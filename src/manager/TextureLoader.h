#ifndef _TextureLoader_H_
    #define _TextureLoader_H_
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class TextureLoader {
public:
	SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string file);
	void DestroyTexture(SDL_Texture* texture);
};

#endif
