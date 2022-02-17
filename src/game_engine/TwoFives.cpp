#include "Game.hpp"
using namespace std;

bool            Game::_are_unbreakables_five_stones(list<list<Position> > fives)
{
    list<Position>  central_stones;
    list<Position>  vulnerable_stone_first_five;
    list<Position>  vulnerable_stone_second_five;

    for (const auto &n : fives) // if one of 2 fives is a 9 stones // unbreakable, no need to go further.
        if (n.size() == 9)
            return true;
    
    central_stones = _find_central_stones();
    //looking for stones around the move that compose a five (it's those stones that make the 2 fives vulnerable)
    vulnerable_stone_first_five = _vulnerables_stones(fives.front(), central_stones);
    vulnerable_stone_second_five = _vulnerables_stones(fives.back(), central_stones);
    for (const auto &n : vulnerable_stone_first_five)
        for (const auto &p : vulnerable_stone_second_five)
            _move_capture_both(n, p);
    return _mandatory_moves.empty();
}

void            Game::_move_capture_both(Position n, Position p)
{
    int         dx;
    int         dy;
    Position    f_move;
    Position    s_move;

    dx = n.x - p.x;
    dy = n.y - p.y;
    f_move.move(dx + n.x, dy + n.y);
    s_move.move(p.x - dx, p.y - dy);
    f_move.set_value(_goban);
    s_move.set_value(_goban);
    if (f_move.value == _opp && s_move.value == EMPTY_INTERSECTION)
        _mandatory_moves.push_back(s_move);
    else if (s_move.value == _opp && f_move.value == EMPTY_INTERSECTION)
        _mandatory_moves.push_back(f_move);
}

list<Position>  Game::_vulnerables_stones(list<Position> five,list<Position> central_stones)
{
    size_t          size;
    int             i;
    list<Position>  central_stones_in_five;

    i = 0;
    size = five.size();
    for (const auto &p : five)
    {
        if (i == 5) // means there is 5 stones before this one, uselle to continue stones dont break the 5.
            break;
        if (i < size - 5) //make sure its gonna break the five incase there is more then five stones.
            continue;
        if (p.is_in_list(central_stones))
            central_stones_in_five.push_back(p);
        i++;
    }
    return central_stones_in_five;
}

list<Position>  Game::_find_central_stones()
{
    list<Position>  central_stones;             //the eight stones around the last move
    Position        new_central;

    for (int dx = -1; dx < 2; dx++)             //finding central_stones;
        for (int dy = -1; dy < 2; dy++)
            if (dx || dy)
            {
                new_central = _new_move;
                new_central.move(dx, dy);
                central_stones.push_back(new_central);
            }

    return central_stones;
}
