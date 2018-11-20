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
		material->SetUniform3f("u_Color", glm::vec3(1.0, 1.0, 0.0));
		Graphics::Material* material2 = new Graphics::Material(shader);
		material2->SetUniform3f("u_Color", glm::vec3(0.2, 0.3, 0.8));

		Actor* a = new SandboxActor();
		Actor* a2 = new SandboxActor();
		Actor* a3 = new Actor();
		Camera* c = new Camera();
		c->transform->pos.y = 3;
		//c->transform->pos.x = 6;
		//c->transform->pos.z = -5;
		c->transform->rot.x = -30;
		//c->transform->rot.y = 90;
		Graphics::OPENGL::Vertex verts[24] = { 
		{ 0.5f, 0.5f, 0.5f, 0, 1, 0 },
		{ 0.5f, 0.5f, -0.5f, 0, 1, 0 },
		{ -0.5f, 0.5f, -0.5f, 0, 1, 0 },
		{ -0.5f, 0.5f, 0.5f, 0, 1, 0}, //top
		
		{ 0.5f, -0.5f, 0.5f, 0, -1, 0 },
		{ 0.5f, -0.5f, -0.5f, 0, -1, 0 },
		{ -0.5f, -0.5f, -0.5f, 0, -1, 0 },
		{ -0.5f, -0.5f, 0.5f, 0, -1, 0}, //bottom

		{-0.5f, 0.5f, -0.5f, 0, 0, -1},
		{ -0.5f, -0.5f, -0.5f, 0, 0, -1 },
		{ 0.5f, -0.5f, -0.5f, 0, 0, -1 },
		{ 0.5f, 0.5f, -0.5f, 0, 0, -1 },//front
		
		{-0.5f, 0.5f, 0.5f, 0, 0, 1},
		{ -0.5f, -0.5f, 0.5f, 0, 0, 1 },
		{ 0.5f, -0.5f, 0.5f, 0, 0, 1 },
		{ 0.5f, 0.5f, 0.5f, 0, 0, 1 },//back

		{ -0.5f, 0.5f, -0.5f, -1, 0, 0 },
		{ -0.5f, 0.5f, 0.5f, -1, 0, 0 },
		{ -0.5f, -0.5f, 0.5f, -1, 0, 0 },
		{ -0.5f, -0.5f, -0.5f, -1, 0, 0 },//left

		{ 0.5f, 0.5f, -0.5f, 1, 0, 0 },
		{ 0.5f, 0.5f, 0.5f, 1, 0, 0 },
		{ 0.5f, -0.5f, 0.5f, 1, 0, 0 },
		{ 0.5f, -0.5f, -0.5f, 1, 0, 0 }//right
		
		};
		//OPENGL::VertexBuffer* buffer = new OPENGL::VertexBuffer(verts, 8);
		unsigned int indecies[12 * 3] = { 
			0, 1, 2, 2, 3, 0, //top
			4, 5, 6, 6, 7, 4, //bottom
			8, 9, 10, 10, 11, 8, //back
			12, 13, 14, 14, 15, 12, //front
			16, 17, 18, 18, 19, 16, // left
			20, 21, 22, 22, 23, 20 //right
		};
		Graphics::Model* model = new Graphics::Model(verts,24, indecies, 12 * 3);
		a->model = model;
		a2->model = model;
		a->material = material;
		a2->material = material2;
		a->transform->pos = glm::vec3(-1.5f, 0.0f, -3.0f);
		a->transform->rot = glm::vec3(0, 45, 0);
		a->transform->scale = glm::vec3(2.0f, 1.0f, 1.0f);
		a->transform->parent = a3->transform;
		a2->transform->pos = glm::vec3(1.5f, 0.0f, -3.0f);
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