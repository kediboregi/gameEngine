#include "TextureLoader.h"
#include <iostream>

SDL_Texture* TextureLoader::LoadTexture(SDL_Renderer* renderer, std::string file) {
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(file.c_str());
    if( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", file, IMG_GetError());
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if( newTexture == NULL ) {
            printf( "Unable to create texture from %s! SDL Error: %s\n", file, SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

void TextureLoader::DestroyTexture(SDL_Texture* texture) {
    SDL_DestroyTexture(texture);
}
