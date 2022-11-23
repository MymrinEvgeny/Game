#pragma once
#include "Vertex.hpp"
#include "Utils/Logger.hpp"

#include <glad/glad.h>

#include <vector>

namespace Engine::Graphics {

	class ArrayBuffer {
	private:

		// Fields
		GLuint m_handle;


	public:

		// Constructors
		ArrayBuffer() = delete;


		ArrayBuffer(const ArrayBuffer&) = delete;


		ArrayBuffer(ArrayBuffer&&) = delete;


		ArrayBuffer(const std::vector<Vertex>& vertices);


		~ArrayBuffer();


		// Operators
		ArrayBuffer& operator=(const ArrayBuffer&) = delete;


		ArrayBuffer& operator=(ArrayBuffer&&) = delete;


		// Methods
		void bind() const;


		static void unbind();


	};

}