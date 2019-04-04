#ifndef CUBOID_H
#define CUBOID_H
#include "Vec3.h"
#include "Cloth.h"
#include "Display.h"
#include "ICollider.h"

class Cuboid : public ICollider
{
    public:
        Vec3 center;
        float width = 0;
        float height = 0;
        float depth = 0;

        Cuboid(const Vec3& pcenter, float w = 10, float h = 10, float d = 10);

        virtual void handleVertex(Vertex& v) override;

        void render(Display& display);
};

#endif // CUBOID_H
