#include "MovingBox.hpp"
#include <SDL2/SDL_render.h>

// example file

Box::Box() {
    ball.h = 32.0f;
    ball.w = 32.0f;
    ball.x = 132.0f;
    ball.y = 132.0f;

    ballSpeed.x = 8.0f;
    ballSpeed.y = 8.0f;
};

Box::~Box(){};

void Box::update() {
    ball.x += ballSpeed.x;
    ball.y += ballSpeed.y;

    if (ball.x + 32 >= 800 || ball.x <= 0)
        ballSpeed.x *= -1;
    if (ball.y + 32 >= 600 || ball.y <= 0)
        ballSpeed.y *= -1;
}

void Box::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 10);
    SDL_RenderDrawRect(renderer, &ball);

    SDL_RenderFillRect(renderer, &ball);
}
