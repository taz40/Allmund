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

}