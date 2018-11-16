#pragma once
#include "Shader.h"
#include <glm/glm.hpp>

namespace Allmund::Graphics::OPENGL {

	class Uniform
	{
	public:
		Uniform();
		~Uniform();

		virtual void ApplyUniformAtLocation(int location, Shader* shader) = 0;
	};

	class UniformInt : public Uniform
	{
	private:
		int value;
	public:
		UniformInt(int value);
		~UniformInt();

		virtual void ApplyUniformAtLocation(int location, Shader* shader);
	};

	class UniformFloat : public Uniform
	{
	private:
		float value;
	public:
		UniformFloat(float value);
		~UniformFloat();

		virtual void ApplyUniformAtLocation(int location, Shader* shader);
	};

	class UniformVec2 : public Uniform
	{
	private:
		glm::vec2 value;
	public:
		UniformVec2(glm::vec2 value);
		~UniformVec2();

		virtual void ApplyUniformAtLocation(int location, Shader* shader);
	};

	class UniformVec3 : public Uniform
	{
	private:
		glm::vec3 value;
	public:
		UniformVec3(glm::vec3 value);
		~UniformVec3();

		virtual void ApplyUniformAtLocation(int location, Shader* shader);
	};

	class UniformVec4 : public Uniform
	{
	private:
		glm::vec4 value;
	public:
		UniformVec4(glm::vec4 value);
		~UniformVec4();

		virtual void ApplyUniformAtLocation(int location, Shader* shader);
	};

	class UniformMat4 : public Uniform
	{
	private:
		glm::mat4 value;
	public:
		UniformMat4(glm::mat4 value);
		~UniformMat4();

		virtual void ApplyUniformAtLocation(int location, Shader* shader);
	};

}