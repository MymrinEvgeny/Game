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
		executablePath + std::string("assets\\shaders\\vDefault.glsl"),
		executablePath + std::string("assets\\shaders\\fDefault.glsl"));

	std::vector<Engine::Graphics::Vertex> vertices = {
		Engine::Graphics::Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
		Engine::Graphics::Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
		Engine::Graphics::Vertex(glm::vec3(0.0f,  0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f))
	};

	m_arrayBuffer = std::make_shared<Engine::Graphics::ArrayBuffer>(vertices);

	m_vertexArray = std::make_shared<Engine::Graphics::VertexArray>(m_arrayBuffer);
	
}


void Game::update() {
	m_defaultShaderProgram->setUniform1d("uTime", getTime());
}


void Game::render() {

	Engine::Graphics::Renderer::clearColor(0.05f, 0.01f, 0.20f, 1.0f);
	Engine::Graphics::Renderer::clear(Engine::Graphics::Renderer::Mask::COLOR_BUFFER_BIT);

	Engine::Graphics::Renderer::drawArrays(m_defaultShaderProgram,
		m_vertexArray, Engine::Graphics::Renderer::Mode::TRIANGLES);

}


// Constructors
Game::Game(int argc, char* argv[]) : Application(argc, argv) {
	Engine::Utils::Logger::log(Engine::Utils::Logger::Level::LOG, "Game::Game(...)");
	executablePath = getArgs()[0].substr(0, getArgs()[0].find_last_of("\\") + 1);
}


Game::~Game() {
	Engine::Utils::Logger::log(Engine::Utils::Logger::Level::LOG, "Game::~Game()");
}