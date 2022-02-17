#ifndef AI_HPP
#define AI_HPP

#include <iostream>
#include "Position.hpp"
#include "Constants.hpp"
#include "Game.hpp"
#include "SearchSpace.hpp"


int                     heuristic(Game&, char player);
Position                artificial_intelligence(Game&);
int                     minmax(int depth, Game, bool maximum, int alpha, int beta, char player);


#endif
