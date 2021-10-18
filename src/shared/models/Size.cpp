/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:20:36 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 14:21:45 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Size.hpp"

Size::Size(int width, int height)
{
    this->width = width;
    this->height = height;
}

Size Size::zero()
{
    return Size(0, 0);
}
