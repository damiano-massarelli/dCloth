#include "Cuboid.h"
#include <SDL2_gfxPrimitives.h>
#include <cmath>

Cuboid::Cuboid(const Vec3& pcenter, float w, float h, float d) : center{pcenter}, width{w}, height{h}, depth{d}
{

}

void Cuboid::handleVertex(Vertex& v)
{
    auto dist = v.pos - center;
    auto oldDist = v.oldPos - center;
    auto vel = v.pos - v.oldPos;
    if (std::abs(dist.x) < width / 2 && std::abs(dist.y) < height / 2 && std::abs(dist.z) < depth / 2) {
        if (! std::abs(oldDist.x) <= width / 2)
            v.pos.x = v.oldPos.x;

        if (! std::abs(oldDist.y) <= height / 2)
            v.pos.y = v.oldPos.y;

        if (! std::abs(oldDist.z) <= depth / 2)
            v.pos.z = v.oldPos.z;
    }
}

void Cuboid::render(Display& display)
{
    auto tl = display.camera.project(center + Vec3{-width / 2, -height / 2, - depth / 2});
    auto tr = display.camera.project(center + Vec3{width / 2, -height / 2, - depth / 2});

    auto tl1 = display.camera.project(center + Vec3{-width / 2, -height / 2, depth / 2});
    auto tr1 = display.camera.project(center + Vec3{width / 2, -height / 2, depth / 2});

    auto bl = display.camera.project(center + Vec3{-width / 2, height / 2, - depth / 2});
    auto br = display.camera.project(center + Vec3{width / 2, height / 2, - depth / 2});

    auto bl1 = display.camera.project(center + Vec3{-width / 2, height / 2, depth / 2});
    auto br1 = display.camera.project(center + Vec3{width / 2, height / 2, depth / 2});

    lineColor(display.renderer, tl.x, tl.y, tr.x, tr.y, 0xff000000);
    lineColor(display.renderer, tl.x, tl.y, tl1.x, tl1.y, 0xff000000);
    lineColor(display.renderer, tr.x, tr.y, tr1.x, tr1.y, 0xff000000);
    lineColor(display.renderer, tl1.x, tl1.y, tr1.x, tr1.y, 0xff000000);

    lineColor(display.renderer, bl.x, bl.y, br.x, br.y, 0xff000000);
    lineColor(display.renderer, bl.x, bl.y, bl1.x, bl1.y, 0xff000000);
    lineColor(display.renderer, br.x, br.y, br1.x, br1.y, 0xff000000);
    lineColor(display.renderer, bl1.x, bl1.y, br1.x, br1.y, 0xff000000);

    lineColor(display.renderer, tl.x, tl.y, bl.x, bl.y, 0xff000000);
    lineColor(display.renderer, tl1.x, tl1.y, bl1.x, bl1.y, 0xff000000);
    lineColor(display.renderer, tr.x, tr.y, br.x, br.y, 0xff000000);
    lineColor(display.renderer, tr1.x, tr1.y, br1.x, br1.y, 0xff000000);
}
