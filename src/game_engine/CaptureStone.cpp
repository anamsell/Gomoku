#include "Game.hpp"
#include "Constants.hpp"
using namespace std;

void    Game::_capture_stones(const list<Position>& captures)
{
    if (_player == FIRST_PLAYER)
        for (auto &pos : captures) {
            _fp_captures_count += 1;
            _sp_stones.remove(pos);
            _goban[pos.x][pos.y] = EMPTY_INTERSECTION;
        }
    else
        for (auto &pos : captures) {
            _sp_captures_count += 1;
            _fp_stones.remove(pos);
            _goban[pos.x][pos.y] = EMPTY_INTERSECTION;
        }
}


void    Game::_directional_capture(int dx, int dy, list<Position>& captures)
{
    Position    start;
    Position    cpy1;
    Position    cpy2;

    start = _new_move;
    start.move(dx,dy);
    start.set_value(_goban);
    if (start.value != _opp)
        return;
    cpy1 = start;
    start.move(dx,dy);
    start.set_value(_goban);
    if (start.value != _opp)
        return;
    cpy2 = start;
    start.move(dx,dy);
    start.set_value(_goban);
    if (start.value != _player)
        return;

    captures.push_back(cpy1);
    captures.push_back(cpy2);

}

bool    Game::_capture()
{
    list<Position>  captures;

    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (i || j)
                _directional_capture(i, j, captures);
    if (captures.empty())
        return false;
    _precedent_captured = captures;
    _capture_stones(captures);
    return true;
}