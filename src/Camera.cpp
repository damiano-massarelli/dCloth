#include "Camera.h"

Camera::Camera(int w, int h, float fl) : windowWidth{w}, windowHeight{h}, focalLength{fl}
{

}

SDL_Point Camera::project(const Vec3& pt)
{
    float perp = (focalLength) / (focalLength + pt.z);
    return SDL_Point{pt.x * perp + windowWidth / 2, pt.y * perp + windowHeight / 2};
}

Camera::~Camera()
{

}
