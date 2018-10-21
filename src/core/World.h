#ifndef _World_H_
	#define _World_H_

#include "../entity/Entity.h"
#include <vector>
#include <string>

class World {
private:
	std::vector<Entity*> m_entities;
public:
	World();
	void addEntity(Entity* entity);
	//Entity* getEntity(std::string ad);

	void onInit();
	void onUpdate(float deltaTime);
	void onRender(SDL_Renderer* renderer);
	void onClean();
};

#endif
