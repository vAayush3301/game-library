#pragma once
#include "library/math/vec3.h"
#include "library/math/mat4.h"

namespace gamelib::math {
    struct Transform {
        Vec3 position {0, 0, 0};
        Vec3 rotation {0, 0, 0};
        Vec3 scale {1, 1, 1};

        Mat4 getModelMatrix() const {
            Mat4 T = Mat4::translation(position.x, position.y, position.z);
            Mat4 Rx = Mat4::rotationX(rotation.x);
            Mat4 Ry = Mat4::rotationX(rotation.y);
            Mat4 Rz = Mat4::rotationX(rotation.z);
            Mat4 S = Mat4::scale(scale.x, scale.y, scale.z);

            Mat4 R = Rz * Ry * Rx;

            return T * R * S;
        }
    };
}