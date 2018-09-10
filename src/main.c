#include "App.h"

int main(int argc, char* argv[]) {
	App* app;
	app = new App();
	
	if(app->Init()) {
		app->Loop();
	}
	
	return 0;
}