#include "Game.hpp"

std::unique_ptr<Engine::Core::Application> Engine::Core::createApplication(int argc, char* argv[]) {
	return std::make_unique<Game>(argc, argv);
}


// Methods
void Game::windowSizeCallback(int width, int height) {
	Engine::Graphics::Renderer::setViewport(0, 0, width, height);
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

}


void Game::update() {
	m_defaultShaderProgram->setUniform1f("uTime", getTime());
}


void Game::render() {

	Engine::Graphics::Renderer::clearColor(0.05f, 0.01f, 0.20f, 1.0f);
	Engine::Graphics::Renderer::clear(Engine::Graphics::Renderer::Mask::COLOR_BUFFER_BIT);

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