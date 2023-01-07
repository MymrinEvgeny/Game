#include "ShaderProgram.hpp"

namespace Engine::Graphics {

	// Methods
 	GLuint ShaderProgram::createShader(const std::string& source,
		const GLenum shaderType) {

		GLuint shaderHandle = glCreateShader(shaderType);
		if (!shaderHandle) {
			Utils::Logger::log(Utils::Logger::Level::ERR, "Shader creation");
		}

		const char* s = source.c_str();
		glShaderSource(shaderHandle, 1, &s, nullptr);
		glCompileShader(shaderHandle);

		if(!getShaderParam(shaderHandle, GL_COMPILE_STATUS)) {
			GLchar infoLog[1024];
			glGetShaderInfoLog(shaderHandle, 1024, nullptr, infoLog);
			Utils::Logger::log(Utils::Logger::Level::ERR,
				"Shader compile, info log:\n" + std::string(infoLog));
		}

		return shaderHandle;
	}


	GLint ShaderProgram::getShaderParam(GLuint shaderHandle, GLenum paramType) {
		GLint param;

		glGetShaderiv(shaderHandle, paramType, &param);

		return param;
	}


	GLint ShaderProgram::getProgramParam(GLuint programHandle, GLenum paramType) {
		GLint param;

		glGetProgramiv(programHandle, paramType, &param);

		return param;
	}


	// Constructors
	ShaderProgram::ShaderProgram(const std::string& vertexShaderSource,
		const std::string& fragmentShaderSource) {

		Utils::Logger::log(Utils::Logger::Level::LOG, "ShaderProgram::ShaderProgram(...)");

		// Vertex shader
		GLuint vertexShaderHandle = 
			createShader(vertexShaderSource, GL_VERTEX_SHADER);

		// Fragment shader
		GLuint fragmentShaderHandle =
			createShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

		// Shader program
		m_handle = glCreateProgram();
		if (!m_handle) {
			Utils::Logger::log(Utils::Logger::Level::ERR, "Program creation");
		}

		glAttachShader(m_handle, vertexShaderHandle);
		glAttachShader(m_handle, fragmentShaderHandle);

		glLinkProgram(m_handle);

		if (!getProgramParam(m_handle, GL_LINK_STATUS)) {
			GLchar infoLog[1024];
			glGetProgramInfoLog(m_handle, 1024, nullptr, infoLog);
			Utils::Logger::log(Utils::Logger::Level::ERR,
				"Program link, info log:\n" + std::string(infoLog));
		}

		glDeleteShader(vertexShaderHandle);
		glDeleteShader(fragmentShaderHandle);
	}


	ShaderProgram::~ShaderProgram() {
		Utils::Logger::log(Utils::Logger::Level::LOG, "ShaderProgram::~ShaderProgram()");
		glDeleteProgram(m_handle);
	}


	// Methods
	void ShaderProgram::use() const {
		glUseProgram(m_handle);
	}


	void ShaderProgram::setUniform1f(const std::string& uniformName,
		const GLfloat& value) const {
		glUniform1f(glGetUniformLocation(m_handle, uniformName.c_str()), value);
	}


	void ShaderProgram::setUniform1i(const std::string& uniformName,
		const GLint& value) const {
		glUniform1i(glGetUniformLocation(m_handle, uniformName.c_str()), value);
	}


	void ShaderProgram::setUniformMatrix4fv(const std::string& uniformName,
		const glm::mat4& matrix) {
		glUniformMatrix4fv(glGetUniformLocation(m_handle, uniformName.c_str()),
			1, GL_FALSE, glm::value_ptr(matrix));
	}


}