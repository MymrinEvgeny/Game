#include "Game.hpp"

std::unique_ptr<Engine::Core::Application> Engine::Core::createApplication(int argc, char* argv[]) {
	return std::make_unique<Game>(argc, argv);
}


// Methods
void Game::windowSizeCallback(int width, int height) {
	Engine::Graphics::Renderer::setViewport(0, 0, width, height);
}


void Game::keyCallback(int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(getWindowHandle(), true);
	}
	if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
		glfwSetWindowMonitor(getWindowHandle(), NULL,
			vidmode->width / 2 - 640 / 2, vidmode->height / 2 - 480 / 2,
			640, 480, GLFW_DONT_CARE);
	}
	if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
		glfwSetWindowMonitor(getWindowHandle(), monitor,
			0, 0, vidmode->width, vidmode->height, GLFW_DONT_CARE);
	}

}


void Game::cursorPosCallback(double xpos, double ypos) {

	float xOffset = xpos - lastX;
	float yOffset = ypos - lastY;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.03;
	yaw += xOffset * sensitivity;
	pitch += yOffset * sensitivity;

	if (pitch > 89.0f) pitch = 89.0f;
	if (pitch < -89.0f) pitch = -89.0f;

}


void Game::init() {
	m_defaultShaderProgram = Engine::Core::ResourceLoader::loadShaderProgram(
		executableDirectory + "assets\\shaders\\vDefault.glsl",
		executableDirectory + "assets\\shaders\\fDefault.glsl");

	m_defaultShaderProgram->use();
	m_defaultShaderProgram->setUniform1i("TEXTURE0", 0);
	m_defaultShaderProgram->setUniform1i("TEXTURE1", 1);
	m_defaultShaderProgram->setUniform1f("interpolate", 0.7);

	std::vector<Engine::Graphics::Vertex> vertices = {
		Engine::Graphics::Vertex(
			glm::vec3(-0.5f, -0.5f, 0.0f),
			glm::vec3(1.0f, 0.0f, 0.0f),
			glm::vec2(0.0f, 0.0f)),
		Engine::Graphics::Vertex(
			glm::vec3(-0.5f,  0.5f, 0.0f),
			glm::vec3(1.0f, 1.0f, 0.0f),
			glm::vec2(0.0f, 1.0f)),
		Engine::Graphics::Vertex(
			glm::vec3(0.5f,  0.5f, 0.0f),
			glm::vec3(0.0f, 0.0f, 1.0f),
			glm::vec2(1.0f, 1.0f)),
		Engine::Graphics::Vertex(
			glm::vec3(0.5f, -0.5f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec2(1.0f, 0.0f))
	};

	std::vector<GLuint> indices = {
		0, 1, 2,
		0, 2, 3
	};

	m_arrayBuffer = std::make_shared<Engine::Graphics::ArrayBuffer>(vertices);

	m_vertexArray = std::make_shared<Engine::Graphics::VertexArray>(m_arrayBuffer);
	
	m_elementArrayBuffer = std::make_shared<Engine::Graphics::ElementArrayBuffer>(indices);

	m_texture2D_awesomeface = Engine::Core::ResourceLoader::loadTexture2D(
		executableDirectory + "assets\\textures\\awesomeface.png");

	m_texture2D_container = Engine::Core::ResourceLoader::loadTexture2D(
		executableDirectory + "assets\\textures\\container.jpg");

	m_camera = std::make_shared<Engine::Entities::Camera>(
		glm::vec3(0.0f, 0.0f, 0.0f));

	m_camera->setAspectRatio(16.0f / 9.0f);

	glfwSetInputMode(getWindowHandle(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(getWindowHandle(), 0, 0);

}


void Game::update(double delta) {
	m_defaultShaderProgram->setUniform1f("uTime", getTime());

	float speed = 10 * delta;
	glm::vec3 pos = m_camera->getPosition();
	if (glfwGetKey(getWindowHandle(), GLFW_KEY_W) == GLFW_PRESS) {
		pos += m_camera->getFront() * speed;
	}
	if (glfwGetKey(getWindowHandle(), GLFW_KEY_A) == GLFW_PRESS) {
		pos -= m_camera->getRight() * speed;
	}
	if (glfwGetKey(getWindowHandle(), GLFW_KEY_S) == GLFW_PRESS) {
		pos -= m_camera->getFront() * speed;
	}
	if (glfwGetKey(getWindowHandle(), GLFW_KEY_D) == GLFW_PRESS) {
		pos += m_camera->getRight() * speed;
	}
	if (glfwGetKey(getWindowHandle(), GLFW_KEY_SPACE) == GLFW_PRESS) {
		pos += m_camera->getUp() * speed;
	}
	if (glfwGetKey(getWindowHandle(),GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		pos -= m_camera->getUp() * speed;
	}
	m_camera->setPosition(pos);

	if (glfwGetKey(getWindowHandle(), GLFW_KEY_Q) == GLFW_PRESS) {
		roll -= 10 * speed;
	}
	if (glfwGetKey(getWindowHandle(), GLFW_KEY_E) == GLFW_PRESS) {
		roll += 10 * speed;
	}

	m_camera->rotate(yaw, pitch, roll);

}


void Game::render() {

	Engine::Graphics::Renderer::clearColor(0.05f, 0.01f, 0.20f, 1.0f);
	Engine::Graphics::Renderer::clear(Engine::Graphics::Renderer::Mask::COLOR_BUFFER_BIT);

	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 1.0f));

	m_defaultShaderProgram->setUniformMatrix4fv("model", model);
	m_defaultShaderProgram->setUniformMatrix4fv("view", m_camera->getView());
	m_defaultShaderProgram->setUniformMatrix4fv("projection", m_camera->getProjection());

	m_texture2D_awesomeface->bind(Engine::Graphics::Texture2D::Texture::TEXTURE0);
	m_texture2D_container->bind(Engine::Graphics::Texture2D::Texture::TEXTURE1);

	Engine::Graphics::Renderer::drawElements(m_defaultShaderProgram,
		m_vertexArray, m_elementArrayBuffer,
		Engine::Graphics::Renderer::Mode::TRIANGLES);

}


// Constructors
Game::Game(int argc, char* argv[]) : Application(argc, argv) {
	Engine::Utils::Logger::log(Engine::Utils::Logger::Level::LOG, "Game::Game(...)");
	executableDirectory = getArgs()[0].substr(0, getArgs()[0].find_last_of("\\") + 1);
}


Game::~Game() {
	Engine::Utils::Logger::log(Engine::Utils::Logger::Level::LOG, "Game::~Game()");
}