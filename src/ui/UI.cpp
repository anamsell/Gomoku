#include "UI.hpp"
using namespace std;

//constructor

UI::UI()  : _win(nullptr), _renderer(nullptr), _last_p1_timer("0.000"), _last_p2_timer("0.000"),
            _timer(NULL), vs_ia(false),_surface_black(IMG_Load(BLACK_STONE_IMG_PATH)),
            _surface_white(IMG_Load(WHITE_STONE_IMG_PATH)), _surface_algo(IMG_Load(GREEN_CIRCLE_IMG_PATH))
{
}

void    UI::init(const char *title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0 && TTF_Init() == 0)
    {
        _win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, 0);
        if (!_win)
            clean(EXIT_FAILURE);
        _renderer = SDL_CreateRenderer(_win, -1, 0);
        if (!_renderer)
            clean(EXIT_FAILURE);
        _refresh_render(1);
    }
    else {
        clean(EXIT_FAILURE);
    }
}

void    UI::_refresh_render(int first_turn) {
    SDL_RenderClear(_renderer);
//    if (_game->is_over())
//        Button
    _display_goban();
    _display_info(first_turn);
    SDL_RenderPresent(_renderer);
    if (_game.new_move_is_valid())
        _reset_timer();
}

void    UI::handle_event()
{
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            clean(EXIT_SUCCESS);
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                clean(EXIT_SUCCESS);
            break;
        case SDL_MOUSEBUTTONDOWN:
            _click(event.button);
    }

}

void    UI::_reset_timer()
{
    if (_game.new_move_is_valid())
    {
        _timer = chrono::duration_cast< chrono::milliseconds >(chrono::system_clock::now().time_since_epoch());
    }
}

void    UI::clean(int error_code)
{
    SDL_FreeSurface(_surface_black);
    SDL_FreeSurface(_surface_white);
    SDL_FreeSurface(_surface_algo);
    if (_renderer)
        SDL_DestroyRenderer(_renderer);
    if (_win)
        SDL_DestroyWindow(_win);
    SDL_Quit();
    if (error_code == EXIT_FAILURE)
        printf("ERROR FAIL TO USE SDL PROPERLY.");
    exit(error_code);
}
