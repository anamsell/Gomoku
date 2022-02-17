#include "Game.hpp"
using namespace std;

bool    Game::_is_unbreakable_five_stones(list<Position> five)
{
    int     i;

    i = 0;
    for (const Position &n : five)
    {
        if (i >= (five.size() - 5))
            _vulnerable(n);
        i++;
        if (i == 5)
            break;
    }
    return _mandatory_moves.empty();
}

void    Game::_vulnerable(Position pos)
{
    _directional_vulnerability(1, 0, pos);
    _directional_vulnerability(0, 1, pos);
    _directional_vulnerability(1, 1, pos);
    _directional_vulnerability(1, -1, pos);
}

void    Game::_directional_vulnerability(int dx, int dy, Position pos)
{
    Position    forward = pos;
    Position    backward = pos;

    forward.move(dx,dy);
    backward.move(-dx,-dy);
    forward.set_value(_goban);
    backward.set_value(_goban);
    if (forward.value != _player && backward.value != _player) // to be vulnerable a stone must have a nearby ally
        return;
    if (forward.value == EMPTY_INTERSECTION) { // Means we are in: WBBE with B player W opp and E empty or not vulnerable
        backward.move(-dx, -dy);
        backward.set_value(_goban);
        if (backward.value == _opp)
            _mandatory_moves.push_back(forward);
        return;
    }
    if (backward.value == EMPTY_INTERSECTION) { // Means we are in: EBBW with B player W opp and E empty or not vulnerable
        forward.move(dx, dy);
        forward.set_value(_goban);
        if (forward.value == _opp)
            _mandatory_moves.push_back(backward);
        return;
    }
    if (forward.value == _opp) { // Means we are in: WBBE with B player W opp and E empty or not vulnerable
        backward.move(-dx, -dy);
        backward.set_value(_goban);
        if (backward.value == EMPTY_INTERSECTION)
            _mandatory_moves.push_back(backward);
        return;
    }
    if (backward.value == _opp) { // Means we are in: EBBW with B player W opp and E empty or not vulnerable
        forward.move(dx, dy);
        forward.set_value(_goban);
        if (forward.value == EMPTY_INTERSECTION)
            _mandatory_moves.push_back(forward);
        return;
    }

}