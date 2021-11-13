//
// Augments
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include <functional>
#include <curl/curl.h>

class HttpRequest {
public:
    typedef std::function<void(long, const std::string&)> Callback;

    HttpRequest();
    HttpRequest(const HttpRequest&) = delete;
    HttpRequest(HttpRequest&& other) noexcept;
    ~HttpRequest();

    HttpRequest& operator=(const HttpRequest&) = delete;
    HttpRequest& operator=(HttpRequest&& other) noexcept;

    long get_response_code() const;

    void set_body(const std::string& body) const;
    void set_callback(Callback callback);
    void set_header_id(uint64_t id);
    void set_header_token(const std::string& token);
    void set_uri(const std::string& uri) const;

    HttpRequest& with_body(const std::string& body);
    HttpRequest& with_callback(Callback callback);
    HttpRequest& with_header_id(uint64_t id);
    HttpRequest& with_header_token(const std::string& token);
    HttpRequest& with_uri(const std::string& uri);

private:
    CURL* handle = nullptr;
    curl_slist* headers = nullptr;
    std::unique_ptr<std::string> response;
    Callback callback = [](auto, auto) {};

    friend class HttpContainer;
};
