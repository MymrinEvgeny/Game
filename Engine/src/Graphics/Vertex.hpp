#pragma once
#include "Utils/Logger.hpp"

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace Engine::Graphics {

	class Vertex {
	private:

		// Fields
		glm::vec3 m_pos;


		glm::vec3 m_color;


		glm::vec2 m_texCoord;

		
	public:

		// Constructors
		Vertex() = delete;


		Vertex(const Vertex& vertex);


		Vertex(Vertex&& vertex) noexcept;


		Vertex(const glm::vec3& pos, const glm::vec3& color, const glm::vec2& texCoord);


		~Vertex();


		// Operators
		Vertex& operator=(const Vertex& vertex);


		Vertex& operator=(Vertex&& vertex) noexcept;


	};

}