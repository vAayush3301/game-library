#include "library/math/vec4.h"
#include "library/math/mat4.h"
#include <iostream>
#include <cmath>

using namespace gamelib::math;

int main() {
    Vec4 point(1, 0, 0, 1);

    Mat4 scale = Mat4::scale(2, 2, 2);
    Mat4 rot = Mat4::rotationZ(M_PI / 2);
    Mat4 trans = Mat4::translation(3, 0, 0);

    Mat4 model = trans * rot * scale;

    Vec4 result = model * point;

    std::cout << result.x << "\n";
    std::cout << result.y << "\n";
    std::cout << result.z << "\n";
    std::cout << result.w << "\n";

    return 0;
}