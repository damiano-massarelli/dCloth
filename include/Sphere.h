#ifndef SPHERE_H
#define SPHERE_H
#include "Vec3.h"
#include "Cloth.h"
#include "Display.h"
#include "ICollider.h"

class Sphere : public ICollider
{
    public:
        Vec3 center;
        float radius = 0;
        float smoothness = 0.98f;

        Sphere(const Vec3& pcenter, float pradius);

        virtual void handleVertex(Vertex& v) override;

        void render(Display& display);
};

#endif // SPHERE_H
