#include "App.h"

#include "states/GameState.h"

App::App() {
	running = true;
}

bool App::Init() {
	assetManager = new AssetManager(*this);
	stateManager = new StateManager();

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
    }

	mWindow = SDL_CreateWindow("cCc", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN);
	if( mWindow == NULL ) {
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}

	IMG_Init(IMG_INIT_PNG);
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	if( mRenderer == NULL ) {
		printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}

	stateManager->PushState(new GameState(*this));
	return true;
}

int App::Loop() {
	int countedFrames = 0;

	while(running) {
		if(oldTime + 1000 < SDL_GetTicks()) {
			oldTime = SDL_GetTicks();
			fps = countedFrames;
			countedFrames = 0;
		}
		deltaTime = ((SDL_GetTicks() - lastTime) / 1000.0f) * 32.0f;
		lastTime = SDL_GetTicks();
		countedFrames++;

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			onEvent(event);
		}

		onUpdate();
		onRender();

		std::cout << "avgFPS: " << fps << std::endl;
		std::cout << "frameTicks: " << deltaTime << std::endl;
		//printf("Seconds since start time %f \n", timer.elapsedMilliseconds());
		//std::cout << "Milliseconds: " << timer.deltaTime() << std::endl;

	}

	onClean();
}

void App::onEvent(SDL_Event event) {
	if (event.type == SDL_QUIT) {
		running = false;
	}
	stateManager->onEvent(event);
}

void App::onUpdate() {
	stateManager->onUpdate();
}

void App::onRender() {
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderClear(mRenderer);
	stateManager->onRender();
	SDL_RenderPresent(mRenderer);
}

void App::onClean() {
	SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
	IMG_Quit();
	SDL_Quit();
}
