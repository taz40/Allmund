#pragma once
#include "../Core.h" 

namespace Allmund::Graphics {

	class ALLMUND_API VertexBuffer
	{
	private:
		unsigned int buffer_id;
	public:
		VertexBuffer(float data[]);
		~VertexBuffer();

		void Bind();
		void Unbind();
	};

}