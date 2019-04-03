#ifndef DISPLAY_H
#define DISPLAY_H
#include <SDL.h>
#include <string>
#include "Camera.h"

class Display
{
    public:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        Camera camera;

        int width, height;

        Display(int w, int h, const std::string& title = "");
        virtual ~Display();
};

#endif // DISPLAY_H
