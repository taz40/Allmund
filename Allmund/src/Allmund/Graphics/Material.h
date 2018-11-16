#pragma once

#include "../Core.h"
#include "Shader.h"
#include "Uniform.h"

namespace Allmund::Graphics {

	class ALLMUND_API Material
	{
	private:
		OPENGL::Shader* shader;
		OPENGL::Uniform** uniforms;
		unsigned int uniform_count;
	public:
		Material(OPENGL::Shader* shader);
		~Material();

		void Bind();
		void Unbind();

		void SetUniform1i(std::string name, int i);
		void SetUniform1f(std::string name, float f);
		void SetUniform2f(std::string name, glm::vec2 vec);
		void SetUniform3f(std::string name, glm::vec3 vec);
		void SetUniform4f(std::string name, glm::vec4 vec);
		void SetUniformMat4(std::string name, glm::mat4 mat);

	};

}