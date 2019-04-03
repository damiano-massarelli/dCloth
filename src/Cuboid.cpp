#include "Cuboid.h"
#include <cmath>

Cuboid::Cuboid(const Vec3& pcenter, float w, float h, float d) : center{pcenter}, width{w}, height{h}, depth{d}
{

}

void Cuboid::handleCollision(Cloth& cloth) const
{
    for (auto& v : cloth.getVertices()) {
        auto dist = v.pos - center;
        if (std::abs(dist.x) < width / 2 && std::abs(dist.y) < height / 2 && std::abs(dist.z) < depth / 2)
            v.pos = v.oldPos;
    }
}

void Cuboid::render(Display& display)
{

}
