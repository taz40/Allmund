#pragma once
#include "Core.h"
#include "Actor.h"
#include <glm/glm.hpp>

namespace Allmund {

	class ALLMUND_API Camera : public Actor
	{
	public:

		bool isOrtho;
		float orthoSize;
		float FOV;
		float NearPlain;
		float FarPlain;

		Camera();
		~Camera();

		void Update();

		glm::mat4 getViewMatrix();

	};

}