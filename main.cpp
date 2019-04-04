#include <iostream>
#include <SDL.h>
#include "Display.h"
#include "Cloth.h"
#include "Sphere.h"
#include "Cuboid.h"

int main(int argc, char* argv[])
{
    Display display(1280, 720, "coding math");
    bool quit = false;
    SDL_Event e;

    Cloth cloth{Vec3{0, -400, 300}, 50, 50, 7, [](int w, int d) {return false;}};
    cloth.precision = 25;

    Sphere s{Vec3{100, -200, 300}, 100};
    Sphere s2{Vec3{-175, -200, 300}, 50};

    Cuboid c{Vec3{0, -200, 300}, 100, 100, 100};

    cloth.addCollider(&s);
    cloth.addCollider(&s2);
    cloth.addCollider(&c);

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;

        }
        SDL_SetRenderDrawColor(display.renderer, 255, 255, 255, 255);
        SDL_RenderClear(display.renderer);

        cloth.update(display);
        cloth.render(display);

        s.render(display);
        s2.render(display);

        c.render(display);

        int x, y;
        SDL_GetMouseState(&x, &y);
        c.center.x = x - display.width / 2;
        c.center.y = y - display.height / 2;

        SDL_RenderPresent(display.renderer);

    }
    return 0;
}
