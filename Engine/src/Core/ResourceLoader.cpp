#include "ResourceLoader.hpp"

namespace Engine::Core {

	// Methods
	std::shared_ptr<Graphics::ShaderProgram> ResourceLoader::loadShaderProgram(
		const std::string& vertexShaderFilePath,
		const std::string& fragmentShaderFilePath) {

		const std::string vertexShaderSource = 
			Utils::FileSystem::readFileToString(vertexShaderFilePath);
		const std::string fragmentShaderSource =
			Utils::FileSystem::readFileToString(fragmentShaderFilePath);

		return std::make_shared<Graphics::ShaderProgram>(
			vertexShaderSource, fragmentShaderSource);
	}


	std::shared_ptr<Graphics::Texture2D> ResourceLoader::loadTexture2D(
		const std::string& filePath) {

		std::shared_ptr<Graphics::Image> image =
			std::make_shared<Graphics::Image>(filePath);

		return std::make_shared<Graphics::Texture2D>(image);

	}


}