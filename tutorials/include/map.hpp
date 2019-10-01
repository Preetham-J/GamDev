/*
 * map.hpp
 * Copyright (C) 2019 preetham <preetham@preetham-laptop>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef MAP_HPP
#define MAP_HPP
#include "game.hpp"

class Map
{
    public:
        Map();
        ~Map();

        void loadMap(int array[20][25]);
        void drawMap();


    private:

        SDL_Rect source, destination;
        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;

        int map[20][25];
};


#endif /* !MAP_HPP */
