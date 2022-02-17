#include "Game.hpp"

bool    Game::_is_in_mandatory()
{
    for (const Position &n : _mandatory_moves)
        if (n.x == _new_move.x && n.y == _new_move.y)
            return true;
    return false;
}
