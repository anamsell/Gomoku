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

#include "Size.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <cmath>
#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 500
#define WINDOW_TITLE "Gomoku"
#define WINDOW_PADDING 16
#define GOBAN_SIZE 19
#define FIRST_PLAYER 'B'
#define SECOND_PLAYER 'W'
#define EMPTY_SQUARE 'O'
typedef std::vector<std::vector<char> > vector2d;

#endif
