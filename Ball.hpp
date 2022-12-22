#include <SDL2/SDL.h>

class Ball { 
    public:
        Ball();
        ~Ball();

        SDL_Rect ball;

        typedef struct Vector2
        {
            int x;
            int y;
        } Vector2;
        Vector2 ballSpeed;

        void update();
        void render(SDL_Renderer* renderer);
};
