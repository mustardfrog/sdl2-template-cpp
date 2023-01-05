#include "Game.hpp"
#include "MovingBox.hpp"
#include "Shapes.hpp"
#include <cstdio>

Game::Game(){};
Game::~Game(){};

Box *box = new Box();

SDL_Renderer *Game::renderer = nullptr;

void Game::init() {

    // if (IMG_Init(IMG_INIT_PNG) == 0) {
    //     printf("failed to initialize png");
    // };

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("cannot start sdl");
    }

    m_Window = SDL_CreateWindow(
        "title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
        SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (m_Window == NULL) {
        printf("m_Window is null");
        m_IsRunning = false;
    }

    renderer = SDL_CreateRenderer(m_Window, -1, 0);

    if (renderer) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    if (renderer == NULL) {
        printf("renderer is null");
        m_IsRunning = false;
    }

    m_IsRunning = true;
}

void Game::handleEvent() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        m_IsRunning = false;
        break;

    default:
        break;
    }
}

void Game::update() { box->update(); }

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 10);
    SDL_RenderClear(renderer);

    // render shits here

    // draw circles from Shapes.hpp
    SDL_SetRenderDrawColor(renderer, 0, 100, 100, 10);
    SDL_RenderFillCircle(renderer, 80,80, 32);

    box->render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
