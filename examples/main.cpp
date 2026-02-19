#include <iostream>
#include "library/math/vec4.h"
#include "library/math/transform.h"
#include "library/camera/Camera.h"

using namespace gamelib::math;
using namespace gamelib::camera;

int main() {

    Camera cam;
    cam.position = {0, 0, 0};
    cam.aspect = 16.0f / 9.0f;
    cam.fov = 3.14159f / 3.0f;   // 60 degrees
    cam.nearPlane = 0.1f;
    cam.farPlane = 100.0f;

    Transform t;

    Vec4 point(1, 0, 0, 1);  // object-space point

    // ---- Case 1: Near object ----
    t.position = {0, 0, -2};  // closer
    Mat4 MVP1 = cam.getProjectionMatrix() *
                cam.getViewMatrix() *
                t.getModelMatrix();

    Vec4 clip1 = MVP1 * point;

    clip1.x /= clip1.w;
    clip1.y /= clip1.w;
    clip1.z /= clip1.w;

    std::cout << "Near NDC: ("
              << clip1.x << ", "
              << clip1.y << ", "
              << clip1.z << ")\n";

    // ---- Case 2: Far object ----
    t.position = {0, 0, -10};  // farther
    Mat4 MVP2 = cam.getProjectionMatrix() *
                cam.getViewMatrix() *
                t.getModelMatrix();

    Vec4 clip2 = MVP2 * point;

    clip2.x /= clip2.w;
    clip2.y /= clip2.w;
    clip2.z /= clip2.w;

    std::cout << "Far NDC: ("
              << clip2.x << ", "
              << clip2.y << ", "
              << clip2.z << ")\n";

    return 0;
}