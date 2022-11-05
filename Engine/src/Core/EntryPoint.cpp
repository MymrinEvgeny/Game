#include "Application.hpp"

int main(int argc, char* argv[]) {
	
	std::unique_ptr<Engine::Core::Application> app(
		new Engine::Core::Application(argc, argv)
	);
	app->run();

	return 0;
}