#pragma once

#include "Utils/Logger.hpp"
#include "Image.hpp"

#include <glad/glad.h>

namespace Engine::Graphics {

	class Texture2D {
	private:

		// Fields
		GLuint m_handle;


	public:
		
		// Classes
		enum class Texture {
			TEXTURE0 = GL_TEXTURE0,
			TEXTURE1 = GL_TEXTURE1
		};


		// Constructors
		Texture2D() = delete;


		Texture2D(const Texture2D&) = delete;


		Texture2D(Texture2D&&) = delete;


		Texture2D(const std::shared_ptr<Graphics::Image> image);


		~Texture2D();


		// Operators
		Texture2D& operator=(const Texture2D&) = delete;


		Texture2D& operator=(Texture2D&&) = delete;


		// Methods
		void bind(Texture texture = Texture::TEXTURE0) const;


		static void unbind();


	};

}