#include "Logger.hpp"

namespace Engine::Utils {

	// Methods
	void Logger::log(Level level, const std::string& message) {

		switch (level){
		case Engine::Utils::Logger::Level::LOG: {
			std::clog << "LOG: " << message << std::endl;
		} break;
		case Engine::Utils::Logger::Level::ERR: {
			std::cerr << "\033[31mERROR: " << message << "\033[0m" << std::endl;
		} break;
		}
	}

}