#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "../Core.h"

namespace Allmund::Graphics {

	class ALLMUND_API Model
	{
	private:
		OPENGL::VertexBuffer* vertexBuffer;
		OPENGL::IndexBuffer* indexBuffer;
	public:
		Model(OPENGL::Vertex* vertexData, unsigned int vertexCount, unsigned int* indexData, unsigned int indexCount);
		~Model();

		void Bind();
		void Unbind();
	};

}