#include "Vec3.h"
#include <cmath>

Vec3 Vec3::operator-(const Vec3& v) const
{
    return Vec3{x - v.x, y - v.y, z - v.z};
}

Vec3 Vec3::operator+(const Vec3& v) const
{
    return Vec3{x + v.x, y + v.y, z + v.z};
}

float Vec3::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

float Vec3::distanceTo(const Vec3& v) const
{
    return (*this - v).length();
}

Vec3 Vec3::operator*(float s) const
{
    return Vec3{x * s, y * s, z * s};
}

Vec3 Vec3::operator/(float s) const
{
    return Vec3{x / s, y / s, z / s};
}

void Vec3::normalize()
{
    float len = length();

    x /= len;
    y /= len;
    z /= len;
}

std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

