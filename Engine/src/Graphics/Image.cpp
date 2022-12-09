#include "Image.hpp"

namespace Engine::Graphics {

	// Constructors
	Image::Image(const std::string& filePath) {
		Utils::Logger::log(Utils::Logger::Level::LOG, "Image::Image(...)");
		m_handle = ilGenImage();

		bind();

		ILboolean result = ilLoadImage(filePath.c_str());
		if (!result) {
			Utils::Logger::log(Utils::Logger::Level::ERR, "Loading image: " + filePath);
		}

		unbind();

	}


	Image::~Image() {
		Utils::Logger::log(Utils::Logger::Level::LOG, "Image::~Image()");
		ilDeleteImage(m_handle);
	}


	// Methods
	void Image::bind() const {
		ilBindImage(m_handle);
	}


	void Image::unbind() {
		ilBindImage(NULL);
	}


	ILubyte* Image::getData() const {
		bind();
		ILubyte* p = ilGetData();
		unbind();
		return p;
	}


	int Image::getInteger(Mode mode) const {
		bind();
		int i = ilGetInteger(static_cast<ILenum>(mode));
		unbind();
		return i;
	}


}