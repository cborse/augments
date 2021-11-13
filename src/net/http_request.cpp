//
// Augments
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include <string>
#include "http_request.h"
#include "error.h"

static size_t write_chunk(const char* in, size_t size, size_t num, std::string* out)
{
    const size_t total_bytes = size * num;
    out->append(in, total_bytes);
    return total_bytes;
}

HttpRequest::HttpRequest()
{
    handle = curl_easy_init();
    if (!handle)
        throw Error("Failed to create server request!");

    response = std::make_unique<std::string>();

    // Response
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, response.get());
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_chunk);

    // headers
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charset: utf-8");
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);

    // Timeout 5 seconds
    curl_easy_setopt(handle, CURLOPT_TIMEOUT, 5);
}

HttpRequest::HttpRequest(HttpRequest&& other) noexcept
{
    handle = other.handle;
    headers = other.headers;
    response = std::move(other.response);
    callback = other.callback;

    other.handle = nullptr;
    other.headers = nullptr;
    other.response = nullptr;
    other.callback = nullptr;
}

HttpRequest::~HttpRequest()
{
    curl_slist_free_all(headers);
    curl_easy_cleanup(handle);
}

HttpRequest& HttpRequest::operator=(HttpRequest&& other) noexcept
{
    if (handle != other.handle) {
        curl_slist_free_all(headers);
        curl_easy_cleanup(handle);

        handle = other.handle;
        headers = other.headers;
        response = std::move(other.response);
        callback = other.callback;
    }

    other.handle = nullptr;
    other.headers = nullptr;
    other.response = nullptr;
    other.callback = nullptr;

    return *this;
}

long HttpRequest::get_response_code() const
{
    long code = 0;
    curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &code);
    return code;
}

void HttpRequest::set_body(const std::string& body) const
{
    curl_easy_setopt(handle, CURLOPT_COPYPOSTFIELDS, body.c_str());
}

void HttpRequest::set_callback(Callback callback)
{
    this->callback = callback;
}

void HttpRequest::set_header_id(uint64_t id)
{
    std::string s = "X-Aug-ID: " + std::to_string(id);
    headers = curl_slist_append(headers, s.c_str());
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);
}

void HttpRequest::set_header_token(const std::string& token)
{
    std::string s = "X-Aug-Token: " + token;
    headers = curl_slist_append(headers, s.c_str());
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);
}

void HttpRequest::set_uri(const std::string& uri) const
{
    curl_easy_setopt(handle, CURLOPT_URL, std::string("127.0.0.1:8080/" + uri).c_str());
}

HttpRequest& HttpRequest::with_body(const std::string& body)
{
    set_body(body);
    return *this;
}

HttpRequest& HttpRequest::with_callback(Callback callback)
{
    set_callback(callback);
    return *this;
}

HttpRequest& HttpRequest::with_header_id(uint64_t id)
{
    set_header_id(id);
    return *this;
}

HttpRequest& HttpRequest::with_header_token(const std::string& token)
{
    set_header_token(token);
    return *this;
}

HttpRequest& HttpRequest::with_uri(const std::string& uri)
{
    set_uri(uri);
    return *this;
}
