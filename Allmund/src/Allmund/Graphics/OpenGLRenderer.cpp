#include "OpenGLRenderer.h"
#include "Shader.h"
#include "../Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "OpenGL.h"

namespace Allmund::Graphics::OPENGL {

	OpenGLRenderer::OpenGLRenderer(){
		Shader* shader = new Shader("res/shaders/unlit.shader");
		defaultMaterial = new Material(shader);
		defaultMaterial->SetUniform4f("u_Color", glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
	}


	OpenGLRenderer::~OpenGLRenderer()
	{
	}

	void OpenGLRenderer::renderScene(Scene* scene) {
		Camera* camera = nullptr;
		for (int i = 0; i < scene->actors.size(); i++) {
			if (Camera* cam = dynamic_cast<Camera*>(scene->actors[i])) {
				camera = cam;
				break;
			}
		}
		if (camera == nullptr) {
			return;
		}
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
		for (int i = 0; i < scene->actors.size(); i++) {
			Actor* a = scene->actors[i];
			if (a->model == nullptr)
				continue;
			Material* mat = a->material;
			if (mat == nullptr)
				mat = defaultMaterial;
			glm::mat4 Projection;
			if (camera->isOrtho) {
				float orthoWidth = (4.0f / 3.0f) * camera->orthoSize;
				Projection = glm::ortho(-(orthoWidth/2), orthoWidth/2, -(camera->orthoSize/2), camera->orthoSize/2, camera->NearPlain, camera->FarPlain);
			} else {
				Projection = glm::perspective(camera->FOV, 4.0f/3.0f, camera->NearPlain, camera->FarPlain);
			}
			mat->SetUniformMat4("u_Projection", Projection);
			mat->SetUniformMat4("u_Model", a->transform->getTransformMatrix());
			mat->SetUniformMat4("u_View", camera->getViewMatrix());
			mat->SetUniform3f("u_ViewPos", camera->transform->pos);
			mat->SetUniform3f("u_LightPos", glm::vec3(-2,2,-6));
			a->model->Bind();
			mat->Bind();
			GLCall(glDrawElements(GL_TRIANGLES, 12 * 3, GL_UNSIGNED_INT, nullptr));
			mat->Unbind();
			a->model->Unbind();
		}
	}

}