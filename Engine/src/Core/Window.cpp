#include "Window.hpp"

namespace Engine::Core {
	
	// Constructors
	Window::Window(int width, int height,
		const char* title,
		GLFWmonitor* monitor,
		GLFWwindow* share) {
		
		Utils::Logger::log(Utils::Logger::Level::LOG, "Window::Window(...)");
		m_handle = glfwCreateWindow(width, height, title, monitor, share);
		assert(m_handle);

	}


	Window::~Window() {
		Utils::Logger::log(Utils::Logger::Level::LOG, "Window::~Window()");
		glfwDestroyWindow(m_handle);
	}


	// Methods
	GLFWwindow* Window::getHandle() const {
		return m_handle;
	}


	int Window::windowShouldClose() const {
		return glfwWindowShouldClose(m_handle);
	}
		

	void Window::update() const {
		glfwSwapBuffers(m_handle);
		glfwPollEvents();
	}
}