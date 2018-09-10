#include "GameState.h"
#include "../App.h"
#include "../entity/Entity.h"
#include "../entity/component/TransformComponent.h"
#include "../entity/component/DrawComponent.h"

GameState::GameState(App& app) : State::State(app) {

}

void GameState::onInit() {
	mApp->assetManager->AddTexture("cCc", "kra.png");
	player = new Entity();
	player->addComponent<TransformComponent>();
	player->getComponent<TransformComponent>().mPosition = Vector2f(500,500);
	player->addComponent<DrawComponent>();
	player->getComponent<DrawComponent>().setTexture(mApp->assetManager->GetTexture("cCc"), 0.5);
	player->onInit();
}

void GameState::onEvent(SDL_Event event) {
	switch (event.type) {
		case SDL_KEYDOWN:
			if(event.key.keysym.sym == SDLK_UP) {
				player->getComponent<TransformComponent>().mVelocity.y = -1;
			}
			if(event.key.keysym.sym == SDLK_DOWN) {
				player->getComponent<TransformComponent>().mVelocity.y = 1;
			}
			if(event.key.keysym.sym == SDLK_LEFT) {
				player->getComponent<TransformComponent>().mVelocity.x = -1;
			}
			if(event.key.keysym.sym == SDLK_RIGHT) {
				player->getComponent<TransformComponent>().mVelocity.x = 1;
			}
		break;
		case SDL_KEYUP:
			if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN) {
				player->getComponent<TransformComponent>().mVelocity.y = 0;
			}
			if(event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT) {
				player->getComponent<TransformComponent>().mVelocity.x = 0;
			}
		break;
	}
}

void GameState::onUpdate() {
	player->onUpdate(mApp->deltaTime);
}

void GameState::onRender() {
	player->onRender(mApp->mRenderer);
}

void GameState::onClean() {
	mApp->assetManager->DelTexture("cCc");
	player->onClean();
}
