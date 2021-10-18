/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:21:54 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 14:25:02 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Frame.hpp"

Frame::Frame(Position position, Size size)
{
    this->position = position;
    this->size = size;
}

Frame Frame::zero()
{
    return Frame(Position::zero(), Size::zero());
}
