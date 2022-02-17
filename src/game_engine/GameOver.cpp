#include "Game.hpp"
#include <list>
#include <Position.hpp>
using namespace std;

bool    Game::_is_game_over()
{
    if (_is_game_tie())
        return true;
    if (_fp_captures_count == 10)
        return true;
    if (_sp_captures_count == 10)
        return true;
    return _unbreakable_five_stones();
}


bool Game::_is_game_tie()
{
    for (const auto& n : _goban)
        for (const auto square : n)
            if (square == EMPTY_INTERSECTION)
                return false;
    _game_tie = true;
    return true;
}



bool    Game::_unbreakable_five_stones() {
    list<list<Position> > fives;
 
    _directional_five(1, 0, fives);
    _directional_five(0, 1, fives);
    _directional_five(1, 1, fives);
    _directional_five(1, -1, fives);
    if (fives.empty())
        return false;
    if (_opponent_can_take_last_stones())
        return false;
    if (fives.size() == 2)
        return _are_unbreakables_five_stones(fives);
    if (fives.size() == 1)
        return _is_unbreakable_five_stones(fives.front());
    return true;
}

void    Game::_directional_five(int dx, int dy, list<list<Position> > &fives) {
    Position pos;
    list<Position> five;
    
    pos = _new_move;
    five.push_back(pos);
    for (int i = 0; i < 4; i++)
    {
        pos.move(dx, dy);
        pos.set_value(get_goban());
        if (pos.value == _player)
            five.push_back(pos);
        else
            break;
    }
    pos = _new_move;
    for (int i = 0; i < 4; i++)
    {
        pos.move(-dx, -dy);
        pos.set_value(get_goban());
        if (pos.value == _player)
            five.push_back(pos);
        else
            break;
    }
    if (five.size() >= 5)
        fives.push_back(five);
}
