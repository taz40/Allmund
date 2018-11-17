#pragma once
#include "../Core.h"
#include "Material.h"
#include "../Scene.h"


namespace Allmund::Graphics::OPENGL {

	class ALLMUND_API OpenGLRenderer
	{
	private:
		Material * defaultMaterial;
	public:
		OpenGLRenderer();
		~OpenGLRenderer();

		void renderScene(Scene* scene);
	};

}