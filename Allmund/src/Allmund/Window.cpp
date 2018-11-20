#include "Window.h"
#include "Engine.h"
#include "Log.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/IndexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/OpenGL.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Transform.h"
#include "Graphics/Model.h"
#include "Actor.h"
#include "Camera.h"

using namespace Allmund::Graphics;

namespace Allmund {

	Window::Window(int width, int height, const char * title){
		scene = nullptr;
		if (Allmund::renderAPI == RenderAPI::OpenGL) {
			AM_CORE_TRACE("Creating OpenGL window with Width = {0}, Height = {1}, Title = {2}", width, height, title);
			/* Create a windowed mode window and its OpenGL context */
			window = glfwCreateWindow(width, height, title, NULL, NULL);
			if (!window)
			{
				glfwTerminate();
				AM_CORE_FATAL("GLFW window failed to open.");
				return;
			}

			/* Make the window's context current */
			glfwMakeContextCurrent(window);

			AM_CORE_TRACE("Using OpenGL version {0}", glGetString(GL_VERSION));

			GLenum err = glewInit();
			if (err != GLEW_OK) {
				AM_CORE_FATAL("GLEW Failed to initialize. Error = {0}", glewGetErrorString(err));
				return;
			}
			GLCall(glEnable(GL_DEPTH_TEST));
			GLCall(glDepthFunc(GL_LESS));
			rendererGL = new OPENGL::OpenGLRenderer();
		}
		else {
			AM_CORE_FATAL("Render API unsuported, cannot create window.\nRender API = {0}", Allmund::renderAPI);
		}
		last = std::chrono::high_resolution_clock::now();
	}


	Window::~Window()
	{
	}

	void Window::Update() {
		if (scene == nullptr)
			return;
		if (Allmund::renderAPI == RenderAPI::OpenGL) {
			rendererGL->renderScene(scene);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
		float deltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(now - last).count();
		for (int i = 0; i < scene->actors.size(); i++) {
			scene->actors[i]->Update(deltaTime);
		}
		last = std::chrono::high_resolution_clock::now();
	}

	bool Window::IsClosing() {
		if (Allmund::renderAPI) {
			return glfwWindowShouldClose(window);
		}
		AM_CORE_FATAL("Not using supported render API\nRender API = {0}", Allmund::renderAPI);
		return true;
	}

}