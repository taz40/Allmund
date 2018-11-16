#include "UniformBuffer.h"
#include "OpenGL.h"
#include <GL/glew.h>

namespace Allmund::Graphics::OPENGL {

	UniformBuffer::UniformBuffer(const void* data, unsigned int size){
		GLCall(glGenBuffers(1, &buffer_id));
		Bind();
		GLCall(glBufferData(GL_UNIFORM_BUFFER, size, data, GL_STATIC_DRAW));
		Unbind();
	}


	UniformBuffer::~UniformBuffer(){

	}


	void UniformBuffer::Bind() {
		GLCall(glBindBuffer(GL_UNIFORM_BUFFER, buffer_id));
	}

	void UniformBuffer::Unbind() {
		GLCall(glBindBuffer(GL_UNIFORM_BUFFER, 0));
	}

}