#include "library/camera/Camera.h"
#include <cmath>

using namespace gamelib;

math::Mat4 camera::Camera::getViewMatrix() const {

    math::Mat4 Rx = math::Mat4::rotationX(-rotation.x);
    math::Mat4 Ry = math::Mat4::rotationY(-rotation.y);
    math::Mat4 Rz = math::Mat4::rotationZ(-rotation.z);

    math::Mat4 R = Rx * Ry * Rz;

    math::Mat4 T = math::Mat4::translation(
        -position.x,
        -position.y,
        -position.z
    );

    return R * T;
}

math::Mat4 camera::Camera::getProjectionMatrix() const {

    math::Mat4 result{};

    float tanHalf = std::tan(fov / 2.0f);

    result.m[0][0] = 1.0f / (aspect * tanHalf);
    result.m[1][1] = 1.0f / tanHalf;
    result.m[2][2] = -(farPlane + nearPlane) / (farPlane - nearPlane);
    result.m[2][3] = -(2.0f * farPlane * nearPlane) / (farPlane - nearPlane);
    result.m[3][2] = -1.0f;

    return result;
}