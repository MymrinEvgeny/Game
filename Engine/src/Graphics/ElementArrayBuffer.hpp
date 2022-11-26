#pragma once
#include "Utils/Logger.hpp"

#include <glad/glad.h>

#include <vector>

namespace Engine::Graphics {

	class ElementArrayBuffer {
	private:

		// Fields
		GLuint m_handle;


		size_t m_count;


	public:

		// Constructors
		ElementArrayBuffer() = delete;


		ElementArrayBuffer(const ElementArrayBuffer&) = delete;


		ElementArrayBuffer(ElementArrayBuffer&&) = delete;


		ElementArrayBuffer(const std::vector<GLuint>& indices);


		~ElementArrayBuffer();


		// Operators
		ElementArrayBuffer& operator=(const ElementArrayBuffer&) = delete;


		ElementArrayBuffer& operator=(ElementArrayBuffer&&) = delete;


		// Methods
		size_t getCount() const;


		void bind() const;


		static void unbind();


	};

}