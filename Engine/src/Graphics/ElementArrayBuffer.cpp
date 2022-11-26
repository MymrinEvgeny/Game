#include "ElementArrayBuffer.hpp"

namespace Engine::Graphics {

	// Constructors
	ElementArrayBuffer::ElementArrayBuffer(const std::vector<GLuint>& indices) {
		Utils::Logger::log(Utils::Logger::Level::LOG,
			"ElementArrayBuffer::ElementArrayBuffer(...)");
		glGenBuffers(1, &m_handle);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
			indices.data(), GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
		m_count = indices.size();
	}


	ElementArrayBuffer::~ElementArrayBuffer() {
		Utils::Logger::log(Utils::Logger::Level::LOG,
			"ElementArrayBuffer::~ElementArrayBuffer()");
		glDeleteBuffers(1, &m_handle);
	}


	// Methods
	size_t ElementArrayBuffer::getCount() const {
		return m_count;
	}


	void ElementArrayBuffer::bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
	}


	void ElementArrayBuffer::unbind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
	}


}