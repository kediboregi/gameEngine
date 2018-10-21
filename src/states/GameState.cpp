#include "GameState.h"
#include "../App.h"
#include "../entity/Entity.h"
#include "../entity/component/TransformComponent.h"
#include "../entity/component/DrawComponent.h"
#include "../entity/component/CameraComponent.h"

GameState::GameState(App& app) : State::State(app) {

}

void GameState::onInit() {
	world = new World();

	camera = new Entity();
	camera->addComponent<TransformComponent>();
	camera->getComponent<TransformComponent>().mPosition = Vector2f(0,0);
	camera->addComponent<CameraComponent>();
	camera->onInit();

	mApp->assetManager->AddTexture("cCc", "kra.png");
	player = new Entity();
	player->addComponent<TransformComponent>();
	player->getComponent<TransformComponent>().mPosition = Vector2f(0,0);
	player->addComponent<DrawComponent>();
	player->getComponent<DrawComponent>().setTexture(mApp->assetManager->GetTexture("cCc"), 0.5);

	Entity* ccc = new Entity();
	ccc->addComponent<TransformComponent>();
	ccc->getComponent<TransformComponent>().mPosition = Vector2f(50,50);
	ccc->addComponent<DrawComponent>();
	ccc->getComponent<DrawComponent>().setTexture(mApp->assetManager->GetTexture("cCc"), 0.5);

	world->addEntity(player);
	world->addEntity(ccc);
	world->onInit();
}

void GameState::onEvent(SDL_Event event) {
	switch (event.type) {
		case SDL_KEYDOWN:
			if(event.key.keysym.sym == SDLK_UP) {
				camera->getComponent<TransformComponent>().mVelocity.y = 1 * 100;
			}
			if(event.key.keysym.sym == SDLK_DOWN) {
				camera->getComponent<TransformComponent>().mVelocity.y = -1 * 100;
			}
			if(event.key.keysym.sym == SDLK_LEFT) {
				camera->getComponent<TransformComponent>().mVelocity.x = 1 * 100;
				//player->getComponent<TransformComponent>().mRotation -= 30;
			}
			if(event.key.keysym.sym == SDLK_RIGHT) {
				camera->getComponent<TransformComponent>().mVelocity.x = -1 * 100;
				//player->getComponent<TransformComponent>().mRotation += 30;
			}
			if(event.key.keysym.sym == SDLK_w) {
				player->getComponent<TransformComponent>().mVelocity.y = -1 * 100;
			}
			if(event.key.keysym.sym == SDLK_s) {
				player->getComponent<TransformComponent>().mVelocity.y = 1 * 100;
			}
			if(event.key.keysym.sym == SDLK_a) {
				player->getComponent<TransformComponent>().mVelocity.x = -1 * 100;
				//player->getComponent<TransformComponent>().mRotation -= 30;
			}
			if(event.key.keysym.sym == SDLK_d) {
				player->getComponent<TransformComponent>().mVelocity.x = 1 * 100;
				//player->getComponent<TransformComponent>().mRotation += 30;
			}
		break;
		case SDL_KEYUP:
			if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN) {
				camera->getComponent<TransformComponent>().mVelocity.y = 0;
			}
			if(event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT) {
				camera->getComponent<TransformComponent>().mVelocity.x = 0;
			}
			if(event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_s) {
				player->getComponent<TransformComponent>().mVelocity.y = 0;
			}
			if(event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d) {
				player->getComponent<TransformComponent>().mVelocity.x = 0;
			}
		break;
	}

	if (player->getComponent<TransformComponent>().mRotation < 90 && player->getComponent<TransformComponent>().mRotation > -90) {
		//player->getComponent<TransformComponent>().mVelocity.y = -10;
		//std::cout << player->getComponent<TransformComponent>().mRotation << std::endl;
	} else {
		//player->getComponent<TransformComponent>().mVelocity.y = 0;
		//std::cout << "d" << std::endl;
	}

}

void GameState::onUpdate() {
	//camera->getComponent<TransformComponent>().mVelocity.x = player->getComponent<TransformComponent>().mVelocity.x;
	//camera->getComponent<TransformComponent>().mVelocity.y = player->getComponent<TransformComponent>().mVelocity.y;
	world->onUpdate(mApp->deltaTime);

	//camera->getComponent<TransformComponent>().mPosition = player->getComponent<TransformComponent>().mPosition;
	camera->onUpdate(mApp->deltaTime);
	std::cout << "p " << player->getComponent<TransformComponent>().mPosition.x << " " << player->getComponent<TransformComponent>().mPosition.y << " / c " << camera->getComponent<TransformComponent>().mPosition.x << " " << camera->getComponent<TransformComponent>().mPosition.y << std::endl;
	//camera->onRender(mApp->mRenderer);
}

void GameState::onRender() {
	//camera->onRender(mApp->mRenderer);
	world->onRender(mApp->mRenderer);
}

void GameState::onClean() {
	mApp->assetManager->DelTexture("cCc");
	world->onClean();
	camera->onClean();
}
