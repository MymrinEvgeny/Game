#pragma once

#include "Utils/Logger.hpp"

#include <IL/il.h>

#include <string>

namespace Engine::Graphics {

	class Image {
	private:

		// Fields
		ILuint m_handle;


	public:

		// Classes
		enum class Mode {
			IMAGE_WIDTH = IL_IMAGE_WIDTH,
			IMAGE_HEIGHT = IL_IMAGE_HEIGHT,
			IMAGE_TYPE = IL_IMAGE_TYPE,
			IMAGE_FORMAT = IL_IMAGE_FORMAT
		};


		// Constructors
		Image() = delete;


		Image(const Image&) = delete;


		Image(Image&&) = delete;


		Image(const std::string& filePath);


		~Image();


		// Operators
		Image& operator=(const Image&) = delete;


		Image& operator=(Image&&) = delete;


		// Methods
		void bind() const;


		static void unbind();


		ILubyte* getData() const;


		int getInteger(Mode mode) const;


	};

}