#pragma once

namespace CanEngine{
    class VertexArray{
        public:
            VertexArray();
            ~VertexArray();
            void Bind();
            void UnBind();
            void SetAttribute(
            unsigned int index,
            unsigned int size,
            unsigned int type, 
            bool normalized,
            unsigned int stride,
            const void* offset);
        private:
            unsigned int VAO;
    };
}