#pragma once

namespace gamelib::math
{
    struct Vec2
    {
        float x;
        float y;

        Vec2();
        Vec2(float x, float y);

        float length() const;
        float lengthSquared() const;

        Vec2 operator+(const Vec2& other) const;
        Vec2 operator-(const Vec2& other) const;
        Vec2 operator*(float scalar) const;

        Vec2 normalized() const;

        float dot(const Vec2& other) const;
    };
}