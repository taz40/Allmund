#pragma once

#include "Core.h"
#include "Window.h"

namespace Allmund {

	class ALLMUND_API Application
	{
	private:
		Window * window;
	public:
		Application(int width, int height, const char * title);
		virtual ~Application();

		void Run();
	};

	//to be defined in client
	Application* CreateApplication();

}