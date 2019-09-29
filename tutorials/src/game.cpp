#include "game.hpp"
#include "texturemanager.hpp"
#include "gameobject.hpp"
#include <iostream>

GameObject* player;
GameObject* enemy;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems initialized." << std::endl;

        window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
        if (window)
        {
            std::cout << "Window created." << std::endl;
        }
        
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created." << std::endl;
        }

        is_running = true;
    }
    else
    {
        is_running = false;
    }

    player = new GameObject("assets/player", renderer, 0, 0);
    enemy = new GameObject("assets/enemy", renderer, 150, 150);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            is_running = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    player->update();
    enemy->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);

    player->render();
    enemy->render();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}
