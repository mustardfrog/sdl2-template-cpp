#include "Game.hpp"
#include "Ball.hpp"
#include <cstdio>

Game::Game(){};
Game::~Game(){};

Ball *ball = new Ball();

SDL_Renderer *Game::renderer = nullptr;

void Game::init() {

    // if (IMG_Init(IMG_INIT_PNG) == 0) {
    //     printf("failed to initialize png");
    // };

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("cannot start sdl");
    }

    window = SDL_CreateWindow(
        "title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
        SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (window == NULL) {
        printf("window is null");
        isRunning = false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    if (renderer == NULL) {
        printf("renderer is null");
        isRunning = false;
    }

    isRunning = true;
}

void Game::handleEvent() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }
}

void Game::update() { ball->update(); }

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 10);
    SDL_RenderClear(renderer);
    // render shits here

    ball->render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
