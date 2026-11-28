#include <CanEngine/Renderer.h>
#include <glad/gl.h>
#include <cstddef>


namespace CanEngine{

    Renderer::Renderer()
        : vertexBuffer(vertices, sizeof(vertices)),
        indexBuffer(indices, sizeof(indices) / sizeof(indices[0])),
        shader("assets/shaders/Basic.vert", "assets/shaders/Basic.frag")
    {
    }

    bool Renderer::Initialize(){
        vertexArray.SetAttribute(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        if (!shader.Initialize())
        {
            return false;
        }

        return true;
    }

    void Renderer::Render(){
            shader.Use();
            vertexArray.Bind();
            glDrawElements(
                GL_TRIANGLES,
                indexBuffer.GetCount(),
                GL_UNSIGNED_INT,
                nullptr
            );
    }
    void Renderer::Shutdown(){
        shader.Shutdown();
    }
}