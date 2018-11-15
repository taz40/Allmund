#pragma once
#include "Core.h"

namespace Allmund::Graphics::OPENGL {

	class ALLMUND_API UniformBuffer{
	private:
		unsigned int buffer_id;
	public:
		UniformBuffer();
		~UniformBuffer();

		void Bind();
		void Unbind();
	};

}