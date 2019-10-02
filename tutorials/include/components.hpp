/*
 * components.hpp
 * Copyright (C) 2019 preetham <preetham@preetham-laptop>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include "ecs.hpp"

class PositionComponent : public Component
{
    public:
        int getX() { return x_pos; }
        int getY() { return y_pos; }

        void init() override
        {
            x_pos = 0;
            y_pos = 0;
        }

        void setPosition(int x, int y)
        {
            x_pos = x;
            y_pos = y;
        }

        void update() override
        {
            x_pos++;
            y_pos++;
        }

    private:
        int x_pos;
        int y_pos;


};

#endif /* !COMPONENTS_HPP */
