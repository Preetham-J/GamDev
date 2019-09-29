#include "game.hpp"


int main(int argc, const char* argv[])
{
    Game* game = nullptr;

    game = new Game();

    game->init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}
