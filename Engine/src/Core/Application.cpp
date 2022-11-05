#include "Application.hpp"

namespace Engine::Core {

	// Constructors
	Application::Application(int argc, char* argv[]) {
		Utils::Logger::log("Application(...)");

		int result = glfwInit();
		assert(result);

	}


	Application::~Application() {
		Utils::Logger::log("~Application()");
		glfwTerminate();
	}


	// Methods
	void Application::run() {
		windowHints();


		createWindow(640, 480, "Game", nullptr, nullptr);


		makeContextCurrent();

		/*int result = gladLoadGL();
		assert(result);
		std::cout << glGetString(GL_VERSION) << std::endl;*/

		mainloop();
	}


	void Application::windowHints() {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}


	void Application::createWindow(int width, int height,
		const char* title,
		GLFWmonitor* monitor,
		GLFWwindow* share) {

		m_window = std::unique_ptr<Window>(new Window(width, height, title, monitor, share));
	}


	void Application::makeContextCurrent() {
		glfwMakeContextCurrent(m_window->getWindowHandle());
	}

	
	void Application::mainloop() {
		while (!m_window->windowShouldClose()) {
			m_window->update();
		}
	}
}