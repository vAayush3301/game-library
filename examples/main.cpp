#include "library/core/Application.h"

int main() {
    gamelib::core::ApplicationSpecification spec;
    spec.Name = "Window";
    spec.Width = 1000;
    spec.Height = 800;

    gamelib::core::Application app(spec);
    app.Run();
}
