//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include <iomanip>
#include <sstream>
#include "login_scene.h"
#include "error.h"
#include "menu_scene.h"

LoginScene::LoginScene(Game& game)
    : Scene(game)
{
    widgets.add<Label>()
        .with_color({ 255, 255, 255 })
        .with_position({ 16, Renderer::size.y - 32 })
        .with_string("Loading...");

    uint32_t size = 0;
    uint8_t tmp[1024] = { 0 };
    ticket_handle = SteamUser()->GetAuthSessionTicket(tmp, 1024, &size);
    if (ticket_handle == k_HAuthTicketInvalid)
        throw Error("Failed to contact Steam.");

    std::stringstream ss;
    ss << std::hex;
    for (uint32_t i = 0; i < size; i++)
        ss << std::setw(2) << std::setfill('0') << (int)tmp[i];
    hex_ticket = ss.str();
}

void LoginScene::draw() const
{
    widgets.draw();
}

void LoginScene::steam_callback(GetAuthSessionTicketResponse_t* result)
{
    if (result->m_eResult != k_EResultOK) {
        SteamUser()->CancelAuthTicket(ticket_handle);
        throw Error("Steam authentication returned an invalid result.");
    }

    uint64_t steam_id = SteamUser()->GetSteamID().ConvertToUint64();
    auto callback = std::bind_front(&LoginScene::login_callback, this);
    const nlohmann::json json({ { "ticket", hex_ticket },{ "steam_id", steam_id } });

    game.api.push_request()
        .with_body(json.dump())
        .with_callback(callback)
        .with_uri("login");
}

void LoginScene::login_callback(long code, const std::string& response)
{
    SteamUser()->CancelAuthTicket(ticket_handle);

    if (code != 200)
        throw Error("Login error! Code = " + std::to_string(code) + ".");

    const nlohmann::json json = nlohmann::json::parse(response, nullptr, false);
    if (json.is_discarded())
        throw Error("Failed to parse login response!");

    game.cache.init(json);

    // Basic check...
    if (game.cache.user.steam_id != SteamUser()->GetSteamID().ConvertToUint64())
        throw Error("Client Steam ID does not match server!");

    game.set_scene(std::make_unique<MenuScene>(game));
}
