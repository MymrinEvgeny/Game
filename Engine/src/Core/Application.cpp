#include "Application.hpp"

namespace Engine::Core {

	// Methods
	void Application::windowSizeCallback(int width, int height) {}


	void Application::keyCallback(int key, int scancode, int action, int mods) {}


	void Application::cursorPosCallback(double xpos, double ypos) {}


	// Constructors
	Application::Application(int argc, char* argv[]) {
		Utils::Logger::log(Utils::Logger::Level::LOG, "Application::Application(...)");

		// vars
		int result;


		// set m_argc and m_argv
		for (size_t i = 0; i < argc; i++) {
			m_args.push_back(std::string(argv[i]));
		}


		// initGlfw
		result = glfwInit();
		assert(result);


		// windowHints
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


		// createWindow
		m_window = std::make_unique<Window>(640, 480, "Game", nullptr, nullptr);


		// makeContextCurrent
		glfwMakeContextCurrent(m_window->getHandle());


		// setWindowUserPointer
		glfwSetWindowUserPointer(m_window->getHandle(), this);


		// callbacks
		glfwSetErrorCallback(
			[](int error_code, const char* description) {
				std::cerr << "\033[31mERROR(GLFW): error_code: "
					<< error_code << ", description: "
					<< description << "\033[0m" << std::endl;
			});


		glfwSetWindowSizeCallback(m_window->getHandle(),
			[](GLFWwindow* window, int width, int height) {
				static_cast<Application*>(glfwGetWindowUserPointer(window))->
					windowSizeCallback(width, height);
			});


		glfwSetKeyCallback(m_window->getHandle(),
			[](GLFWwindow* window, int key, int scancode, int action, int mods) {
				static_cast<Application*>(glfwGetWindowUserPointer(window))->
					keyCallback(key, scancode, action, mods);
			});


		glfwSetCursorPosCallback(m_window->getHandle(),
			[](GLFWwindow* window, double xpos, double ypos) {
				static_cast<Application*>(glfwGetWindowUserPointer(window))->
					cursorPosCallback(xpos, -ypos);
			});


		// initGlad
		result = gladLoadGL();
		assert(result);


		// init DevIL
		ilInit();


	}


	Application::~Application() {
		Utils::Logger::log(Utils::Logger::Level::LOG, "Application::~Application()");
		glfwTerminate();
	}


	// Methods
	void Application::run() {
		init();
		double lastTime = getTime();
		while (!m_window->windowShouldClose()) {
			update(getTime() - lastTime);
			lastTime = getTime();
			render();
			m_window->update();
		}
	}


	std::vector<std::string> Application::getArgs() const {
		return m_args;
	}


	GLFWwindow* Application::getWindowHandle() const {
		return m_window->getHandle();
	}


	double Application::getTime() const {
		return glfwGetTime();
	}


}