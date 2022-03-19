//
// Augments
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include <queue>
#include "http_request.h"

class HttpContainer {
public:
    HttpContainer();
    ~HttpContainer();

    void update();
    HttpRequest& push_request();

private:
    CURLM* multi_handle = nullptr;
    std::queue<HttpRequest> requests;
};
