#pragma once

#include "Utils/Logger.hpp"

#include <string>
#include <fstream>

namespace Engine::Utils {

	class FileSystem {
	public:

		// Methods
		static std::string readFileToString(const std::string& filePath);


	};

}