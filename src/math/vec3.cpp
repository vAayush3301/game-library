#include "library/math/vec3.h"
#include <cmath>

namespace gamelib::math
{
    Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

    Vec3::Vec3(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

    float Vec3::length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    float Vec3::lengthSquared() const {
        return x * x + y * y + z * z;
    }

    Vec3 Vec3::operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 Vec3::operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 Vec3::operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    Vec3 Vec3::normalized() const {
        float len = lengthSquared();

        if (len == 0.0f) {
            return Vec3(0.0f, 0.0f, 0.0f);
        }

        return Vec3(x / len, y / len, z / len);
    }

    float Vec3::dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vec3 Vec3::cross(const Vec3& other) const {
        return Vec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }
}