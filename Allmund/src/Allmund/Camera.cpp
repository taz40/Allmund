#include "Camera.h"

namespace Allmund {

	Camera::Camera(){
		isOrtho = false;
		orthoSize = 10;
		FOV = 45;
		NearPlain = 1;
		FarPlain = 100;
	}


	Camera::~Camera()
	{
	}

	void Camera::Update() {
		
	}

	glm::mat4 Camera::getViewMatrix() {
		return glm::inverse(transform->getTransformMatrix());
	}

}