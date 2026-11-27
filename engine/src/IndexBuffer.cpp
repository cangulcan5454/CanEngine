#include <CanEngine/IndexBuffer.h>
#include <glad/gl.h>

namespace CanEngine{
    IndexBuffer::IndexBuffer(const void* data, unsigned int count){
        glGenBuffers(1, &EBO);
        Bind();
        glBufferData(
            GL_ELEMENT_ARRAY_BUFFER,
            count * sizeof(unsigned int),
            data,
            GL_STATIC_DRAW
        );
        this->count = count;
    }

    IndexBuffer::~IndexBuffer(){
        glDeleteBuffers(1, &EBO);
    }

    void IndexBuffer::Bind(){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    }

    void IndexBuffer::UnBind(){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    unsigned int IndexBuffer::GetCount() const{
        return count;
    }

}