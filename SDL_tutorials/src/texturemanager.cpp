/*
 * texture_manager.cpp
 * Copyright (C) 2019 preetham <preetham@preetham-laptop>
 *
 * Distributed under terms of the MIT license.
 */

#include "texturemanager.hpp"

SDL_Texture* TextureManager::loadTexture(const char* filename)
{
    SDL_Surface* temp_surface = IMG_Load(filename);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, temp_surface);
    SDL_FreeSurface(temp_surface);
    
    return texture;
} 

void TextureManager::draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination)
{
    SDL_RenderCopy(Game::renderer, texture, &source, &destination);
}
