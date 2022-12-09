#include "VertexArray.hpp"

namespace Engine::Graphics {

	// Constructors
	VertexArray::VertexArray(std::shared_ptr<ArrayBuffer> arrayBuffer) {
		Utils::Logger::log(Utils::Logger::Level::LOG, "VertexArray::VertexArray(...)");
		
		glCreateVertexArrays(1, &m_handle);
		bind();
		arrayBuffer->bind();

		// pos attrib
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glEnableVertexAttribArray(0);

		// color attrib
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(glm::vec3));
		glEnableVertexAttribArray(1);

		// texCoord attrib
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(2 * sizeof(glm::vec3)));
		glEnableVertexAttribArray(2);

		arrayBuffer->unbind();
		unbind();

		m_count = arrayBuffer->getCount();

	}


	VertexArray::~VertexArray() {
		Utils::Logger::log(Utils::Logger::Level::LOG, "VertexArray::~VertexArray()");
		glDeleteVertexArrays(1, &m_handle);
	}


	// Methods
	size_t VertexArray::getCount() const {
		return m_count;
	}


	void VertexArray::bind() const {
		glBindVertexArray(m_handle);
	}


	void VertexArray::unbind() {
		glBindVertexArray(NULL);
	}


}