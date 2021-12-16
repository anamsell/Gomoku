/* **********************dfefeererefefe**************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Constants.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:26:39 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/21 17:45:08 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

//user interface constant
#define DEFAULT_WINDOW_WIDTH 1200
#define DEFAULT_WINDOW_HEIGHT 770
#define ERROR_MARGIN 7
#define BOARDER_GOBAN 25
#define WINDOW_TITLE "Gomoku"
#define GOBAN_IMG_PATH "ressources/goban.png"
#define WHITE_STONE_IMG_PATH "ressources/whitestone.png"
#define BLACK_STONE_IMG_PATH "ressources/blackstone.png"
#define GREEN_CIRCLE_IMG_PATH "ressources/greencircle.png"

//game engine constant
#define GOBAN_SIZE 19
#define FIRST_PLAYER 'B'
#define SECOND_PLAYER 'W'
#define EMPTY_INTERSECTION 'O'

#include <iostream>
#include <vector>
typedef std::vector<std::vector<char> > vector2d;

#endif
