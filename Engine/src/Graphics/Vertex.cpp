#include "Vertex.hpp"

namespace Engine::Graphics {

	// Constructors
	Vertex::Vertex(const Vertex& vertex) {
		Utils::Logger::log(Engine::Utils::Logger::Level::LOG, "Vertex::Vertex(const Vertex&)");
		m_pos = vertex.m_pos;
		m_color = vertex.m_color;
	}


	Vertex::Vertex(Vertex&& vertex) noexcept {
		Utils::Logger::log(Engine::Utils::Logger::Level::LOG, "Vertex::Vertex(Vertex&&)");
		m_pos = std::move(vertex.m_pos);
		m_color = std::move(vertex.m_color);
	}


	Vertex::Vertex(const glm::vec3& pos, const glm::vec3& color) {
		Utils::Logger::log(Engine::Utils::Logger::Level::LOG, "Vertex::Vertex(...)");
		m_pos = pos;
		m_color = color;
	}


	Vertex::~Vertex() {
		Utils::Logger::log(Engine::Utils::Logger::Level::LOG, "Vertex::~Vertex()");
	}


	// Operators
	Vertex& Vertex::operator=(const Vertex& vertex) {
		Utils::Logger::log(Engine::Utils::Logger::Level::LOG, "Vertex::operator=(const Vertex&)");
		if (this != &vertex) {
			m_pos = vertex.m_pos;
			m_color = vertex.m_color;
		}
		return *this;
	}


	Vertex& Vertex::operator=(Vertex&& vertex) noexcept {
		Utils::Logger::log(Engine::Utils::Logger::Level::LOG, "Vertex::operator=(Vertex&&)");
		if (this != &vertex) {
			m_pos = std::move(vertex.m_pos);
			m_color = std::move(vertex.m_color);
		}
		return *this;
	}


}