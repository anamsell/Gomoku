#include "Game.hpp"

bool    Game::_is_in_mandatory()
{
    for (const Position &n : _mandatory_moves)
        if (n.x == _move.x && n.y == _move.y)
        {
            _mandatory_moves.clear();
            return true;
        }
    return false;
}
