#include "Scene.h"

namespace Allmund {

	Scene::Scene()
	{
	}


	Scene::~Scene()
	{
	}

	void Scene::addActor(Actor* actor) {
		actors.push_back(actor);
	}

}