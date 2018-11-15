#include "UniformBuffer.h"
#include "OpenGL.h"
#include <GL/glew.h>

namespace Allmund::Graphics::OPENGL {

	UniformBuffer::UniformBuffer(){
		GLCall(glGenBuffers(1, &buffer_id));
		
	}


	UniformBuffer::~UniformBuffer(){

	}


	void UniformBuffer::Bind() {
		
	}

	void UniformBuffer::Unbind() {
		
	}

}