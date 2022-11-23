#pragma once

#include <iostream>

namespace Engine::Utils {

	class Logger {
	public:

		// Classes
		enum class Level {
			LOG,
			ERR
		};


		// Methods
		static void log(Level level, const std::string& message);


	};

}