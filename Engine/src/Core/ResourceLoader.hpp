#pragma once

#include "Utils/FileSystem.hpp"
#include "Graphics/ShaderProgram.hpp"
#include "Graphics/Texture2D.hpp"
#include "Graphics/Image.hpp"

#include <memory>

namespace Engine::Core {

	class ResourceLoader {
	public:

		// Fields
		static std::string pathToResources;

		
		// Constructors
		ResourceLoader() = delete;


		ResourceLoader(const ResourceLoader&) = delete;


		ResourceLoader(ResourceLoader&&) = delete;


		~ResourceLoader() = delete;


		// Operators
		ResourceLoader& operator=(const ResourceLoader&) = delete;


		ResourceLoader& operator=(ResourceLoader&&) = delete;


		// Methods
		static std::shared_ptr<Graphics::ShaderProgram> loadShaderProgram(
			const std::string& vertexShaderFilePath,
			const std::string& fragmentShaderFilePath);


		static std::shared_ptr<Graphics::Texture2D> loadTexture2D(
			const std::string& filePath);


	};

}