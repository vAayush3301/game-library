#pragma once

namespace gamelib::math
{
    struct Vec3
    {
        float x;
        float y;
        float z;

        Vec3();
        Vec3(float x, float y, float z);

        float length() const;
        float lengthSquared() const;

        Vec3 operator+(const Vec3& other) const;
        Vec3 operator-(const Vec3& other) const;
        Vec3 operator*(float scalar) const;

        Vec3 normalized() const;

        float dot(const Vec3& other) const;

        Vec3 cross(const Vec3& other) const;
    };
}