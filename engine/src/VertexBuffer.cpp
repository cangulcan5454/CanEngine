#include <CanEngine/VertexBuffer.h>
#include <glad/gl.h>

namespace CanEngine{
    VertexBuffer::VertexBuffer(const void* data, unsigned int size){
        glGenBuffers(1, &VBO);
        Bind();
        glBufferData(
            GL_ARRAY_BUFFER,
            size,
            data,
            GL_STATIC_DRAW
        );
    }

    VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1, &VBO);
    }

    void VertexBuffer::Bind(){
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
    }

    void VertexBuffer::UnBind(){
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}