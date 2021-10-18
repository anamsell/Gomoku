/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UIView.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:01:00 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 14:40:01 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "UIView.hpp"

void UIView::moveToOrigin()
{
    move(this->frame.position.x, this->frame.position.y);
}

void UIView::clean()
{
    // for (int x = 0; i < size().width; i++)
    // {
    //     for (size_t i = 0; i < count; i++)
    //     {
    //         /* code */
    //     }
    //     }
}

void UIView::prepareForRender()
{
    move(this->frame.position.x, this->frame.position.y);
}

void UIView::render()
{
    refresh();
}

Position UIView::position()
{
    return frame.position;
}

Size UIView::size()
{
    return frame.size;
}
