#include "CameraComponent.h"
#include "TransformComponent.h"
#include "../Entity.h"

CameraComponent::CameraComponent() {
	//SDL_GetWindowSize(SDL_Window* window, int* viewport.w, int* viewport.h);
}

void CameraComponent::onInit() {
	transform = &mEntity->getComponent<TransformComponent>();
	//viewport.w = 1024;
	//viewport.h = 768;
	//viewport.x = -1 * transform->mPosition.x + viewport.w/2;
	//viewport.y = -1 * transform->mPosition.y + viewport.h/2;
}

void CameraComponent::onUpdate(float deltaTime) {
	viewport.x = transform->mPosition.x;
	viewport.y = transform->mPosition.y;
	viewport.w = -transform->mPosition.x + 400;
	viewport.h = -transform->mPosition.y + 400;
}

void CameraComponent::onRender(SDL_Renderer* renderer) {
	SDL_RenderSetViewport(renderer, &viewport);
}

void CameraComponent::onClean() {

}
