#ifndef _State_H_
    #define _State_H_

#include <SDL.h>

class App;
class State {
private:
	bool active;
	
protected:
	App* mApp;
	
public:
	State(App& app);
	
	void Active();
	void Deactive();
	
	virtual void onInit() = 0;
	virtual void onEvent(SDL_Event event) = 0;
	virtual void onUpdate() = 0;
	virtual void onRender() = 0;
	virtual void onClean() = 0;

};

#endif