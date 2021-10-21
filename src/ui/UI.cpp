#include "UI.hpp"
using namespace std;

//constructor

UI::UI()  : _is_running(true), _win(NULL), _renderer(NULL), _texture(NULL)
{
    _rect = {0, 138, 630, 630};
}


void    UI::init(const char *title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        _win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, 0);
        if (!_win)
            clean(EXIT_FAILURE);
        _renderer = SDL_CreateRenderer(_win, -1, 0);
        if (!_renderer)
            clean(EXIT_FAILURE);
        _surface = IMG_Load(GOBAN_IMG_PATH);
        if (!_surface)
            clean(EXIT_FAILURE);
        _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
        SDL_FreeSurface(_surface);
        if (!_texture)
            clean(EXIT_FAILURE);
        SDL_RenderCopy(_renderer, _texture, NULL, &_rect);
        SDL_RenderPresent(_renderer);
    }
    else
        _is_running = false;
}

void    UI::handle_event()
{
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            _is_running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                _is_running = false;
            break;
    }

}

void    UI::render()
{
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer); 
}

void    UI::clean(int error_code)
{
    if (_texture)
        SDL_DestroyTexture(_texture);
    if (_renderer)
        SDL_DestroyRenderer(_renderer);
    if (_win)
        SDL_DestroyWindow(_win);
    SDL_Quit();
    exit(error_code);
}
