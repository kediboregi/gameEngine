#ifndef _DrawComponent_H_
    #define _DrawComponent_H_
	
#include "Component.h"
#include <string>

class TransformComponent;
class DrawComponent : public Component {
private:
	SDL_Rect srcrect, dstrect;
	SDL_Texture* mTexture;
	TransformComponent* transform;
	
public:
	DrawComponent();
	DrawComponent(SDL_Texture* texture, float scale);
	
	void onInit() override;
	void onUpdate(float deltaTime) override;
	void onRender(SDL_Renderer* renderer) override;
	void onClean() override;
		
	void setTexture(SDL_Texture* texture, float scale);
};

#endif