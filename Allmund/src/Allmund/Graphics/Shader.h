#pragma once
#include "../Core.h"
#include <iostream>

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
	};

}	
