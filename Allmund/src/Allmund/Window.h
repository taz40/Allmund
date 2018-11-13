#pragma once
#include "Core.h"
#include "Graphics/Shader.h"

class GLFWwindow;

namespace Allmund {

	class ALLMUND_API Window
	{
	private:
		GLFWwindow* window;
		Graphics::OPENGL::Shader* shader;
	public:
		Window(int width, int height, const char * title);
		~Window();

		void Update();
		bool IsClosing();
	};

}