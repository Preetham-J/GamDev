/*
 * gameobject.cpp
 * Copyright (C) 2019 preetham <preetham@preetham-laptop>
 *
 * Distributed under terms of the MIT license.
 */

#include "gameobject.hpp"
#include "texturemanager.hpp"

GameObject::GameObject(const char* texture_sheet, int x, int y)
{
    object_texture = TextureManager::loadTexture(texture_sheet);

    x_pos = x;
    y_pos = y;
}

GameObject::~GameObject()
{


}

void GameObject::update()
{
    x_pos++;
    y_pos++;    

    source_rectangle.h = 450;
    source_rectangle.w = 600;
    source_rectangle.x = 0;
    source_rectangle.y = 0;

    destination_rectangle.x = x_pos;
    destination_rectangle.y = y_pos;
    destination_rectangle.w = source_rectangle.w / 2;
    destination_rectangle.h = source_rectangle.h / 2;
}

void GameObject::render()
{
    SDL_RenderCopy(Game::renderer, object_texture, &source_rectangle, &destination_rectangle);
}

