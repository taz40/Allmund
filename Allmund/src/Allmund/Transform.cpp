#include "Transform.h"
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>

namespace Allmund {

	Transform::Transform()
	{
		pos = glm::vec3(0, 0, 0);
		rot = glm::vec3(0, 0, 0);
		scale = glm::vec3(1.0f, 1.0f, 1.0f);
	}


	Transform::~Transform()
	{
	}

	glm::mat4 Transform::getTransformMatrix() {
		//glm::mat4 rotation = glm::rotate(rot.x, glm::vec3(1.0, 0.0, 0.0));
		//rotation *= glm::rotate(rot.y, glm::vec3())
		return glm::translate(pos) * glm::eulerAngleXYZ(glm::radians(rot.x), glm::radians(rot.y), glm::radians(rot.z)) * glm::scale(scale);
	}

}