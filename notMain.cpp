
// Minimal SDL setup 

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main (int argc, char *argv[])
{

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool quit = false;

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
        printf("m_Window is null");
        quit = true;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    if (renderer == NULL) {
        printf("renderer is null");
        quit = true;
    }

    quit = false;

    while (!quit) {

        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;

            default:
                break;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 10);
        SDL_RenderClear(renderer);

        // Renderering commandns go in here


        // SDL_SetRenderDrawColor(renderer, 0, 100, 100, 10);
        SDL_RenderPresent(renderer);
    
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    return 0;
}
