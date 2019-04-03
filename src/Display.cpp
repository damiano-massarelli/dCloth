#include "Display.h"
#include <SDL_image.h>

Display::Display(int w, int h, const std::string& title) : width{w}, height{h}, camera{w, h, 300}
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        SDL_Log("cannot init");
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if (window ==  nullptr)
        SDL_Log("cannot create window");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
        SDL_Log("cannot create renderer");

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
        SDL_Log("cannot init image loader");
}

Display::~Display()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
