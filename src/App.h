#ifndef _APP_H_
    #define _APP_H_

#include <SDL.h>

#include "system/Timer.h"

#include "manager/AssetManager.h"
#include "manager/StateManager.h"

class App {
private:
	bool running;
	
public:
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	const int SCREEN_FPS = 60;
	const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

	float deltaTime = 0;
	int fps = 0;
	int oldTime = 0, lastTime = 0;

	Timer mTimer;
	Timer capTimer;

	AssetManager* assetManager;
	StateManager* stateManager;

public:
	App();
	bool Init();
	int Loop();

	void onEvent(SDL_Event event);
	void onUpdate();
	void onRender();
	void onClean();
};

#endif
