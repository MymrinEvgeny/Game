#include "Application.hpp"

int main(int argc, char* argv[]) {
	
	auto app = Engine::Core::createApplication(argc, argv);
	app->run();

	return 0;
}