#ifndef _Component_H_
    #define _Component_H_
	
#include <SDL.h>

class Entity;
class Component {
protected:

	
public:
	Entity* mEntity;
		
	virtual void onInit() {}
	virtual void onUpdate(float deltaTime) {}
	virtual void onRender(SDL_Renderer* renderer) {}
	virtual void onClean() {}
	virtual ~Component() {}
};

#endif