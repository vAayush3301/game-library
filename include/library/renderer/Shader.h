#pragma once

#include <string>

namespace gamelib::renderer {
    class Shader {
    public:
        Shader(const std::string &vertexPath, const std::string &fragmentPath);

        ~Shader();

        void Bind() const;

        void Unbind() const;

    private:
        unsigned int m_RendererID;
    };
}
