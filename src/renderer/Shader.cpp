#include "library/renderer/Shader.h"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

namespace gamelib::renderer {
    static std::string ReadFile(const std::string &path) {
        std::ifstream file(path);
        std::stringstream ss;
        ss << file.rdbuf();
        return ss.str();
    }

    static unsigned int CompileShader(unsigned int type, const std::string &source) {
        unsigned int id = glCreateShader(type);
        const char *src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);

        if (!result) {
            char message[512];
            glGetShaderInfoLog(id, 512, nullptr, message);
            std::cout << "Shader compilation failed: " << message << std::endl;
        }

        return id;
    }

    Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath) {
        std::string vertexSrc = ReadFile(vertexPath);
        std::string fragmentSrc = ReadFile(fragmentPath);

        unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexSrc);
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

        m_RendererID = glCreateProgram();
        glAttachShader(m_RendererID, vs);
        glAttachShader(m_RendererID, fs);
        glLinkProgram(m_RendererID);
        glValidateProgram(m_RendererID);

        glDeleteShader(vs);
        glDeleteShader(fs);
    }

    Shader::~Shader() {
        glDeleteProgram(m_RendererID);
    }

    void Shader::Bind() const {
        glUseProgram(m_RendererID);
    }

    void Shader::Unbind() const {
        glUseProgram(0);
    }
}
