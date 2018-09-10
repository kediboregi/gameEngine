#ifndef _AssetManager_H_
    #define _AssetManager_H_

#include "TextureLoader.h"

#include <map>

class App;

class AssetManager : public TextureLoader
{
private:
	std::map<std::string, SDL_Texture*> textures;
	//std::map<std::string, sf::Font> fonts;

protected:
	App* mApp;

public:
	AssetManager(App& app);

	void AddTexture(std::string id, std::string path);
	SDL_Texture* GetTexture(std::string id);
	void DelTexture(std::string id);

	//void AddFont(std::string id, std::string path, int fontSize);
	//sf::Font GetFont(std::string id);
};

#endif
