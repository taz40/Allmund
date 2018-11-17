#pragma once
#include "Core.h"
#include <glm/glm.hpp>

namespace Allmund {

	class ALLMUND_API Transform
	{
	public:
		Transform();
		~Transform();

		glm::mat4 getTransformMatrix();

		glm::vec3 pos;
		glm::vec3 rot;
		glm::vec3 scale;

		Transform* parent;

	};

}