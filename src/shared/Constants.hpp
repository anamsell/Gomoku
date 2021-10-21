/* ************************************************************************** */
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

#define DEFAULT_WINDOW_WIDTH 1024
#define DEFAULT_WINDOW_HEIGHT 768
#define WINDOW_TITLE "Gomoku"
#define GOBAN_IMG_PATH "ressources/goban.png"
#define GOBAN_SIZE 19
#define FIRST_PLAYER 'B'
#define SECOND_PLAYER 'W'
#define EMPTY_SQUARE 'O'

#include <iostream>
#include <vector>
typedef std::vector<std::vector<char> > vector2d;

#endif
