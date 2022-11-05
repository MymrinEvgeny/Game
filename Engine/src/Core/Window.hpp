#pragma once
#include "Utils/Logger.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cassert>

namespace Engine::Core {

	class Window {
	private:
		
		// Fields
		GLFWwindow* m_windowHandle;


	public:

		// Constructors
		Window() = delete ;


		Window(int width, int height,
			const char* title,
			GLFWmonitor* monitor,
			GLFWwindow* share);


		Window(const Window&) = delete;


		Window(Window&&) = delete;


		~Window();

		
		// Operators
		Window& operator=(const Window&) = delete;


		Window& operator=(Window&&) = delete;


		// Methods
		GLFWwindow* getWindowHandle() const;


		int windowShouldClose() const;


		void update() const;


	};
}