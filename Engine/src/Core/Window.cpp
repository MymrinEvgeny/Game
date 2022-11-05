#include "Window.hpp"

namespace Engine::Core {
	
	// Constructors
	Window::Window(int width, int height,
		const char* title,
		GLFWmonitor* monitor,
		GLFWwindow* share) {
		
		Utils::Logger::log("Window(...)");
		m_windowHandle = glfwCreateWindow(width, height, title, monitor, share);
		assert(m_windowHandle);

	}


	Window::~Window() {
		Utils::Logger::log("~Window()");
		glfwDestroyWindow(m_windowHandle);
	}


	// Methods
	GLFWwindow* Window::getWindowHandle() const {
		return m_windowHandle;
	}


	int Window::windowShouldClose() const {
		return glfwWindowShouldClose(m_windowHandle);
	}
		

	void Window::update() const {
		glfwSwapBuffers(m_windowHandle);
		glfwPollEvents();
	}
}