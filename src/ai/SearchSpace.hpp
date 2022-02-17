#ifndef SEARCHSPACE_HPP
#define SEARCHSPACE_HPP

#include <iostream>
#include "Position.hpp"
#include "Constants.hpp"
#include "Game.hpp"
#include <array>

std::array<std::list<Position>, 12> update_good_move(std::array<std::list<Position>, 12> possibles_moves, Game game);
void                                remove_pos_from_list(Position pos, std::array<std::list<Position>, 12> &possibles_moves);
void                                add_pos_to_list(Position pos, std::array<std::list<Position>, 12> &possibles_moves, const Game);

//std::list<Position>     good_moves(Game game);
//bool                    pos_is_possible(Game game, Position position);
//bool                    is_in_one_area(Position position, std::list<Area> areas);
//std::list<Area>         all_areas(vector2d goban);
//Area                    new_area(Position position, vector2d &goban);
//bool                    stone_in_area(int dx, int dy, Position position, vector2d& goban, Area& area, int depth);
//void                    searching_dimension_of_area(Position position, vector2d& goban, Area& area, int depth);
//void                    removing_stone_of_area(vector2d& goban, Area);
//void                    increase_size(Area&);

#endif
