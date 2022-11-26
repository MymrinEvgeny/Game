#pragma once
#include "ShaderProgram.hpp"
#include "VertexArray.hpp"
#include "ElementArrayBuffer.hpp"
#include "Utils/Logger.hpp"

#include <glad/glad.h>

namespace Engine::Graphics {

	class Renderer {
	public:

		// Classes
		enum class Mask {
			COLOR_BUFFER_BIT = GL_COLOR_BUFFER_BIT,
			DEPTH_BUFFER_BIT = GL_DEPTH_BUFFER_BIT,
			STENCIL_BUFFER_BIT = GL_STENCIL_BUFFER_BIT
		};


		enum class Mode {
			POINTS = GL_POINTS,
			LINE_STRIP = GL_LINE_STRIP,
			LINE_LOOP = GL_LINE_LOOP,
			LINES = GL_LINES,
			LINE_STRIP_ADJACENCY = GL_LINE_STRIP_ADJACENCY,
			LINES_ADJACENCY = GL_LINES_ADJACENCY,
			TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
			TRIANGLE_FAN = GL_TRIANGLE_FAN,
			TRIANGLES = GL_TRIANGLES,
			TRIANGLE_STRIP_ADJACENCY = GL_TRIANGLE_STRIP_ADJACENCY,
			TRIANGLES_ADJACENCY = GL_TRIANGLES_ADJACENCY,
			PATCHES = GL_PATCHES
		};


		// Constructors
		Renderer() = delete;


		Renderer(const Renderer&) = delete;


		Renderer(Renderer&&) = delete;


		~Renderer() = delete;


		// Operators
		Renderer& operator=(const Renderer&) = delete;


		Renderer& operator=(Renderer&&) = delete;


		// Methods
		static void setViewport(GLint x, GLint y, GLsizei width, GLsizei height);


		static void clear(Mask mask);


		static void clearColor(GLfloat red, GLfloat green,
			GLfloat blue, GLfloat alpha);


		static void clearDepthf(GLfloat depth);


		static void clearDepth(GLdouble depth);


		static void clearStencil(GLint s);


		static void drawArrays(
			const std::shared_ptr<ShaderProgram> shaderProgram, 
			const std::shared_ptr<VertexArray> vertexArray,
			const Mode mode);


		static void drawElements(
			const std::shared_ptr<ShaderProgram> shaderProgram,
			const std::shared_ptr<VertexArray> vertexArray,
			const std::shared_ptr<ElementArrayBuffer> elementArrayBuffer,
			const Mode mode);


	};


}