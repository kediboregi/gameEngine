#ifndef _GameState_H_
	#define _GameState_H_
	
#include "State.h"

class Entity;

class GameState : public State {
private:
	Entity* player;
public:

	GameState(App& app);
	void onInit();
	void onEvent(SDL_Event event);
	void onUpdate();
	void onRender();
	void onClean();
};
	
#endif