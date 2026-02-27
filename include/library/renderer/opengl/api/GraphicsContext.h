#pragma once

namespace gamelib::renderer {
    class GraphicsContext {
    public:
        virtual ~GraphicsContext() = default;

        virtual void Init();
        virtual void SwapBuffers();
    };
}