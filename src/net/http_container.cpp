//
// Augments
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#include <string>
#include "http_container.h"
#include "error.h"

HttpContainer::HttpContainer()
{
    multi_handle = curl_multi_init();
    if (!multi_handle)
        throw Error("Failed to create cURL multi handle!");
}

HttpContainer::~HttpContainer()
{
    curl_multi_cleanup(multi_handle);
}

void HttpContainer::update()
{
    int still_running;
    curl_multi_perform(multi_handle, &still_running);

    int messages_left;
    CURLMsg* message = curl_multi_info_read(multi_handle, &messages_left);

    if (message && message->msg == CURLMSG_DONE) {
        // Make sure it's the correct handle
        HttpRequest& request = requests.front();
        if (message->easy_handle != request.handle)
            throw Error("HTTP requests are out of order!");

        // Copy the request info because it's going to be deleted
        long code = request.get_response_code();
        if (code != 200)
            throw Error("Server returned code " + std::to_string(code) + ".");

        std::string response = *request.response;
        auto callback = request.callback;

        // Remove the handle from the queue
        curl_multi_remove_handle(multi_handle, requests.front().handle);
        requests.pop();

        // Add the next handle (if there is one)
        if (!requests.empty())
            curl_multi_add_handle(multi_handle, requests.front().handle);

        // Do the callback
        callback(code, response);
    }
}

HttpRequest& HttpContainer::push_request()
{
    HttpRequest request;

    if (requests.empty())
        curl_multi_add_handle(multi_handle, request.handle);
    requests.push(std::move(request));

    return requests.back();
}
