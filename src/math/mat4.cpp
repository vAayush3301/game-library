#include "library/math/mat4.h"

namespace gamelib::math {
    Mat4 Mat4::identity() {
        Mat4 result{};

        for (int i = 0; i < 4; i++) {
            result.m[i][i] = 1.0f;
        }

        return result;
    }

    Mat4 Mat4::translation(float x, float y, float z) {
        Mat4 result = identity();

        result.m[0][3] = x;
        result.m[1][3] = y;
        result.m[2][3] = z;

        return result;
    }

    Mat4 Mat4::scale(float x, float y, float z) {
        Mat4 result{};

        result.m[0][0] = x;
        result.m[1][1] = y;
        result.m[2][2] = z;
        result.m[3][3] = 1.0f;

        return result;
    }

    Vec4 Mat4::operator*(const Vec4& v) const {
        Vec4 result;

        result.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w;
        result.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w;
        result.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w;
        result.w = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w;

        return result;
    }

    Mat4 Mat4::operator*(const Mat4& other) const {
        Mat4 result{};

        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                for (int k = 0; k < 4; ++k) {
                    result.m[row][col] += m[row][k] * other.m[k][col];
                }
            }
        }

        return result;
    }
}