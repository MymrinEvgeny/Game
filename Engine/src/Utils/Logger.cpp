#include "Logger.hpp"

namespace Engine::Utils {

	// Methods
	void Logger::log(Level level, const std::string& message) {

		std::time_t t = std::time(nullptr);
		std::tm* now = std::localtime(&t);

		std::cout << "[";
		if (now->tm_hour < 10) std::cout << "0";
		std::cout << now->tm_hour << ":";
		if (now->tm_min < 10) std::cout << "0";
		std::cout << now->tm_min << ":";
		if (now->tm_sec < 10) std::cout << "0";
		std::cout << now->tm_sec << "]\t";

		switch (level){
		case Engine::Utils::Logger::Level::LOG: {
			std::clog << "LOG:\t" << message << std::endl;
		} break;
		case Engine::Utils::Logger::Level::ERR: {
			std::cerr << "\033[31mERROR:\t" << message << "\033[0m" << std::endl;
		} break;
		}
	}

}