#include "Renderer.hpp"

namespace Engine::Graphics {

	// Methods
	void Renderer::setViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
		glViewport(x, y, width, height);
	}


	void Renderer::clear(Mask mask) {
		glClear(static_cast<GLbitfield>(mask));
	}


	void Renderer::clearColor(GLfloat red, GLfloat green,  GLfloat blue, GLfloat alpha) {
		glClearColor(red, green, blue, alpha);
	}


	void Renderer::clearDepthf(GLfloat depth) {
		glClearDepthf(depth);
	}


	void Renderer::clearDepth(GLdouble depth) {
		glClearDepthf(depth);
	}


	void Renderer::clearStencil(GLint s) {
		glClearStencil(s);
	}


	void Renderer::drawArrays(
		const std::shared_ptr<ShaderProgram> shaderProgram,
		const std::shared_ptr<VertexArray> vertexArray,
		const Mode mode) {

		shaderProgram->use();
		vertexArray->bind();
		
		glDrawArrays(static_cast<GLenum>(mode), 0, vertexArray->getCount());

	}


	void Renderer::drawElements(
		const std::shared_ptr<ShaderProgram> shaderProgram,
		const std::shared_ptr<VertexArray> vertexArray,
		const std::shared_ptr<ElementArrayBuffer> elementArrayBuffer,
		const Mode mode) {

		shaderProgram->use();
		vertexArray->bind();
		elementArrayBuffer->bind();

		glDrawElements(static_cast<GLenum>(mode),
			elementArrayBuffer->getCount(), GL_UNSIGNED_INT, (void*)0);

	}


}