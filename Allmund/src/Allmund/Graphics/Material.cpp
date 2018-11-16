#include "Material.h"
#include <glm/glm.hpp>
#include "../Log.h"

namespace Allmund::Graphics {

	Material::Material(OPENGL::Shader* shader){
		this->shader = shader;
		uniform_count = shader->getUniformCount();
		uniforms = new OPENGL::Uniform*[uniform_count];
		for (int i = 0; i < uniform_count; i++) {
			uniforms[i] = nullptr;
		}
	}


	Material::~Material()
	{
	}

	void Material::Bind() {
		shader->Bind();
		for (int i = 0; i < uniform_count; i++) {
			if (uniforms == nullptr) {
				AM_CORE_FATAL("Uniforms array is null!");
				return;
			}
			if (uniforms[i] == nullptr)
				continue;
			uniforms[i]->ApplyUniformAtLocation(i, shader);
		}
	}

	void Material::Unbind() {
		shader->Unbind();
	}

	void Material::SetUniform1i(std::string name, int i) {
		int location = shader->getUniformLocation(name);
		if (location >= 0) {
			uniforms[location] = new OPENGL::UniformInt(i);
		}
	}
	void Material::SetUniform1f(std::string name, float f) {
		int location = shader->getUniformLocation(name);
		if (location >= 0) {
			uniforms[location] = new OPENGL::UniformFloat(f);
		}
	}

	void Material::SetUniform2f(std::string name, glm::vec2 vec) {
		int location = shader->getUniformLocation(name);
		if (location >= 0) {
			uniforms[location] = new OPENGL::UniformVec2(vec);
		}
	}

	void Material::SetUniform3f(std::string name, glm::vec3 vec) {
		int location = shader->getUniformLocation(name);
		if (location >= 0) {
			uniforms[location] = new OPENGL::UniformVec3(vec);
		}
	}

	void Material::SetUniform4f(std::string name, glm::vec4 vec) {
		int location = shader->getUniformLocation(name);
		if (location >= 0) {
			uniforms[location] = new OPENGL::UniformVec4(vec);
		}
	}

	void Material::SetUniformMat4(std::string name, glm::mat4 mat) {
		int location = shader->getUniformLocation(name);
		if (location >= 0) {
			uniforms[location] = new OPENGL::UniformMat4(mat);
		}
	}

}