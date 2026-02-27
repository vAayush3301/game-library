#pragma once

#include <string>

namespace gamelib::core {
    class Window {
    public:
        Window(unsigned int width, unsigned int height, const std::string& title);
        ~Window();

        void OnUpdate();
        bool ShouldClose() const;

    private:
        void Init();
        void Shutdown();

        unsigned int m_width;
        unsigned int m_height;
        std::string m_Title;

        void* m_NativeWindow = nullptr;
    };
}