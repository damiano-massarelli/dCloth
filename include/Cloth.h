#ifndef CLOTH_H
#define CLOTH_H
#include "Vec3.h"
#include <SDL.h>
#include <vector>
#include <functional>
#include "Display.h"

struct Vertex {
    Vec3 pos;
    Vec3 oldPos;
    bool fixed = false;
};

struct Stick {
    int v1;
    int v2;
    float len;
};

class Cloth
{
    std::vector<Vertex> vertices;
    std::vector<Stick> sticks;

    friend class Sphere;

    public:
        /** how the cloth responds to stretching
          * a value of 1 means it is completely stiff, a value of 0 means that the
          * cloth can deform indefinitely. Too high values can lead to instability */
        float stiffness = 0.09f;

        /** The mass of each particle composing the cloth. Too high values can lead
          * to instability */
        float mass = 0.1f;

        Cloth(const Vec3& center, int width, int depth, float space, std::function<bool(int, int)> fixedIf = nullptr);

        void render(Display& display);

        void update(Display& display);

        virtual ~Cloth();
};

#endif // CLOTH_H
