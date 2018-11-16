#pragma once
#include "Core.h"
#include "Graphics/Shader.h"
#include "Graphics/Material.h"

class GLFWwindow;

namespace Allmund {

	class ALLMUND_API Window
	{
	private:
		GLFWwindow* window;
		Graphics::Material* material;
		Graphics::Material* material2;
		float rotX;
	public:
		Window(int width, int height, const char * title);
		~Window();

		void Update();
		bool IsClosing();
	};

}