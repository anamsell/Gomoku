/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UIBoard.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:40:18 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 12:46:26 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UIBOARD_HPP
#define UIBOARD_HPP

#include <vector>

using ui_board = std::vector<std::vector<int> >;

class UIBoard
{
private:
    ui_board _board;

public:
    UIBoard(ui_board board);
    void update(ui_board board);
    void render();
};

#endif
