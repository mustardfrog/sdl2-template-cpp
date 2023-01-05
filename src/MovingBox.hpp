#pragma once
#include <SDL2/SDL.h>

// example file
class Box {

  public:
    Box();
    ~Box();


    typedef struct Vector2 {
        float x;
        float y;
    } Vector2;

    Vector2 ballSpeed;

    void update();
    void render(SDL_Renderer *renderer);

  private:
    SDL_Rect ball;
};
