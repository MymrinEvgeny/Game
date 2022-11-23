#include "FileSystem.hpp"

namespace Engine::Utils {

	// Methods
	std::string FileSystem::readFileToString(const std::string& filePath) {
		Logger::log(Logger::Level::LOG, "Reading file to string: " + filePath);

		std::ifstream f(filePath);

		if (!f.is_open()) {
			Logger::log(Logger::Level::ERR, "Opening file: " + filePath);
		}

		f.seekg(0, std::ios::end);
		size_t size = f.tellg();
		std::string str(size, ' ');
		f.seekg(0);
		f.read(&str[0], size);

		f.close();

		return str;
	}

}