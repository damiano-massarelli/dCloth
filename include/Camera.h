#ifndef CAMERA_H
#define CAMERA_H
#include <SDL.h>
#include "Vec3.h"

class Camera
{
    private:
        float focalLength;
        int windowWidth;
        int windowHeight;

    public:
        Camera(int w, int h, float fl);

        SDL_Point project(const Vec3& pt);

        virtual ~Camera();
};

#endif // CAMERA_H
