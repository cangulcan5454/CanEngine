#include <CanEngine/VertexArray.h>
#include <glad/gl.h>

namespace CanEngine{
    VertexArray::VertexArray(){
        glGenVertexArrays(1, &VAO);
        Bind();
    }
    VertexArray::~VertexArray(){
        glDeleteVertexArrays(1, &VAO);
    }
    void VertexArray::Bind(){
        glBindVertexArray(VAO);
    }
    void VertexArray::UnBind(){
        glBindVertexArray(0);
    }
    void VertexArray::SetAttribute(
    unsigned int index,
    unsigned int size,
    unsigned int type, 
    bool normalized,
    unsigned int stride,
    const void* offset)
    {
        Bind();

        glVertexAttribPointer(
            index,
            size,
            type,
            normalized,
            stride,
            offset
        );
        
        glEnableVertexAttribArray(index);
            
    }
}