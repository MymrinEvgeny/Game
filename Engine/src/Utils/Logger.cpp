#include "Logger.hpp"

namespace Engine::Utils {

	// Methods
	void Logger::log(const std::string& message) {
		std::clog << "Log: " << message << std::endl;
	}

}