#pragma once
#include "ArrayBuffer.hpp"
#include "Utils/Logger.hpp"

#include <glad/glad.h>

namespace Engine::Graphics {

	class VertexArray {
	private:

		// Fields
		GLuint m_handle;


	public:

		// Constructors
		VertexArray(std::shared_ptr<ArrayBuffer> arrayBuffer);


		VertexArray(const VertexArray&) = delete;


		VertexArray(VertexArray&&) = delete;


		~VertexArray();


		// Operators
		VertexArray& operator=(const VertexArray&) = delete;


		VertexArray& operator=(VertexArray&&) = delete;


		// Methods
		void bind() const;

		
		static void unbind();


	};

}