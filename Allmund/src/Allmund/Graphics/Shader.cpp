#include "Shader.h"
#include "../Log.h"
#include <GL/glew.h>

namespace Allmund::Graphics::OPENGL {

	unsigned int Shader::compileShader(unsigned int type, const std::string& source) {
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) {
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			AM_CORE_ERROR("{0} shader failed to compile.", (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment"));
			AM_CORE_ERROR(message);
			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	unsigned int Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader) {
		unsigned int program = glCreateProgram();
		unsigned int vertShader = compileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fragShader = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(program, vertShader);
		glAttachShader(program, fragShader);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertShader);
		glDeleteShader(fragShader);

		return program;
	}

	Shader::Shader(const std::string& path)
	{
		this->path = path;
		shader_id = createShader("#version 330 core\nlayout(location = 0) in vec4 position;\nvoid main(){\ngl_Position = position;\n}","#version 330 core\nlayout(location = 0) out vec4 color;\nvoid main(){\ncolor = vec4(1.0, 0.0, 0.0, 1.0);\n}");
	}


	Shader::~Shader()
	{
	}

	void Shader::Bind() {
		glUseProgram(shader_id);
	}

	void Shader::Unbind() {
		glUseProgram(0);
	}

}