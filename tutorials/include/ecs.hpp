/*
 * ecs.hpp
 * Copyright (C) 2019 preetham <preetham@preetham-laptop>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef ECS_HPP
#define ECS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
    static ComponentID last_ID = 0;
    return last_ID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID type_ID = getComponentTypeID();
    return type_ID;
}

constexpr std::size_t max_components = 32;

// Allows us to determine components for an entity
using ComponentBitSet = std::bitset<max_components>;

// ARray of components mapped to their maximum number of components
using ComponentArray = std::array<Component*, max_components>;

class Component
{
    public:
        Entity* entity;
        virtual void init() {}
        virtual void update() {}
        virtual void draw() {}
        virtual ~Component() {}
};

class Entity
{
    public:
        void update()
        {
            for (auto& c : components)
            {
                c->update();
            }
            for (auto& c : components)
            {
                c->draw();
            }
        }

        void draw()
        {

        }

        bool isActive() const
        {
            return active;
        }

        void destroy()
        {
            active = false;
        }

        template <typename T> bool hasComponent() const
        {
            return component_bitset[getComponentTypeID<T>()];

        }

        template <typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs)
        {
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->entity = this;
            std::unique_ptr<Component> uPtr{ c };
            components.emplace_back(std::move(uPtr));

            component_array[getComponentTypeID<T>()] = c;
            component_bitset[getComponentTypeID<T>()] = true;

            c->init();
            return *c;
        }

        template <typename T> T& getComponent() const
        {
            auto ptr(component_array[getComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }

    private:
        bool active = true;
        std::vector<std::unique_ptr<Component>> components;
        ComponentArray component_array;
        ComponentBitSet component_bitset;
};


class Manager
{
    public:
        void update()
        {
            for (auto& e : entities)
            {
                e->update();
            }
        }

        void draw()
        {
            for (auto& e : entities)
            {
                e->draw();
            }
        }

        void refresh()
        {
            entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                [](const std::unique_ptr<Entity> &mEntity)
                {
                    return !mEntity->isActive();
                }), std::end(entities));
        }

        Entity& addEntity()
        {
            Entity* e = new Entity();
            std::unique_ptr<Entity> uPtr{ e };

            entities.emplace_back(std::move(uPtr));
            return *e;
        }

    private:
        std::vector<std::unique_ptr<Entity>> entities;
};



#endif /* !ECS_HPP */
