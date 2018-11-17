#include <Allmund.h>
#include <Allmund/Actor.h>
#include <Allmund/Camera.h>
#include <Allmund/Graphics/VertexBuffer.h>
#include <Allmund/Graphics/Model.h>
#include <glm/glm.hpp>
#include <Allmund/Scene.h>
#include <Allmund/Graphics/Shader.h>
#include <Allmund/Graphics/Material.h>
#include "SandboxActor.h"

using namespace Allmund;

class Sandbox : public Application {

public:
	Sandbox()
	: Application(800, 600, "Sandbox"){
		AM_TRACE("Sandbox initialized");

		Graphics::OPENGL::Shader* shader = new Graphics::OPENGL::Shader("res/shaders/Basic.shader");
		Graphics::Material* material = new Graphics::Material(shader);
		material->SetUniform4f("u_Color", glm::vec4(1.0, 1.0, 0.0, 1.0));
		Graphics::Material* material2 = new Graphics::Material(shader);
		material2->SetUniform4f("u_Color", glm::vec4(0.2, 0.3, 0.8, 1.0));

		Actor* a = new SandboxActor();
		Actor* a2 = new SandboxActor();
		Actor* a3 = new Actor();
		Camera* c = new Camera();
		c->transform->pos.y = 5;
		//c->transform->pos.x = 6;
		//c->transform->pos.z = -5;
		c->transform->rot.x = -45;
		//c->transform->rot.y = 90;
		Graphics::OPENGL::Vertex verts[8] = { { 0.5f, 0.5f, 0.5f },{ 0.5f, 0.5f, -0.5f },{ -0.5f, 0.5f, -0.5f },{ -0.5f, 0.5f, 0.5f },{ -0.5f, -0.5f, 0.5f },{ 0.5f, -0.5f, 0.5f },{ 0.5f, -0.5f, -0.5f },{ -0.5f, -0.5f, -0.5f } };
		//OPENGL::VertexBuffer* buffer = new OPENGL::VertexBuffer(verts, 8);
		unsigned int indecies[12 * 3] = { 0,4,3, 0, 5, 4, 3,4,7, 2, 3, 7, 1, 7, 6, 1, 2, 7, 5, 6, 7, 7, 4, 5, 2, 1, 0, 0, 3, 2, 5, 0, 1, 1, 6, 5 };
		Graphics::Model* model = new Graphics::Model(verts, 8, indecies, 12 * 3);
		a->model = model;
		a2->model = model;
		a->material = material;
		a2->material = material2;
		a->transform->pos = glm::vec3(-1.5f, 0.0f, -5.0f);
		a->transform->rot = glm::vec3(0, 45, 0);
		a->transform->scale = glm::vec3(2.0f, 1.0f, 1.0f);
		a->transform->parent = a3->transform;
		a2->transform->pos = glm::vec3(1.5f, 0.0f, -5.0f);
		a2->transform->rot = glm::vec3(0, -45, 0);
		a2->transform->scale = glm::vec3(1.0f, 2.0f, 1.0f);
		a2->transform->parent = a3->transform;
		a3->transform->pos.x = 1;
		a3->transform->rot.x = 0;

		Scene* s = new Scene();

		s->addActor(a);
		s->addActor(a2);
		s->addActor(c);
		
		loadScene(s);
	}

	~Sandbox() {
		
	}

};
namespace Allmund {
	Application* CreateApplication() {
		return new Sandbox();
	}
}