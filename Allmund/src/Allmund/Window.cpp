#include "Window.h"
#include "Engine.h"
#include "Log.h"
#include "Graphics/VertexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace Allmund::Graphics;

namespace Allmund {

	Window::Window(int width, int height, const char * title){
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
		}
		else {
			AM_CORE_FATAL("Render API unsuported, cannot create window.\nRender API = {0}", Allmund::renderAPI);
		}
	}


	Window::~Window()
	{
	}

	void Window::Update() {
		if (Allmund::renderAPI == RenderAPI::OpenGL) {


			VertexBuffer* buffer = new VertexBuffer(new float[6] {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f});
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			buffer->Bind();
			glDrawArrays(GL_TRIANGLES, 0, 3);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	bool Window::IsClosing() {
		if (Allmund::renderAPI) {
			return glfwWindowShouldClose(window);
		}
		AM_CORE_FATAL("Not using supported render API\nRender API = {0}", Allmund::renderAPI);
		return true;
	}

}