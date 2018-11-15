#include "IndexBuffer.h"
#include "OpenGL.h"
#include <GL/glew.h>

namespace Allmund::Graphics::OPENGL {

	IndexBuffer::IndexBuffer(unsigned int* data, unsigned int count){
		GLCall(glGenBuffers(1, &buffer_id));
		Bind();
		GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
		Unbind();
	}


	IndexBuffer::~IndexBuffer(){

	}

	void IndexBuffer::Bind() {
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id));
	}

	void IndexBuffer::Unbind() {
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

}