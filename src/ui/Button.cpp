//
// Created by Anthony Amsellem on 05/11/2021.
//

#include "Button.hpp"

using namespace std;

Button::Button(string text, SDL_Rect rect, SDL_Renderer* renderer, SDL_Window* win)
{
    activate = 0;
    _text = text;
    _rect = rect;
    _renderer = renderer;
    _win = win;
}

void    Button::_display_button()
{
    SDL_Color   white = {255, 255, 255, 255};

    _write(20, white);
}

void    Button::_write(int ptsize, SDL_Color color)
{
    TTF_Font*       font  = TTF_OpenFont("resources/Arial.ttf", ptsize);
    SDL_Texture*    texture;
    SDL_Surface*    surface;

    if (!font)
        _clean(EXIT_FAILURE);
    surface = TTF_RenderText_Solid(font, _text.c_str(), color);
    TTF_CloseFont(font);
    if (!surface)
        _clean(EXIT_FAILURE);
    texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture)
        _clean(EXIT_FAILURE);
    SDL_QueryTexture(texture, NULL, NULL, &_rect.w, &_rect.h);
    SDL_RenderCopy(_renderer, texture, NULL, &_rect);
    SDL_DestroyTexture(texture);
}

void    Button::_clean(int error_code)
{
    if (_renderer)
        SDL_DestroyRenderer(_renderer);
    if (_win)
        SDL_DestroyWindow(_win);
    SDL_Quit();
    if (error_code == EXIT_FAILURE)
        printf("ERROR FAIL TO USE SDL PROPERLY.");
    exit(error_code);
}
