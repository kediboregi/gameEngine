#include "AssetManager.h"
#include "../App.h"

AssetManager::AssetManager(App& app) : mApp(&app) {

}

void AssetManager::AddTexture(std::string id, std::string path) {
	std::string respath = "..\\..\\..\\resources\\";
	std::string bpath = SDL_GetBasePath()+respath+path;
	textures.emplace(id, LoadTexture(mApp->mRenderer, bpath));
}

SDL_Texture* AssetManager::GetTexture(std::string id) {
	return textures[id];
}

void AssetManager::DelTexture(std::string id) {
	DestroyTexture(GetTexture(id));
	textures.erase(id);
}

/*void AssetManager::AddFont(std::string id, std::string path, int fontSize) {
	sf::Font _font;
	if (!_font.loadFromFile(path)){

	}
	fonts.emplace(id, _font);
}
sf::Font AssetManager::GetFont(std::string id) {
	return fonts[id];
}*/
