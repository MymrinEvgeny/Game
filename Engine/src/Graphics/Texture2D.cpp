#include "Texture2D.hpp"

namespace Engine::Graphics {

	// Constructors
	Texture2D::Texture2D(const std::shared_ptr<Graphics::Image> image) {
		Utils::Logger::log(Utils::Logger::Level::LOG, "Texture::Texture(...)");
		glCreateTextures(GL_TEXTURE_2D, 1, &m_handle);

		bind();

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0,
			image->getInteger(Image::Mode::IMAGE_FORMAT),
			image->getInteger(Image::Mode::IMAGE_WIDTH),
			image->getInteger(Image::Mode::IMAGE_HEIGHT),
			0,
			image->getInteger(Image::Mode::IMAGE_FORMAT),
			image->getInteger(Image::Mode::IMAGE_TYPE),
			image->getData());

		glGenerateMipmap(GL_TEXTURE_2D);
		
		unbind();

	}


	Texture2D::~Texture2D() {
		Utils::Logger::log(Utils::Logger::Level::LOG, "Texture::~Texture()");
		glDeleteTextures(1, &m_handle);
	}


	// Methods
	void Texture2D::bind(Texture texture) const {
		glActiveTexture(static_cast<GLenum>(texture));
		glBindTexture(GL_TEXTURE_2D, m_handle);
	}


	void Texture2D::unbind() {
		glBindTexture(GL_TEXTURE_2D, NULL);
	}


}