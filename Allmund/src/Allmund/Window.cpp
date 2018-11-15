#include "Window.h"
#include "Engine.h"
#include "Log.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/IndexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/OpenGL.h"

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
			shader = new OPENGL::Shader("res/shaders/Basic.shader");
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
			OPENGL::Vertex verts[4] = { 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f };
			OPENGL::VertexBuffer* buffer = new OPENGL::VertexBuffer(verts, 4);
			unsigned int indecies[6] = { 0, 1, 3, 1, 2, 3 };
			OPENGL::IndexBuffer* Ibuffer = new OPENGL::IndexBuffer(indecies, 6);
			shader->Bind();
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			buffer->Bind();
			Ibuffer->Bind();
			OPENGL::GLClearError();
			glDrawElements(GL_TRIANGLES, 6, GL_INT, nullptr);
			OPENGL::GLCheckError();
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