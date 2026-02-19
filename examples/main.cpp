#include "library/math/vec4.h"
#include "library/math/mat4.h"
#include <iostream>

int main() {
    gamelib::math::Vec4 point(1, 2, 3, 1);

    gamelib::math::Mat4 t = gamelib::math::Mat4::translation(5, 0, 0);

    gamelib::math::Vec4 moved = t * point;

    std::cout << moved.x << "\n";
    std::cout << moved.y << "\n";
    std::cout << moved.z << "\n";
    std::cout << moved.w << "\n";

    return 0;
}