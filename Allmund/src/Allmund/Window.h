#pragma once
#include "Core.h"

class GLFWwindow;

namespace Allmund {

	class ALLMUND_API Window
	{
	private:
		GLFWwindow* window;
	public:
		Window(int width, int height, const char * title);
		~Window();

		void Update();
		bool IsClosing();
	};

}