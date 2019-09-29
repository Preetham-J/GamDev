/*
 * texturemanager.hpp
 * Copyright (C) 2019 preetham <preetham@preetham-laptop>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "game.hpp"

class TextureManager
{
    public:
        static SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer); 
};


#endif /* !TEXTUREMANAGER_HPP */
