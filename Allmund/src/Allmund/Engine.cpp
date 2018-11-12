#include "Engine.h"
#include "Log.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Allmund {

	RenderAPI Allmund::renderAPI = AM_DEFAULT_RENDER_API;

	bool Allmund::Init(){
		if (renderAPI == RenderAPI::DirectX) {
			AM_CORE_WARN("DirectX is not supported, swiching to OpenGL");
			renderAPI = RenderAPI::OpenGL;
		}
		if (renderAPI == RenderAPI::Metal) {
			AM_CORE_WARN("Metal is not supported, switching to OpenGL");
			renderAPI = RenderAPI::OpenGL;
		}
		if (renderAPI == RenderAPI::OpenGL) {
			AM_CORE_INFO("Initializing OpenGL Rendering API");
			GLFWwindow* window;

			/* Initialize the library */
			if (!glfwInit()) {
				AM_CORE_FATAL("GLFW Failed to initialize");
				return false;
			}

			

			return true;
		}
	}

	void Allmund::Terminate() {
		if (renderAPI == RenderAPI::DirectX) {
		}
		if (renderAPI == RenderAPI::Metal) {
		}
		if (renderAPI == RenderAPI::OpenGL) {
			glfwTerminate();
		}
	}

}