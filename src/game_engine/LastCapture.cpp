#include "Game.hpp"
#include <iostream>
#include <list>
#include <Position.hpp>
using namespace std;

bool    Game::_opponent_can_take_last_stones() {
    if (_player == FIRST_PLAYER && _sp_captures_count != 8)
        return false;
    if (_player == SECOND_PLAYER && _fp_captures_count != 8)
        return false;
    return _player_stones_vulnerable();
}

bool    Game::_player_stones_vulnerable() {
    list<Position>  lst = _fp_stones;

    if (_player == SECOND_PLAYER)
        lst = _sp_stones;
    for (const Position pos : lst)
    {
        //I'm trying to capture every "_player" precedent move
        _directional_vulnerability(1, 0, pos);
        _directional_vulnerability(0, 1, pos);
        _directional_vulnerability(1, 1, pos);
        _directional_vulnerability(1, -1, pos);
    }
    return !_mandatory_moves.empty();
}
