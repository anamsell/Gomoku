#include "UI.hpp"
using namespace std;

bool    UI::_is_on_goban(SDL_MouseButtonEvent &event)
{
    int         x;
    int         y;
    Position    pos;

    x = event.x - BOARDER_GOBAN; // removing the boarder of the goban
    y = event.y - BOARDER_GOBAN; 

    if (x > (720 + ERROR_MARGIN) || y > (720 + ERROR_MARGIN))
        return false;
    if ((x % 40) < ERROR_MARGIN || (x % 40) > (40 - ERROR_MARGIN))
        if ((y % 40) < ERROR_MARGIN || (y % 40) > (40 - ERROR_MARGIN))
            {
                pos.redefine((int)round((float)y/40), (int)round((float)x/40));
                _game->new_move(pos);
                _refresh_render(0);
                if (vs_ia == true && _game->get_player() == 1)
                {
                    _game->new_move(artificial_intelligence(*_game));
                    if(_game->new_move_is_valid() == false)
                        clean(0);
                    _refresh_render(0);
                }
            }
    return true;
}

void    UI::_click(SDL_MouseButtonEvent &event)
{
    if(!_game->is_over())
        _is_on_goban(event);

}