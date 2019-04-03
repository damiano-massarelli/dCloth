#include <iostream>
#include <SDL.h>
#include "Display.h"
#include "Cloth.h"
#include "Sphere.h"

int main(int argc, char* argv[])
{
    Display display(1280, 720, "coding math");
    bool quit = false;
    SDL_Event e;

    Cloth c{Vec3{0, -400, 300}, 40, 40, 7, [](int w, int d) {return d == 0 && w % 2 == 0;}};
    Sphere s{Vec3{50, -200, 300}, 100};

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;

        }
        SDL_SetRenderDrawColor(display.renderer, 255, 255, 255, 255);
        SDL_RenderClear(display.renderer);

        c.update(display);
        c.render(display);

        s.handleCollision(c);
        s.render(display);

        int x, y;
        SDL_GetMouseState(&x, &y);
        s.center.x = x - display.width / 2;

        SDL_RenderPresent(display.renderer);

    }
    return 0;
}
