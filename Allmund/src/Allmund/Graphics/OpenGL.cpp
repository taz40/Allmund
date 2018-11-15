#include "OpenGL.h"
#include "../Log.h"

namespace Allmund::Graphics::OPENGL {

	void GLClearError() {
		while (glGetError() != GL_NO_ERROR);
	}

	std::string GLGetErrorString(GLenum error) {
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

	bool GLLogCall(const char* function, const char* file, int line) {
		while (GLenum error = glGetError()) {
			AM_CORE_ERROR("OpenGL Error: ({0}) In Function: {1}, In File: {2}, On Line: {3}", GLGetErrorString(error), function, file, line);
			return false;
		}

		return true;
	}

}