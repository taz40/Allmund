#include "Shader.h"
#include "../Log.h"
#include "OpenGL.h"
#include <GL/glew.h>
#include <fstream>
#include <string>
#include <sstream>

namespace Allmund::Graphics::OPENGL {

	unsigned int Shader::compileShader(unsigned int type, const std::string& source) {
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		GLCall(glShaderSource(id, 1, &src, nullptr));
		GLCall(glCompileShader(id));

		int result;
		GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
		if (result == GL_FALSE) {
			int length;
			GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
			char* message = (char*)alloca(length * sizeof(char));
			GLCall(glGetShaderInfoLog(id, length, &length, message));
			AM_CORE_ERROR("{0} shader failed to compile.", (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment"));
			AM_CORE_ERROR(message);
			GLCall(glDeleteShader(id));
			return 0;
		}

		return id;
	}

	unsigned int Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader) {
		GLCall(unsigned int program = glCreateProgram());
		unsigned int vertShader = compileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fragShader = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

		GLCall(glAttachShader(program, vertShader));
		GLCall(glAttachShader(program, fragShader));
		GLCall(glLinkProgram(program));
		GLCall(glValidateProgram(program));

		GLCall(glDeleteShader(vertShader));
		GLCall(glDeleteShader(fragShader));

		return program;
	}

	Shader::Shader(const std::string& path)
	{
		this->path = path;
		AM_CORE_TRACE("Creating shader from file: {0}", path);
		std::ifstream stream(path);

		enum class ShaderType {
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		std::string line;
		std::stringstream ss[2];
		ShaderType type = ShaderType::NONE;
		while (getline(stream, line)) {
			if (line.find("#shader") != std::string::npos) {
				if (line.find("vertex") != std::string::npos) {
					type = ShaderType::VERTEX;
				}else if (line.find("fragment") != std::string::npos) {
					type = ShaderType::FRAGMENT;
				}
			} else {
				ss[(int)type] << line << '\n';
			}
		}

		shader_id = createShader(ss[(int)ShaderType::VERTEX].str(), ss[(int)ShaderType::FRAGMENT].str());
	}


	Shader::~Shader(){
		GLCall(glDeleteProgram(shader_id));
	}

	void Shader::Bind() {
		GLCall(glUseProgram(shader_id));
	}

	void Shader::Unbind() {
		GLCall(glUseProgram(0));
	}

}