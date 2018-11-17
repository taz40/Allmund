#include "Model.h"

namespace Allmund::Graphics {

	Model::Model(OPENGL::Vertex* vertexData, unsigned int vertexCount, unsigned int* indexData, unsigned int indexCount){
		vertexBuffer = new OPENGL::VertexBuffer(vertexData, vertexCount);
		indexBuffer = new OPENGL::IndexBuffer(indexData, indexCount);
	}


	Model::~Model()
	{
	}

	void Model::Bind() {
		vertexBuffer->Bind();
		indexBuffer->Bind();
	}

	void Model::Unbind() {
		vertexBuffer->Unbind();
		indexBuffer->Unbind();
	}

}