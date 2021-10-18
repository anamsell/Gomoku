/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:55:26 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 12:39:41 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "UI.hpp"

UI *UI::_shared = nullptr;

UI::UI()
{
    initscr();
    printw("Hello World");
    refresh();
    getch();
    endwin();
}

UI *UI::shared()
{
    if (_shared == nullptr)
        _shared = new UI();
    return _shared;
}

void UI::showWindow()
{
    initscr();
    printw("Hello World");
}
