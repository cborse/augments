//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include <steam/steam_api.h>
#include "scene.h"

class LoginScene : public Scene {
public:
    explicit LoginScene(Game& game);

    virtual void resume() override {}
    virtual void handle_event(const SDL_Event& e) override {}
    virtual void update() override {}
    virtual void draw() const override;

private:
    STEAM_CALLBACK(LoginScene, steam_callback, GetAuthSessionTicketResponse_t);
    void login_callback(long code, const std::string& response);
    void get_data_callback(long code, const std::string& response);

    std::string hex_ticket;
    HAuthTicket ticket_handle = k_HAuthTicketInvalid;
};
