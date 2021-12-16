/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:02:24 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 14:08:45 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Position.hpp"

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

Position    Position::zero()
{
    return Position(0, 0);
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

Position Position::cpy()
{
    Position pos;

    pos.x = this->x;
    pos.y = this->y;
    return pos;
}

bool        Position::is_in_the_map() const
{
    if  (this->x < 0 || this->y < 0)
        return false;
    if  (this->x >= GOBAN_SIZE || this->y >= GOBAN_SIZE)
        return false;
    return true;
}

bool        Position::is_empty_on(vector2d goban) const
{
    if (this->is_in_the_map() == false)
        return false;
    if (goban[this->x][this->y] == EMPTY_INTERSECTION)
        return true;
    return false;
}

bool        Position::is_ally_on(vector2d goban, bool player) const
{
    if  (this->is_in_the_map() == false)
        return false;
    if (goban[this->x][this->y] == FIRST_PLAYER && player == 0)
        return true;
    if (goban[this->x][this->y] == SECOND_PLAYER && player == 1)
        return true;
    return false;
}

bool        Position::is_enemy_on(vector2d goban, bool player) const
{
    if  (this->is_in_the_map() == false)
        return false;
    if (goban[this->x][this->y] == FIRST_PLAYER && player == 1)
        return true;
    if (goban[this->x][this->y] == SECOND_PLAYER && player == 0)
        return true;
    return false;
}

bool        Position::is_in_list(std::list<Position> lst) const
{
    for(const auto &n : lst)
        if (this->x == n.x && this->y == n.y)
            return true;
    return false;
}

bool        Position::is_white_on(vector2d goban) const
{
    if  (this->is_in_the_map() == false)
        return false;
    return goban[this->x][this->y] == SECOND_PLAYER;
}