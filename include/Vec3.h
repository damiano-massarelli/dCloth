#ifndef VEC3_H
#define VEC3_H
#include <ostream>

struct Vec3 {
    float x = 0;
    float y = 0;
    float z = 0;

    Vec3 operator-(const Vec3& v) const;

    Vec3 operator+(const Vec3& v) const;

    float length() const;

    float distanceTo(const Vec3& v) const;

    void normalize();

    Vec3 operator*(float s) const;

    Vec3 operator/(float s) const;
};

std::ostream& operator<<(std::ostream& out, const Vec3& v);

#endif // VEC3_H
