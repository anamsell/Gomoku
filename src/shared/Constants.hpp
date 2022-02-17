#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

//user interface constant
#define DEFAULT_WINDOW_WIDTH 1200
#define DEFAULT_WINDOW_HEIGHT 770
#define ERROR_MARGIN 12
#define BOARDER_GOBAN 25
#define WINDOW_TITLE "Gomoku"
#define GOBAN_IMG_PATH "resources/goban.png"
#define WHITE_STONE_IMG_PATH "resources/whitestone.png"
#define BLACK_STONE_IMG_PATH "resources/blackstone.png"
#define GREEN_CIRCLE_IMG_PATH "resources/greencircle.png"

//game engine constant
#define GOBAN_SIZE 19
#define FIRST_PLAYER 'B'
#define SECOND_PLAYER 'W'
#define EMPTY_INTERSECTION 'O'

#include <iostream>
#include <vector>
typedef std::vector<std::vector<char> > vector2d;

#endif

