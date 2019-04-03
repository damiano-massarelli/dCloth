#ifndef SPHERE_H
#define SPHERE_H
#include "Vec3.h"
#include "Cloth.h"
#include "Display.h"

class Sphere
{
    public:
        Vec3 center;
        float radius = 0;

        Sphere(const Vec3& pcenter, float pradius);

        void handleCollision(Cloth& cloth) const;

        void render(Display& display);
};

#endif // SPHERE_H
