#pragma once

#include <string>

#include "library/math/transform.h"

namespace gamelib::renderer {
    class Shader {
    public:
        Shader(const std::string &vertexPath, const std::string &fragmentPath);

        ~Shader();

        void Bind() const;

        void Unbind() const;

        void SetMat4(const std::string &name, const float *value);

    private:
        unsigned int m_RendererID;
    };
}