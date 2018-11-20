#include "VertexBuffer.h"
#include "../Log.h"
#include "OpenGL.h"
#include <GL/glew.h>
#include <stddef.h>

namespace Allmund::Graphics::OPENGL {

	VertexBuffer::VertexBuffer(Vertex* data, unsigned int count)
	{
		GLCall(glGenBuffers(1, &buffer_id));
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer_id));
		GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * count, data, GL_STATIC_DRAW));

		GLCall(glGenVertexArrays(1, &vertex_array_id));
		GLCall(glBindVertexArray(vertex_array_id));

		GLCall(glEnableVertexAttribArray(0));
		GLCall(glEnableVertexAttribArray(1));
		GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0));
		GLCall(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 3)));
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
		GLCall(glBindVertexArray(0));
	}


	VertexBuffer::~VertexBuffer()
	{
		//glDeleteBuffer(buffer_id);
	}

	void VertexBuffer::Bind() {
		GLCall(glBindVertexArray(vertex_array_id));
	}

	void VertexBuffer::Unbind() {
		GLCall(glBindVertexArray(0));
	}

}