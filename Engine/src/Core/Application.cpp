#include "Application.hpp"

namespace Engine::Core {

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
		glfwSetWindowSizeCallback(m_window->getHandle(),
			[](GLFWwindow* window, int width, int height) {
				static_cast<Application*>(glfwGetWindowUserPointer(window))->windowSizeCallback(width, height);
			});


		glfwSetErrorCallback(
			[](int error_code, const char* description) {
				std::cerr << "\033[31mERROR(GLFW): error_code: "
					<< error_code << ", description: "
					<< description << "\033[0m" << std::endl;
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
		while (!m_window->windowShouldClose()) {
			update();
			render();
			m_window->update();
		}
	}


	std::vector<std::string> Application::getArgs() const {
		return m_args;
	}


	double Application::getTime() const {
		return glfwGetTime();
	}


}