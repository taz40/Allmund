#pragma once
#include <glm/glm.hpp>

namespace Allmund {

	class Transform
	{
	public:
		Transform();
		~Transform();

		glm::mat4 getTransformMatrix();

		glm::vec3 pos;
		glm::vec3 rot;
		glm::vec3 scale;

	};

}