#pragma once

#include "Utils/Logger.hpp"

#include <glad/glad.h>

#include <string>

namespace Engine::Graphics {

	class ShaderProgram {
	private:

		// Fields
		GLuint m_handle;


		// Methods
		GLuint createShader(const std::string& source, const GLenum shaderType);


		GLint getShaderParam(GLuint shaderHandle, GLenum paramType);


		GLint getProgramParam(GLuint programHandle, GLenum paramType);


	public:

		// Construstors
		ShaderProgram() = delete;


		ShaderProgram(const ShaderProgram&) = delete;


		ShaderProgram(ShaderProgram&&) = delete;


		ShaderProgram(const std::string& vertexShaderSource,
			const std::string& fragmentShaderSource);


		~ShaderProgram();


		// Operators
		ShaderProgram& operator=(const ShaderProgram&) = delete;


		ShaderProgram& operator=(ShaderProgram&&) = delete;


		// Methods
		void use() const;


		void setUniform1f(const std::string& uniformName, const GLfloat& value) const;


		void setUniform1i(const std::string& uniformName, const GLint& value) const;


	};

}