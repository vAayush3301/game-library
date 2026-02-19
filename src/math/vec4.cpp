#include "library/math/vec4.h"

namespace gamelib::math {
    Vec4::Vec4() : x(0), y(0), z(0), w(0) {}

    Vec4::Vec4(float xVal, float yVal, float zVal, float wVal) : x(xVal), y(yVal), z(zVal), w(wVal) {}

    float Vec4::dot(const Vec4& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }
}