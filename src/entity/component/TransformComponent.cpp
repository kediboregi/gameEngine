#include "TransformComponent.h"
#include "../Entity.h"

TransformComponent::TransformComponent() {

}

void TransformComponent::onInit() {

}

void TransformComponent::onUpdate(float deltaTime) {
	//mPosition.x += mVelocity.x * deltaTime;
	//mPosition.y += mVelocity.y * deltaTime;

	float rot = mRotation * M_PI / 180;
	mPosition.x += (mVelocity.x * cos(rot) - mVelocity.y * sin(rot)) * deltaTime;
	mPosition.y += (mVelocity.x * sin(rot) + mVelocity.y * cos(rot)) * deltaTime;
}
