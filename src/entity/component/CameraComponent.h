#ifndef _CameraComponent_H_
    #define _CameraComponent_H_

#include "Component.h"
#include <string>

class TransformComponent;
class CameraComponent : public Component {
private:
	SDL_Rect viewport;
	TransformComponent* transform;

public:
	CameraComponent();

	void onInit() override;
	void onUpdate(float deltaTime) override;
	void onRender(SDL_Renderer* renderer) override;
	void onClean() override;
};

#endif
