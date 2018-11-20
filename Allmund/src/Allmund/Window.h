#pragma once
#include "Core.h"
#include "Graphics/Shader.h"
#include "Graphics/Material.h"
#include "Graphics/OpenGLRenderer.h"
#include <chrono>

class GLFWwindow;

namespace Allmund {

	class ALLMUND_API Window
	{
	private:
		GLFWwindow* window;
		Graphics::OPENGL::OpenGLRenderer* rendererGL;
		std::chrono::high_resolution_clock::time_point last;
	public:
		Scene * scene;
		Window(int width, int height, const char * title);
		~Window();

		void Update();
		bool IsClosing();
	};

}