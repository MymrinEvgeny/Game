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


	std::shared_ptr<Engine::Graphics::Texture2D> m_texture2D_awesomeface;


	std::shared_ptr<Engine::Graphics::Texture2D> m_texture2D_container;


	std::shared_ptr<Engine::Entities::Camera> m_camera;


	float yaw = 0.0f;


	float pitch = 0.0f;


	float roll = 0.0f;


	float lastX = 0.0f;


	float lastY = 0.0f;


	// Methods
	void windowSizeCallback(int width, int height) override;


	void keyCallback(int key, int scancode, int action, int mods) override;


	void cursorPosCallback(double xpos, double ypos) override;


	void init() override;


	void update(double delta) override;


	void render() override;


public:

	// Constructors
	Game(int argc, char* argv[]);


	~Game() override;


};