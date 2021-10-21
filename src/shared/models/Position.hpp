/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:23:55 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 14:22:02 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>
#include <vector>
#include <list>
#include "Constants.hpp"

struct Position
{
    int x;
    int y;

    Position(int x = 0, int y = 0);

    static Position zero();

    bool    is_in_the_map() const;

    void    redefine(int ,int );

    void    move(int, int);

    bool    is_empty_on(vector2d) const;

    bool    is_ally_on(vector2d, bool) const;

    bool    is_enemy_on(vector2d, bool) const;

    bool    is_in_list(std::list<Position>) const;

    Position cpy();
    
};

#endif
