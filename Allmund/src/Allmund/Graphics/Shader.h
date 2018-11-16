#pragma once
#include "../Core.h"
#include <iostream>
#include <glm/glm.hpp>

namespace Allmund::Graphics::OPENGL {

	class ALLMUND_API Shader
	{
	private:
		static unsigned int compileShader(unsigned int type, const std::string& source);
		static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
		std::string path;
		unsigned int shader_id;
	public:
		Shader(const std::string& path);
		~Shader();

		void Bind();
		void Unbind();

		int getUniformLocation(std::string name);

		void SetUniform1i(std::string name, int i);
		void SetUniform1f(std::string name, float f);
		void SetUniform2f(std::string name, glm::vec2 vec);
		void SetUniform3f(std::string name, glm::vec3 vec);
		void SetUniform4f(std::string name, glm::vec4 vec);
		void SetUniformMat4(std::string name, glm::mat4 mat);

		void SetUniform1i(int location, int i);
		void SetUniform1f(int location, float f);
		void SetUniform2f(int location, glm::vec2 vec);
		void SetUniform3f(int location, glm::vec3 vec);
		void SetUniform4f(int location, glm::vec4 vec);
		void SetUniformMat4(int location, glm::mat4 mat);

		unsigned int getUniformCount();

	};

}	
