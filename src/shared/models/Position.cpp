#include "Position.hpp"

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

Position    Position::zero()
{
    return {0, 0};
}

void    Position::redefine(int x, int y)
{
    this->x = x;
    this->y = y;
}

void    Position::move(int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}

bool        Position::is_on_the_map() const
{
    if  (this->x < 0 || this->y < 0)
        return false;
    if  (this->x >= GOBAN_SIZE || this->y >= GOBAN_SIZE)
        return false;
    return true;
}

void        Position::set_value(vector2d goban) {
    if (!this->is_on_the_map())
    {
        this->value = 0;
        return;
    }
    this->value = goban[this->x][this->y];
}



bool        Position::is_empty_on(vector2d goban) const
{
    return (goban[this->x][this->y] == EMPTY_INTERSECTION);
}

bool        Position::is_ally_on(vector2d goban, char player) const
{
    return (goban[this->x][this->y] == player);
}

bool        Position::is_enemy_on(vector2d goban, char player) const
{
    return (!(goban[this->x][this->y] == player || goban[this->x][this->y] == EMPTY_INTERSECTION));
}

bool        Position::is_in_list(const std::list<Position>& lst) const
{
    for(const auto &n : lst)
        if (this->x == n.x && this->y == n.y)
            return true;
    return false;
}

bool        Position::is_white_on(vector2d goban) const
{
    return goban[this->x][this->y] == SECOND_PLAYER;
}