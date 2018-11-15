#include "VertexBuffer.h"
#include "../Log.h"
#include "OpenGL.h"
#include <GL/glew.h>
#include <stddef.h>

namespace Allmund::Graphics::OPENGL {

	VertexBuffer::VertexBuffer(Vertex* data, unsigned int count)
	{
		GLCall(glGenBuffers(1, &buffer_id));
		Bind();
		GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * count, data, GL_STATIC_DRAW));

		GLCall(glEnableVertexAttribArray(0));
		GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));
		Unbind();
	}


	VertexBuffer::~VertexBuffer()
	{
		//glDeleteBuffer(buffer_id);
	}

	void VertexBuffer::Bind() {
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer_id));
	}

	void VertexBuffer::Unbind() {
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

}