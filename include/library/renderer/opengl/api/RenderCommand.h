#pragma once

#include "library/renderer/RendererAPI.h"
#include <memory>

namespace gamelib::renderer {
    class RenderCommand {
    public:
        static void Init();
        static void SetClearColor(float r, float g, float b, float a);
        static void Clear();

    private:
        static std::unique_ptr<RendererAPI> s_RendererAPI;
    };
}