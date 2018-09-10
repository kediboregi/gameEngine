#include "TransformComponent.h"
#include "../Entity.h"

TransformComponent::TransformComponent() {
	//velocity.x = 1;
}

void TransformComponent::onUpdate(float deltaTime) {
	mPosition.x += mVelocity.x * deltaTime;
	mPosition.y += mVelocity.y * deltaTime;
}