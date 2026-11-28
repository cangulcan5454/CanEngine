#include <CanEngine/Shader.h>
#include <CanEngine/Log.h>
#include <glad/gl.h>
#include <fstream>
#include <sstream>

namespace CanEngine{
    Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
        : vertexPath(vertexPath),
        fragmentPath(fragmentPath)
    {
    }

    bool Shader::Initialize(){
        std::ifstream vertexFile(vertexPath);
        if (!vertexFile.is_open())
        {
            Log::Error("Failed to open vertex shader: " + vertexPath);
            return false;
        }
        std::stringstream vertexBuffer;
        vertexBuffer << vertexFile.rdbuf();
        std::string vertexSource = vertexBuffer.str();
        const char* vertexShaderSource = vertexSource.c_str();

        std::ifstream fragmentFile(fragmentPath);
        if (!fragmentFile.is_open())
        {
            Log::Error("Failed to open fragment shader: " + fragmentPath);
            return false;
        }
        std::stringstream fragmentBuffer;
        fragmentBuffer << fragmentFile.rdbuf();
        std::string fragmentSource = fragmentBuffer.str();
        const char* fragmentShaderSource = fragmentSource.c_str();

        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);
        int success;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE)
        {
            char infoLog[512];

            glGetShaderInfoLog(
                vertexShader,
                512,
                nullptr,
                infoLog
            );

            Log::Error(infoLog);
            glDeleteShader(vertexShader);
            return false;
        }

        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE)
        {
            char infoLog[512];

            glGetShaderInfoLog(
                fragmentShader,
                512,
                nullptr,
                infoLog
            );

            Log::Error(infoLog);
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
            return false;
        }

        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (success == GL_FALSE)
        {
            char infoLog[512];

            glGetProgramInfoLog(
                shaderProgram,
                512,
                nullptr,
                infoLog
            );

            Log::Error(infoLog);
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
            glDeleteProgram(shaderProgram);
            shaderProgram = 0;
            return false;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    

        return true;
    }

    void Shader::Use(){
        glUseProgram(shaderProgram);
    }

    void Shader::Shutdown(){
        glDeleteProgram(shaderProgram);
        shaderProgram = 0;
    }
        
}