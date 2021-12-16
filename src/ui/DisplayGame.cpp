#include "UI.hpp"
using namespace std;

void    UI::_display_goban() {
    SDL_Texture*    texture;
    SDL_Surface*    surface;

    surface = IMG_Load(GOBAN_IMG_PATH); // open image
    if (!surface)
        clean(EXIT_FAILURE);
    SDL_Rect rect = {0, 0, 770, 770};
    texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture)
        clean(EXIT_FAILURE);
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    _display_stones();
    _display_algo_play();
}

void    UI::_display_stones() {
    Position pos;
    for (size_t x = 0; x < GOBAN_SIZE; x++)
        for (size_t y = 0; y < GOBAN_SIZE; y++)
            {
                pos.redefine(x, y);
                if (!pos.is_empty_on(_game->get_goban()))
                    _display_stone(pos);
            }
}

void    UI::_display_stone(Position pos, bool algo_play)
{
    SDL_Texture *texture;
    SDL_Surface *surface;
    if(algo_play == true)
        surface = IMG_Load(GREEN_CIRCLE_IMG_PATH);
    else if (pos.is_white_on(_game->get_goban()))
        surface = IMG_Load(WHITE_STONE_IMG_PATH);
    else
        surface = IMG_Load(BLACK_STONE_IMG_PATH);
    SDL_Rect rect = {(pos.y * 40) + BOARDER_GOBAN - 12, (pos.x * 40) + BOARDER_GOBAN - 13, 24, 26};
    texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture)
        clean(EXIT_FAILURE);
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}

void    UI::_display_algo_play()
{
    Position    pos;

    pos = artificial_intelligence(*_game);
    _display_stone(pos, true);
}