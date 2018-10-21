#include "Entity.h"
#include "component/Component.h"

Entity::Entity() {
}

void Entity::onInit() {
	for (auto& c : components) c->onInit();
}

void Entity::onUpdate(float deltaTime) {
	if (isActive())
		for (auto& c : components) c->onUpdate(deltaTime);
}

void Entity::onRender(SDL_Renderer* renderer) {
	if (isActive())
		for (auto& c : components) c->onRender(renderer);
}

void Entity::onClean() {
	for (auto& c : components) c->onClean();
}

bool Entity::isActive() const { return mActive; }
void Entity::destroy() { mActive = false; }
void Entity::active() { mActive = true; }
