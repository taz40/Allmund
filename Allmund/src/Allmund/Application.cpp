#include "Application.h"
#include "Log.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Allmund {

	Application::Application(int width, int height, const char * title)
	{
		window = new Window(width, height, title);
	}


	Application::~Application()
	{
	}

	void Application::Run() {
		while (!window->IsClosing()) {
			window->Update();
		}
	}

	void Application::loadScene(Scene* scene) {
		window->scene = scene;
	}

}