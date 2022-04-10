#pragma once

#include <queue>
#include "http_request.h"

class HttpContainer {
public:
    HttpContainer();
    ~HttpContainer();

    void update();
    HttpRequest& push_request();
    void set_header_id(uint64_t id);
    void set_header_token(const std::string& token);

private:
    CURLM* multi_handle = nullptr;
    std::queue<HttpRequest> requests;
    uint64_t id = 0;
    std::string token;
};
