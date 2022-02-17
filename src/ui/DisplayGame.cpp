#include "UI.hpp"
#include "../ai/AI.hpp"

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
    SDL_RenderCopy(_renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
    _display_stones();
    if (!_game.is_over() && !(vs_ia && _game.get_player() == SECOND_PLAYER))
        _display_algo_play();

}

void    UI::_display_stones() {

    for (auto &pos : _game.get_fp_stones())
        _display_stone(pos, _surface_black);
    for (auto &pos : _game.get_sp_stones())
        _display_stone(pos, _surface_white);
}

void    UI::_display_stone(Position pos, SDL_Surface *surface)
{
    SDL_Texture *texture;

    SDL_Rect rect = {(pos.y * 40) + BOARDER_GOBAN - 12, (pos.x * 40) + BOARDER_GOBAN - 13, 24, 26};
    texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if (!texture)
        clean(EXIT_FAILURE);
    SDL_RenderCopy(_renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}

void    UI::_display_algo_play()
{
    Position    pos(9,9);

    if (_game.get_turn()) {
        if (!_game.new_move_is_valid())
            pos = _last_algo_play;
        else
            pos = artificial_intelligence(_game);
    }
    _last_algo_play = pos;
    _display_stone(pos, _surface_algo);
}