#include "library/math/vec2.h"
#include <cmath>

namespace gamelib::math
{
    Vec2::Vec2() : x(0.0f), y(0.0f) {}

    Vec2::Vec2(float xVal, float yVal) : x(xVal), y(yVal) {}

    float Vec2::length() const {
        return std::sqrt(x * x + y * y);
    }

    float Vec2::lengthSquared() const {
        return x * x + y * y;
    }

    Vec2 Vec2::operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 Vec2::operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 Vec2::operator*(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 Vec2::normalized() const {
        float len = lengthSquared();

        if (len == 0.0f) {
            return Vec2(0.0f, 0.0f);
        }

        return Vec2(x / len, y / len);
    }

    float Vec2::dot(const Vec2& other) const {
        return x * other.x + y * other.y;
    }
}