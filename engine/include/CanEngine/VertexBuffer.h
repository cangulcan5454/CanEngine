#pragma once

namespace CanEngine{

    class VertexBuffer{
        public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();
        void Bind();
        void UnBind();
        private:
        unsigned int VBO;
    };
}