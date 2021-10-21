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
    }
    return _mandatory_moves.size() == 0;
}

void    Game::_vulnerable(Position pos)
{
    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (i || j)
                _directional_vulnerability(i, j, pos);
}

void    Game::_directional_vulnerability(int dx, int dy, Position pos)
{
        pos.move(-dx, -dy); //if previous one is an ennemy
        if (pos.is_enemy_on(_goban, _player) == false)
            return;
        pos.move(2*dx,2*dy); // if next one is an ally
        if (pos.is_ally_on(_goban, _player) == false)
            return;
        pos.move(dx,dy); // if the one after is empty ==  the 5 is vulnerable + actual pos is a mandatory next move for opp ( example:  WBB0)
        if (pos.is_empty_on(_goban) == true)
            _mandatory_moves.push_back(pos);

}