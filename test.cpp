#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
using namespace std;

int main()
{
    bool quit = false;
    SDL_Event event;

    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        printf("Error: \n");
        return(-1);
    }

    SDL_Window *win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, SDL_WINDOW_RESIZABLE);
    if(!win)
    {
        printf("Failed to create window\n");
        return(-1);
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, 0);
    if(!renderer)
    {
        printf("Failed to create renderer\n");
        SDL_DestroyWindow(win);
    }

    while(!quit)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, 150, 150, 250 ,250);
        SDL_RenderPresent(renderer);
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    quit = true;
                break;

        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return(0);
}