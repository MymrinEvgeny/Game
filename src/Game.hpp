#pragma once

#include <Engine.hpp>

class Game : public Engine::Core::Application {
private:

	// Fields
	std::string executableDirectory;


	std::shared_ptr<Engine::Graphics::ShaderProgram> m_defaultShaderProgram;
	

	std::shared_ptr<Engine::Graphics::ArrayBuffer> m_arrayBuffer;


	std::shared_ptr<Engine::Graphics::ElementArrayBuffer> m_elementArrayBuffer;


	std::shared_ptr<Engine::Graphics::VertexArray> m_vertexArray;


	// Methods
	void windowSizeCallback(int width, int height) override;


	void init() override;


	void update() override;


	void render() override;


public:

	// Constructors
	Game(int argc, char* argv[]);


	~Game() override;


};