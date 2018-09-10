#include "DrawComponent.h"
#include "TransformComponent.h"
#include "../Entity.h"

DrawComponent::DrawComponent() {
	srcrect.x = 0;
	srcrect.y = 0;
	dstrect.x = 0;
	dstrect.y = 0;
	
}
DrawComponent::DrawComponent(SDL_Texture* texture, float scale) {
	setTexture(texture, 1);
	srcrect.x = 0;
	srcrect.y = 0;
	dstrect.x = 0;
	dstrect.y = 0;
	
}
void DrawComponent::onInit() {
	transform = &mEntity->getComponent<TransformComponent>();
}

void DrawComponent::onUpdate(float deltaTime) {
	dstrect.x = transform->mPosition.x;
	dstrect.y = transform->mPosition.y;
}

void DrawComponent::onRender(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, mTexture, &srcrect, &dstrect);
}

void DrawComponent::onClean() {
	
}

void DrawComponent::setTexture(SDL_Texture* texture, float scale) {
	mTexture = texture;
	SDL_QueryTexture(mTexture, NULL, NULL, &srcrect.w, &srcrect.h);
	dstrect.w = srcrect.w * scale;
	dstrect.h = srcrect.h * scale;

}