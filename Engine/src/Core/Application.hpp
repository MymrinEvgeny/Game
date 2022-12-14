#pragma once
#include "Window.hpp"
#include "ResourceLoader.hpp"

#include <vector>
#include <memory>

namespace Engine::Core {

	class Application {
	private:

		// Fields
		std::vector<std::string> m_args;


		std::unique_ptr<Window> m_window;


		// Methods
		virtual void windowSizeCallback(int width, int height);


		virtual void keyCallback(int key, int scancode, int action, int mods);


		virtual void cursorPosCallback(double xpos, double ypos);


		virtual void init() = 0;


		virtual void update(double delta) = 0;


		virtual void render() = 0;


	public:

		// Constructors
		Application() = delete;


		Application(const Application&) = delete;


		Application(Application&&) = delete;


		Application(int argc, char* argv[]);


		virtual ~Application();


		// Operators
		Application& operator=(const Application&) = delete;


		Application& operator=(Application&&) = delete;

	
		// Methods
		void run();


		std::vector<std::string> getArgs() const;


		GLFWwindow* getWindowHandle() const;


		double getTime() const;


	};


	std::unique_ptr<Engine::Core::Application> createApplication(int argc, char* argv[]);


}