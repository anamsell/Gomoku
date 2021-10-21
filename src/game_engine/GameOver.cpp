#include "Game.hpp"
#include <iostream>
#include <list>
#include <Position.hpp>
using namespace std;

bool    Game::_is_game_over()
{
    if (_first_player_captures_count == 10)
        return true;
    if (_second_player_captures_count == 10)
        return true;
    return _unbreakable_five_stones();
}

bool    Game::_unbreakable_five_stones()
{
    list<list<Position> > fives;
 
    _directional_five(1, 0, fives);
    _directional_five(0, 1, fives);
    _directional_five(1, 1, fives);
    _directional_five(1, -1, fives);

    if (fives.size() >= 3)
        return true;
    if (fives.size() == 2)
        return _are_unbreakables_five_stones(fives);
    if (fives.size() == 1)
        return _is_unbreakable_five_stones(fives.front());
    return false;
}

void    Game::_directional_five(int dx, int dy, list<list<Position> > &fives)
{
    Position pos;
    list<Position> five;
    
    pos = _move.cpy();
    five.push_back(pos);
    for (int i = 0; i < 4; i++)
    {
        pos.move(dx, dy);
        if (pos.is_ally_on(_goban, _player))
            five.push_back(pos);
        else
            break;
    }
    pos = _move.cpy();
    for (int i = -4; i < 0; i++)
    {
        pos.move(-dx, -dy);
        if (pos.is_ally_on(_goban, _player))
            five.push_front(pos);
        else
            break;
    }
    if (five.size() >= 5)
        fives.push_back(five);
}
