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
			OPENGL::Shader* shader = new OPENGL::Shader("res/shaders/Basic.shader");
			material = new Material(shader);
			material->SetUniform4f("u_Color", glm::vec4(1.0,1.0,0.0,1.0));
			material2 = new Material(shader);
			material2->SetUniform4f("u_Color", glm::vec4(0.2,0.3,0.8,1.0));
			GLCall(glEnable(GL_DEPTH_TEST));
			GLCall(glDepthFunc(GL_LESS));
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
			OPENGL::Vertex verts[8] = { {0.5f, 0.5f, 0.5f}, {0.5f, 0.5f, -0.5f}, {-0.5f, 0.5f, -0.5f}, {-0.5f, 0.5f, 0.5f}, {-0.5f, -0.5f, 0.5f}, {0.5f, -0.5f, 0.5f}, {0.5f, -0.5f, -0.5f}, {-0.5f, -0.5f, -0.5f} };
			OPENGL::VertexBuffer* buffer = new OPENGL::VertexBuffer(verts, 8);
			unsigned int indecies[12 * 3] = { 0,4,3, 0, 5, 4, 3,4,7, 2, 3, 7, 1, 7, 6, 1, 2, 7, 5, 6, 7, 7, 4, 5, 2, 1, 0, 0, 3, 2, 5, 0, 1, 1, 6, 5 };
			OPENGL::IndexBuffer* Ibuffer = new OPENGL::IndexBuffer(indecies, 12 * 3);
			glm::mat4 proj = glm::perspective<float>(glm::radians(45.0f), 4.0f/3.0f, 1.0f, 100.0f);//glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
			Transform transform;
			transform.pos = glm::vec3(-1.5f, 0.0f, -5.0f);
			transform.rot = glm::vec3(45,rotX,0);
			rotX += 1.0f;
			transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
			material->SetUniformMat4("u_MV", transform.getTransformMatrix());
			material->SetUniformMat4("u_Projection", proj);
			material->Bind();
			/* Render here */
			GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

			buffer->Bind();
			Ibuffer->Bind();
			GLCall(glDrawElements(GL_TRIANGLES, 12 * 3, GL_UNSIGNED_INT, nullptr));
			material->Unbind();

			Transform transform2;
			transform2.pos = glm::vec3(1.5f, 0.0f, -5.0f);
			transform2.rot = glm::vec3(45, -rotX, 0);
			transform2.scale = glm::vec3(1.0f, 1.0f, 1.0f);
			material2->SetUniformMat4("u_MV", transform2.getTransformMatrix());
			material2->SetUniformMat4("u_Projection", proj);
			material2->Bind();
			GLCall(glDrawElements(GL_TRIANGLES, 12 * 3, GL_UNSIGNED_INT, nullptr));

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