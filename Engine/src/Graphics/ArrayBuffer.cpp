#include "ArrayBuffer.hpp"

namespace Engine::Graphics {

	// Constructors
	ArrayBuffer::ArrayBuffer(const std::vector<Vertex>& vertices) {
		Utils::Logger::log(Utils::Logger::Level::LOG, "ArrayBuffer::ArrayBuffer(...)");
		
		glCreateBuffers(1, &m_handle);
		bind();
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
		unbind();

		m_count = vertices.size();

	}


	ArrayBuffer::~ArrayBuffer() {
		Utils::Logger::log(Utils::Logger::Level::LOG, "ArrayBuffer::~ArrayBuffer()");
		glDeleteBuffers(1, &m_handle);
	}


	// Methods
	size_t ArrayBuffer::getCount() const {
		return m_count;
	}


	void ArrayBuffer::bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, m_handle);
	}


	void ArrayBuffer::unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, NULL);
	}


}