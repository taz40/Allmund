#pragma once
#include "../Core.h"

namespace Allmund::Graphics::OPENGL {

	class ALLMUND_API IndexBuffer
	{
	private:
		unsigned int buffer_id;
	public:
		IndexBuffer(unsigned int* data, unsigned int count);
		~IndexBuffer();

		void Bind();
		void Unbind();
	};

}