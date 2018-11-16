#pragma once
#include "../Core.h" 

namespace Allmund::Graphics::OPENGL {

	struct ALLMUND_API Vertex {
		float x;
		float y;
		float z;
	};

	class ALLMUND_API VertexBuffer
	{
	private:
		unsigned int buffer_id;
		unsigned int vertex_array_id;
	public:
		VertexBuffer(Vertex* data, unsigned int count);
		~VertexBuffer();

		void Bind();
		void Unbind();
	};

}