//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include <windows.h>
#include <curl/curl.h>
#include <SDL_image.h>
#include <steam/steam_api.h>
#include "error.h"
#include "game.h"

static void fatal_error(const std::string& msg)
{
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error", msg.c_str(), NULL);
    exit(EXIT_FAILURE);
}

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    if (SteamAPI_RestartAppIfNecessary(1390280))
        fatal_error("Please use the Steam launcher.");

    if (!SteamAPI_Init())
        fatal_error("Failed to initialize the Steam API.");
    atexit(SteamAPI_Shutdown);

    if (curl_global_init(CURL_GLOBAL_DEFAULT) != 0)
        fatal_error("Failed to initialize cURL.");
    atexit(curl_global_cleanup);

    if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_TIMER | SDL_INIT_VIDEO) != 0)
        fatal_error("Failed to initialize SDL: " + std::string(SDL_GetError()) + ".");
    atexit(SDL_Quit);

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
        fatal_error("Failed to initialize SDL_image: " + std::string(IMG_GetError()) + ".");
    atexit(IMG_Quit);

    if (TTF_Init() != 0)
        fatal_error("Failed to initialize SDL_ttf: " + std::string(TTF_GetError()) + ".");
    atexit(TTF_Quit);

    try {
        Game game;
        game.loop();
    }
    catch (const Error& e) {
        fatal_error(std::string(e.what()) + " Please restart the application and try again.");
    }
    catch (const std::exception& e) {
        fatal_error("Error: " + std::string(e.what()) + ". Please restart the application and try again.");
    }

    return EXIT_SUCCESS;
}
