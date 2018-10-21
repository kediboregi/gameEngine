#ifndef _StateManager_H_
    #define _StateManager_H_

#include "../states/State.h"
#include <vector>


class StateManager {
private:
	std::vector<State*> m_states;

public:
	StateManager();

	void onEvent(SDL_Event event);
	void onUpdate();
	void onRender();
	void onClean();
	
	void ChangeState(State* state);
	void PushState(State* state);
	void PopState();


	State* Get();
};

#endif
