#include "Actor.h"

namespace Allmund {

	Actor::Actor(){
		transform = new Transform();
		material = nullptr;
		model = nullptr;
	}


	Actor::~Actor()
	{
	}

	void Actor::Update(float deltaTime) {
		
	}

}