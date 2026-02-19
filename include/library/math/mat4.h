#pragma once
#include "library/math/vec4.h"

namespace gamelib::math {
    struct Mat4 {
        float m[4][4];

        static Mat4 identity();
        static Mat4 translation(float x, float y, float z);
        static Mat4 scale(float x, float y, float z);
        static Mat4 rotationX(float angleRadians);
        static Mat4 rotationY(float angleRadians);
        static Mat4 rotationZ(float angleRadians);

        Mat4 operator*(const Mat4& other) const;
        Vec4 operator*(const Vec4& v) const;

    };
}