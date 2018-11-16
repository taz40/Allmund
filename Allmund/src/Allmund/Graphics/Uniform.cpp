#include "Uniform.h"

namespace Allmund::Graphics::OPENGL {

	Uniform::Uniform() {
	}
	
	Uniform::~Uniform() {
	}

	UniformInt::UniformInt(int value) {
		this->value = value;
	}
	UniformInt::~UniformInt()
	{
	}
	void UniformInt::ApplyUniformAtLocation(int location, Shader* shader) {
		shader->SetUniform1i(location, value);
	}

	UniformFloat::UniformFloat(float value) {
		this->value = value;
	}
	UniformFloat::~UniformFloat()
	{
	}
	void UniformFloat::ApplyUniformAtLocation(int location, Shader* shader) {
		shader->SetUniform1f(location, value);
	}

	UniformVec2::UniformVec2(glm::vec2 value) {
		this->value = value;
	}
	UniformVec2::~UniformVec2()
	{
	}
	void UniformVec2::ApplyUniformAtLocation(int location, Shader* shader) {
		shader->SetUniform2f(location, value);
	}

	UniformVec3::UniformVec3(glm::vec3 value) {
		this->value = value;
	}
	UniformVec3::~UniformVec3()
	{
	}
	void UniformVec3::ApplyUniformAtLocation(int location, Shader* shader) {
		shader->SetUniform3f(location, value);
	}

	UniformVec4::UniformVec4(glm::vec4 value) {
		this->value = value;
	}
	UniformVec4::~UniformVec4()
	{
	}
	void UniformVec4::ApplyUniformAtLocation(int location, Shader* shader) {
		shader->SetUniform4f(location, value);
	}

	UniformMat4::UniformMat4(glm::mat4 value) {
		this->value = value;
	}
	UniformMat4::~UniformMat4()
	{
	}
	void UniformMat4::ApplyUniformAtLocation(int location, Shader* shader) {
		shader->SetUniformMat4(location, value);
	}

}