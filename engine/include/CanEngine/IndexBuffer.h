#pragma once

namespace CanEngine{
    class IndexBuffer{
        private:
            unsigned int EBO = 0;
            unsigned int count = 0;
        public:
            IndexBuffer(const void* data, unsigned int count);
            ~IndexBuffer();
            void Bind();
            void UnBind();
            unsigned int GetCount() const;
    };
    
    
}
