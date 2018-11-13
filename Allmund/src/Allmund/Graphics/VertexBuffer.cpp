#include "VertexBuffer.h"
#include "../Log.h"
#include <GL/glew.h>
#include <stddef.h>

namespace Allmund::Graphics::OPENGL {

	VertexBuffer::VertexBuffer(Vertex* data, unsigned int count)
	{
		glGenBuffers(1, &buffer_id);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * count, data, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
		Unbind();
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