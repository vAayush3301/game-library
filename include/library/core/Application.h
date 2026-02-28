#pragma once

#include <memory>
#include <string>

namespace gamelib::core {
    struct ApplicationSpecification {
        std::string Name = "GameLib";
        uint32_t Width = 1280;
        uint32_t Height = 720;
    };

    class Window;

    class Application {
    public:
        Application(const ApplicationSpecification& spec);
        virtual ~Application();

        void Run();

    protected:
        virtual void OnInit() {}
        virtual void OnUpdate(float dt) {}
        virtual void OnShutdown() {}

    private:
        ApplicationSpecification m_Specification;
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
}
