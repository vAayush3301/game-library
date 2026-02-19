#pragma once

namespace gamelib::math {
    struct Vec4 {
        float x, y, z, w;

        Vec4();
        Vec4(float x, float y, float z, float w);

        float dot(const Vec4& other) const;
    };
}