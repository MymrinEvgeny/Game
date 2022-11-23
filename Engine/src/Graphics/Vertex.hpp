#pragma once
#include "Utils/Logger.hpp"

#include <glm/vec3.hpp>

namespace Engine::Graphics {

	class Vertex {
	private:

		// Fields
		glm::vec3 m_pos;


		glm::vec3 m_color;


	public:

		// Constructors
		Vertex() = delete;


		Vertex(const Vertex& vertex);


		Vertex(Vertex&& vertex) noexcept;


		Vertex(const glm::vec3& pos, const glm::vec3& color);


		~Vertex();


		// Operators
		Vertex& operator=(const Vertex& vertex);


		Vertex& operator=(Vertex&& vertex) noexcept;


	};

}