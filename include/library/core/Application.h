#pragma once

#include <memory>

namespace gamelib::core {
    class Window;

    class Application {
    public:
        Application();
        ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_running = true;
    };
}