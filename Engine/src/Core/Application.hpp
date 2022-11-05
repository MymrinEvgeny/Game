#pragma once
#include "Window.hpp"

#include <memory>

namespace Engine::Core {

	class Application {
	private:

		// Fields
		std::unique_ptr<Window> m_window;


	public:

		// Constructors
		Application() = delete;


		Application(int argc, char* argv[]);


		Application(const Application&) = delete;


		Application(Application&&) = delete;


		~Application();


		// Operators
		Application& operator=(const Application&) = delete;


		Application& operator=(Application&&) = delete;


	
		// Methods
		void run();


		void windowHints();


		void createWindow(int width, int height,
			const char* title,
			GLFWmonitor* monitor,
			GLFWwindow* share);


		void makeContextCurrent();


		void mainloop();


	};

}