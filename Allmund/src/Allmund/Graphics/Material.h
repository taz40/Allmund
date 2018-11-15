#pragma once

#include "../Core.h"
#include "Shader.h"

namespace Allmund::Graphics {

	class ALLMUND_API Material
	{
	private:
		OPENGL::Shader* shader;
	public:
		Material();
		~Material();
	};

}