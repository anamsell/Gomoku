#include "Game.hpp"
#include "Constants.hpp"
#include "Position.hpp"
#include <iostream>
#include <vector>
using namespace std;

static  bool free_three(vector2d goban, Position pos, bool player, int dx, int dy)
{
    Position    end;
    short       stone_count = 0;

    end = pos.cpy();
    end.move(dx * 5, dy * 5);
    //pattern for free three : EXXXXE with E = empty and X is 2 ally and 2 empty
    if (pos.is_in_the_map() == false || pos.is_empty_on(goban) == false)
        return false;
    if (end.is_in_the_map() == false || end.is_empty_on(goban) == false)
        return false;
    for (int i = 0; i < 4; i++)
    {
        pos.move(dx, dy);
        if (pos.is_enemy_on(goban, player))
            return false;
        stone_count += pos.is_ally_on(goban, player);
    }
    return stone_count == 2;
}

static  bool directional_three(vector2d goban, Position pos, bool player, int dx, int dy)
{
    // searching for all the possible free_three create on this direction with the new stone
    pos.move(dx * -4, dy * -4);
    
    for (int i = -4; i < 0; i++)
    {
        if  (free_three(goban, pos, player, dx, dy))
            return true;
        pos.move(dx, dy);
    }

    return false;
}

bool    Game::_double_three()
{
    int     three_count = 0;
    // 4 direciton possible horizontal, vertical, and 2 diagonals
    three_count += directional_three(get_goban(), get_move(), get_player(), 1, 0);
    three_count += directional_three(get_goban(), get_move(), get_player(), 0, 1);
    three_count += directional_three(get_goban(), get_move(), get_player(), 1, 1);
    three_count += directional_three(get_goban(), get_move(), get_player(), -1, 1);
    // if it create at least 2 free_three on different directon : double three
    if (three_count >=2)
        return true;
    return false;
}
