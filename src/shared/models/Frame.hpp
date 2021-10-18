/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:19:35 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 14:24:20 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_HPP
#define FRAME_HPP

#include "Position.hpp"
#include "Size.hpp"

struct Frame
{
    Position position = Position::zero();
    Size size = Size::zero();

    Frame(Position position, Size size);

    static Frame zero();
};

#endif
