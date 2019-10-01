#include "game.hpp"


int main(int argc, const char* argv[])
{
    Game* game = nullptr;

    game = new Game();

    const int FPS = 60;
    const int frame_delay = 1000 / FPS;
    uint32_t frame_start;
    int frame_time;

    game->init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    while (game->running())
    {
        frame_start = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frame_time = SDL_GetTicks() - frame_start;

        if (frame_delay > frame_time)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }

    game->clean();
    return 0;
}
