#pragma once
#include <GL/glew.h>
#include "../Core.h"
#include <string>

#define ASSERT(x) if (!(x)) __debugbreak();

#define GLCall(x) Graphics::OPENGL::GLClearError();\
	x;\
	ASSERT(Graphics::OPENGL::GLLogCall(#x, __FILE__, __LINE__))

namespace Allmund::Graphics::OPENGL {
	
	void ALLMUND_API GLClearError();

	std::string ALLMUND_API GLGetErrorString(GLenum error);

	bool ALLMUND_API GLLogCall(const char* function, const char* file, int line);

}