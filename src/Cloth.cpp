#include "Cloth.h"
#include <SDL2_gfxPrimitives.h>

Cloth::Cloth(const Vec3& center, int width, int depth, float space, std::function<bool(int, int)> fixedIf)
{
    for (int w = 0; w < width; w++) {
        for (int d = 0; d < depth; d++) {
            Vec3 pos{center.x - width * space/2 + w * space, center.y, center.z - depth * space / 2 + d * space};

            Vertex v{pos, pos};
            v.fixed = fixedIf && fixedIf(w, d);

            vertices.push_back(v);
        }
    }

    for (int w = 0; w < width; w++) {
        for (int d = 0; d < depth; d++) {
            int current = w * depth + d;
            int right = current + 1;
            int down = (w + 1) * depth + d;
            if (w != width - 1)
                sticks.push_back(Stick{ current, down, vertices[current].pos.distanceTo(vertices[down].pos) });
            if (d != depth - 1)
                sticks.push_back(Stick{ current, right, vertices[current].pos.distanceTo(vertices[right].pos) });
        }
    }
}

void Cloth::render(Display& display)
{
    for (const auto& st : sticks) {
        SDL_Point v1 = display.camera.project(vertices[st.v1].pos);
        SDL_Point v2 = display.camera.project(vertices[st.v2].pos);

        lineColor(display.renderer, v1.x, v1.y, v2.x, v2.y, 0xFF00CC00);
    }
}

void Cloth::update(Display& display)
{
    for (auto& v : vertices) {
        if (v.fixed) continue;
        Vec3 vel = v.pos - v.oldPos;

        v.oldPos = v.pos;
        v.pos = v.pos + vel * 0.98;
        v.pos.y += mass;
    }

    for (int i = 0; i < precision; ++i) {
        for (auto& st : sticks) {
            Vertex& v1 = vertices[st.v1];
            Vertex& v2 = vertices[st.v2];
            float len = v1.pos.distanceTo(v2.pos);
            Vec3 offset = v1.pos - v2.pos;
            float percent = (len - st.len) / (st.len);
            Vec3 setBack = (offset * percent) * stiffness;
            if (percent < 0) continue;

            if (!v1.fixed)
                v1.pos = v1.pos - setBack;

            if (!v2.fixed) {
                v2.pos = v2.pos + setBack;

            }
        }
        for (auto collider : colliders) {
            for (auto& v : vertices) {
                collider->handleVertex(v);
            }
        }
    }
    for (auto& v : vertices) {
        Vec3 vel = v.pos - v.oldPos;

        if (v.pos.y > display.height / 2) {
            v.pos.y = display.height / 2;
            v.oldPos.y = v.pos.y + vel.y * 0.05f;
        }
    }
}

void Cloth::addCollider(ICollider* collider)
{
    colliders.push_back(collider);
}

std::vector<Vertex>& Cloth::getVertices()
{
    return vertices;
}

Cloth::~Cloth()
{

}
