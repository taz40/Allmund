#pragma once
#include "../Core.h" 

namespace Allmund::Graphics::OPENGL {

	struct ALLMUND_API Vertex {
		float x;
		float y;
	};

	class ALLMUND_API VertexBuffer
	{
	private:
		unsigned int buffer_id;
	public:
		VertexBuffer(Vertex* data, unsigned int count);
		~VertexBuffer();

		void Bind();
		void Unbind();
	};

}