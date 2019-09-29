#ifndef game_hpp
#define game_hpp
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Game
{
    public:
        Game();
        ~Game();
        void init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();
        bool running() { return is_running; }

    private:
        int count = 0;
        bool is_running;
        SDL_Window* window;
        SDL_Renderer* renderer;
};


#endif /* game_hpp */
