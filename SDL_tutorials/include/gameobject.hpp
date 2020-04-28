/*
 * gameobject.hpp
 * Copyright (C) 2019 preetham <preetham@preetham-laptop>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include "game.hpp"

class GameObject
{
    public:
        GameObject(const char* texture_sheet, int x, int y);
        ~GameObject();

        void update();
        void render();
    
    private:
        int x_pos;
        int y_pos;

        SDL_Texture* object_texture;
        SDL_Rect source_rectangle, destination_rectangle;

};


#endif /* !GAMEOBJECT_HPP */
