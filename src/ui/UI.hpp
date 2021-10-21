#ifndef UI_HPP
#define UI_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "Constants.hpp"
#include <iostream>
#include <stdio.h>

class UI
{
    public:
    UI();       //Constructor
    
    void    init(const char *);
    void    handle_event();
    void    clean(int);
    void    render();
    bool    running(){return _is_running;}

    private:
    bool            _is_running;
    SDL_Window      *_win;
    SDL_Renderer    *_renderer;
    SDL_Surface     *_surface;
    SDL_Texture     *_texture;
    SDL_Rect        _rect;

};

#endif