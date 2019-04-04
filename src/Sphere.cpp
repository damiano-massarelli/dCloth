#include "Sphere.h"
#include <SDL2_gfxPrimitives.h>

Sphere::Sphere(const Vec3& pcenter, float pradius) : center{pcenter}, radius{pradius}
{

}
void Sphere::handleVertex(Vertex& v)
{
    if (v.pos.distanceTo(center) < radius) {
        Vec3 vel = v.pos - v.oldPos;
        Vec3 newPos = v.pos - center;
        newPos.normalize();

        newPos = center + newPos * radius;
        v.pos = newPos;
        v.oldPos = v.pos - vel * smoothness;
    }
}

void Sphere::render(Display& display)
{
    Vec3 up = Vec3{0, center.y + radius, center.z};
    SDL_Point projCenter = display.camera.project(center);
    int projRadius = display.camera.project(up).y - projCenter.y;


    circleColor(display.renderer, projCenter.x, projCenter.y, projRadius, 0xFF000000);
}
