//
// Created by Anthony Amsellem on 05/11/2021.
//

#ifndef BUTTONS_H
#define BUTTONS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_events.h>
#include <stdio.h>
#include <iostream>

class Button {

public:
    Button(std::string text, SDL_Rect rect, SDL_Renderer *renderer, SDL_Window* win); //Constructor

    bool            activate;
private:

    std::string     _text;
    SDL_Rect        _rect;
    SDL_Renderer*   _renderer;
    SDL_Window*     _win;

    void    _write(int ptsize, SDL_Color color);
    void    _clean(int error_code);
    void    _display_button();
};


#endif
