#include "World.h"

World::World() {

}

void World::addEntity(Entity* entity) {
	m_entities.emplace_back(entity);
}

/*Entity* World::getEntity(std::string ad) {
	return m_entities[ad];
}*/

void World::onInit() {
	for (auto& e : m_entities) e->onInit();
}

void World::onUpdate(float deltaTime) {
	for (auto& e : m_entities) e->onUpdate(deltaTime);
}

void World::onRender(SDL_Renderer* renderer) {
	for (auto& e : m_entities) e->onRender(renderer);
}

void World::onClean() {
	for (auto& e : m_entities) e->onClean();
}
