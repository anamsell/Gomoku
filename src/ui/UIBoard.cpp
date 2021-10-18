/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UIBoard.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:42:28 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 12:45:44 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "UIBoard.hpp"

UIBoard::UIBoard(ui_board board)
{
    this->_board = board;
}
