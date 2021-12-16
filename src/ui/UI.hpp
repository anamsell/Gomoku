#ifndef UI_HPP
#define UI_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_events.h>
#include "Constants.hpp"
#include "Position.hpp"
#include "Game.hpp"
#include "Button.hpp"
#include "AI.hpp"
#include <chrono>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sys/time.h>


class UI {
public:
    UI();       //Constructor
    
    void    init(const char *);
    void    handle_event();
    void    clean(int);
    bool    vs_ia;

    private:

    //display info
    void    _display_info(int);
    void    _display_player();
    void    _display_stone_counts();
    void    _display_timers();
    void    _display_move_error();
    void    _write(int text_size, std::string msg, SDL_Rect, SDL_Color);

    //display game result
    void    _display_tie();
    void    _display_winner();

    //display game
    void    _display_goban();
    void    _display_stones();
    void    _display_stone(Position, bool = false);
    void    _display_algo_play();


    //on event
    void    _refresh_render(int);

    //click
    void    _click(SDL_MouseButtonEvent &);
    bool    _is_on_goban(SDL_MouseButtonEvent &);

    //reset timer
    void    _reset_timer();

    //SLD window and renderer
    SDL_Window      *_win;
    SDL_Renderer    *_renderer;

    // info player timer
    std::chrono::milliseconds  _timer;
    std::string                _last_p1_timer;
    std::string                _last_p2_timer;

    //Game engine class
    Game        *_game;

    // Buttons
//    Button      *_new_game;
//    Button      *_previous_move;

};

#endif