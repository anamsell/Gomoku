#include "Game.hpp"
#include "Constants.hpp"
using namespace std;


void    Game::_capture_stone(Position pos)
{
    _captured_stones.push_back(pos);
    if (_player == 0)
        _first_player_captures_count += 1;
    else
        _second_player_captures_count += 1;
    _goban[pos.x][pos.y] = EMPTY_SQUARE;

}

void    Game::_directional_capture(int dx, int dy)
{
    Position    start;

    start = _move.cpy();

    start.move(dx,dy);
    if (start.is_in_the_map() == false || start.is_enemy_on(_goban, _player) == false)
        return;

    start.move(dx,dy);
    if (start.is_in_the_map() == false || start.is_enemy_on(_goban, _player) == false)
        return;

    start.move(dx,dy);
    if (start.is_in_the_map() == false || start.is_ally_on(_goban, _player) == false)
        return;
    
    start.move(-dx, -dy);
    _capture_stone(start);
    start.move(-dx, -dy);
    _capture_stone(start);

}

void    Game::_capture()
{
    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (i || j)
                _directional_capture(i, j);
}