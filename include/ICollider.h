#ifndef ICOLLIDER_H
#define ICOLLIDER_H

class Vertex;

class ICollider
{
    public:
        ICollider() {}
        virtual ~ICollider() {}

        virtual void handleVertex(Vertex& v) = 0;
};

#endif // ICOLLIDER_H
