#pragma once
#include <GL/glew.h>
#include "../Core.h"
#include "../Log.h"

namespace Allmund::Graphics::OPENGL {
	
	void ALLMUND_API GLClearError() {
		while (glGetError() != GL_NO_ERROR);
	}

	std::string ALLMUND_API GLGetErrorString(GLenum error) {
		switch (error) {
		case GL_INVALID_ENUM:
			return "Invalid Enum";
		case GL_INVALID_VALUE:
			return "Invalid Value";
		case GL_INVALID_OPERATION:
			return "Invalid Operation";
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			return "Invalid Framebuffer Opearation";
		case GL_OUT_OF_MEMORY:
			return "Out of Memory";
		case GL_STACK_UNDERFLOW:
			return "Stack Underflow";
		case GL_STACK_OVERFLOW:
			return "Stack Overflow";
		default:
			return "Unknown Error";
		}
	}

	void ALLMUND_API GLLogCall() {
		while (GLenum error = glGetError()) {
			AM_CORE_ERROR("OpenGL Error: ({0})", GLGetErrorString(error));
		}
	}

}