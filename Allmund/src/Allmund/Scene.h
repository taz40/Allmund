#pragma once
#include <vector>
#include "Actor.h"

namespace Allmund {

	class ALLMUND_API Scene
	{
	public:
		std::vector<Actor*> actors;
		Scene();
		~Scene();

		void addActor(Actor* actor);
	};

}