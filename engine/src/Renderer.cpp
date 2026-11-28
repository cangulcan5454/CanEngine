#include <CanEngine/Renderer.h>
#include <glad/gl.h>
#include <CanEngine/Log.h>
#include <cstddef>


namespace CanEngine{
    bool Renderer::Initialize(){
        vertexArray.SetAttribute(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        const char* vertexShaderSource = R"(
        #version 330 core

        layout (location = 0) in vec3 aPos;

        void main()
        {
            gl_Position = vec4(aPos, 1.0);
        }
        )";
        const char* fragmentShaderSource = R"(
        #version 330 core

        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(0.6, 0.0, 0.5, 1.0);
        }
        )";

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
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return true;
    }
    
    Renderer::Renderer()
    : vertexBuffer(vertices, sizeof(vertices)),
      indexBuffer(indices, sizeof(indices) / sizeof(indices[0]))
{
}

    void Renderer::Render(){
            glUseProgram(shaderProgram);
            vertexArray.Bind();
            glDrawElements(
                GL_TRIANGLES,
                indexBuffer.GetCount(),
                GL_UNSIGNED_INT,
                nullptr
            );
    }
    void Renderer::Shutdown(){
        glDeleteProgram(shaderProgram);
        shaderProgram = 0;
    }
}