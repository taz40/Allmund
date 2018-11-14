#include "IndexBuffer.h"
#include <GL/glew.h>

namespace Allmund::Graphics::OPENGL {

	IndexBuffer::IndexBuffer(unsigned int* data, unsigned int count){
		glGenBuffers(1, &buffer_id);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
		Unbind();
	}


	IndexBuffer::~IndexBuffer(){

	}

	void IndexBuffer::Bind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id);
	}

	void IndexBuffer::Unbind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}