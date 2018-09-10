#ifndef _TransformComponent_H_
    #define _TransformComponent_H_
	
#include "Component.h"
#include "../../math/Vector2.h"

class TransformComponent : public Component {
private:

	Vector2f mOrigin;

	float mRotation;
	Vector2f mScale;

	int scale = 1;

	bool blocked = false;
	
public:
	Vector2f mPosition;
	Vector2f mVelocity;
	
public:
	TransformComponent();
	void onUpdate(float deltaTime) override;
};
#endif