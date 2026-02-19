#pragma once
#include "library/math/mat4.h"
#include "library/math/vec3.h"
#include <cmath>

namespace gamelib::camera {
    struct Camera {
        math::Vec3 position {0, 0, 0};
        math::Vec3 rotation {0, 0, 0};

        float fov = 3.14159f / 4.0f;
        float aspect = 16.0f / 9.0f;
        float nearPlane = 0.1f;
        float farPlane = 100.0f;

        math::Mat4 getViewMatrix() const;
        math::Mat4 getProjectionMatrix() const;
    };
}