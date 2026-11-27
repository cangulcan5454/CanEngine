#pragma once
#include <CanEngine/VertexBuffer.h>
#include <CanEngine/VertexArray.h>
#include <CanEngine/IndexBuffer.h>

namespace CanEngine{
    class Renderer{
        public:
        Renderer();
        bool Initialize();
        void Render();
        void Shutdown();
        private:
            unsigned int shaderProgram = 0;
            struct Vertex
            {
                float position[3];
            };

            Vertex vertices[3] ={
                {{0.0f,0.5f,0.0f}},
                {{-0.5f,-0.5f,0.0f}},
                {{0.5f,-0.5f,0.0f}}
            };

            unsigned int indices[3] = {0, 1, 2};


            VertexArray vertexArray;
            VertexBuffer vertexBuffer;
            IndexBuffer indexBuffer;
    };
}