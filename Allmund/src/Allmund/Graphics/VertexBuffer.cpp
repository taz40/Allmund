#include "VertexBuffer.h"
#include <GL/glew.h>

namespace Allmund::Graphics {

	VertexBuffer::VertexBuffer(float data[])
	{
		glGenBuffers(1, &buffer_id);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	}


	VertexBuffer::~VertexBuffer()
	{
		//glDeleteBuffer(buffer_id);
	}

	void VertexBuffer::Bind() {
		glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
	}

	void VertexBuffer::Unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}