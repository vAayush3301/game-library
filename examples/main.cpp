#include "library/math/vec2.h"
#include <iostream>

int main() {
    gamelib::math::Vec2 a(3.0f, 4.0f);
    gamelib::math::Vec2 b(1.0f, 2.0f);

    gamelib::math::Vec2 c = a + b;

    std::cout << a.length() << "\n";
    std::cout << b.length() << "\n";
    std::cout << b.dot(a) << "\n";
    std::cout << b.lengthSquared() << "\n";
    std::cout << a.lengthSquared() << "\n";

    std::cout << c.normalized().length();
    return 0;
}