#pragma once
#include "Core.h"
#include "Graphics/Model.h"
#include "Graphics/Material.h"
#include "Transform.h"

namespace Allmund {

	class ALLMUND_API Actor
	{
	public:

		Graphics::Model* model;
		Transform* transform;
		Graphics::Material* material;

		Actor();
		~Actor();

		virtual void Update(float deltaTime);
	};

}