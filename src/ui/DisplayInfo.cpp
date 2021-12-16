#include "UI.hpp"
using namespace std;


void    UI::_display_info(int first_turn)
{
    _display_player();
    if (!first_turn)
    {
        _display_stone_counts();
        _display_timers();
    }
    if (!_game->new_move_is_valid())
        _display_move_error();
    if(_game->is_over())
    {
        if (_game->is_tie())
            _display_tie();
        else
            _display_winner();
    }
}

void    UI::_display_player()
{
    SDL_Rect    rect = {780, 100};
    string      msg = "Player 1 (black)";
    SDL_Color   white = {255, 255, 255, 255};

    if (_game->get_player() == 0 && _game->is_over() == 0)
        msg += "            (turn to play)";
    _write(25, msg, rect, white);

    rect = {780, 300};
    if (vs_ia == true)
        msg = "IA (white)";
    else
        msg = "Player 2 (white)";
    if (_game->get_player() == 1 && _game->is_over() == 0)
        msg += "            (turn to play)";
    _write(25, msg, rect, white);
}

void    UI::_display_winner()
{
    SDL_Rect    rect = {880, 20};
    string      msg;
    SDL_Color   green = {0, 255, 0, 255};

    if (_game->get_player() == 1)
        msg = "PLAYER 1 WIN";
    else
        msg = "PLAYER 2 WIN";
    _write(30, msg, rect, green);
}

void    UI::_display_tie()
{
    SDL_Rect    rect = {880, 20};
    string      msg = "TIE";
    SDL_Color   orange = {255, 127, 0, 255};

    _write(30, msg, rect, orange);
}

void    UI::_display_move_error()
{
    SDL_Rect    rect = {780, 500};
    string      msg = _game->get_error_code();
    SDL_Color   red = {255, 0, 0, 255};

    _write(23, msg, rect, red);
}

void    UI::_display_stone_counts()
{
    SDL_Rect    rect = {800, 160};
    string      msg = "Stones captured : " + to_string(_game->get_first_player_capture_count());
    SDL_Color   white = {255, 255, 255, 255};
    _write(20, msg, rect, white);

    rect = {800, 360};
    msg = "Stones captured : " + to_string(_game->get_second_player_capture_count());
    _write(20, msg, rect, white);
}

void    UI::_display_timers()
{
    SDL_Rect    rect;
    string      msg;
    SDL_Color   white = {255, 255, 255, 255};
    chrono::milliseconds   timer_last_move;
    auto        time_now = chrono::duration_cast< chrono::milliseconds >(chrono::system_clock::now().time_since_epoch());

    timer_last_move = (time_now - _timer); // get the timer since last move in chrono::milliseconds
    string timer = to_string((float)timer_last_move.count()/1000); // convert milliseconds to float to string
    timer = timer.substr(0, timer.length() - 3); // remove the 3 last 0
    if (_game->new_move_is_valid())
    {
        if (_game->get_player() == 1)
            _last_p1_timer = timer;
        else
            _last_p2_timer = timer;
    }

    rect = {800, 200};
    msg = "Time for last move (in sec) : " + _last_p1_timer ;
    _write(20, msg, rect, white);

    rect = {800, 400};
    msg = "Time for last move (in sec) : " + _last_p2_timer;
    _write(20, msg, rect, white);
}


void    UI::_write(int ptsize, string msg, SDL_Rect rect, SDL_Color color)
{
    TTF_Font*       font  = TTF_OpenFont("ressources/Arial.ttf", ptsize);
    SDL_Texture*    texture;
    SDL_Surface*    surface;

    if (!font)
        clean(EXIT_FAILURE);
    surface = TTF_RenderText_Solid(font, msg.c_str(), color);
    TTF_CloseFont(font);
    if (!surface)
        clean(EXIT_FAILURE);
    texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture)
        clean(EXIT_FAILURE);
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}