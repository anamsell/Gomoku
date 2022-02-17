#include "Game.hpp"
#include "Constants.hpp"
#include "Position.hpp"
#include <iostream>
#include <vector>
using namespace std;

bool    Game::_end_pattern_verif(int dx, int dy, Position pos, unsigned int allies)
{
    // EMXXXE are the patter specific pattern we test here.
    // E = empty, X are 2 ally and 1 empty and M is the move
    // We are already sure for EMXX
    // need to check the last X and the E and count allies

    pos.move(dx,dy);
    pos.set_value(_goban);
    if (!pos.value || pos.value == _opp)
        return false;
    allies += (pos.value == _player);
    if (allies != 2)
        return false;
    pos.move(dx,dy);
    pos.set_value(_goban);
    return pos.value == EMPTY_INTERSECTION;
}

bool    Game::_directional_three(int dx, int dy)
{
    // Pattern for free three EXXXXE with E = empty and X are 2 ally and 2 empty
    Position        forward;
    Position        backward;
    Position        last_forward;
    Position        last_backward;
    unsigned int    allies = 0;

    forward = _new_move;
    backward = _new_move;
    forward.move(dx, dy);
    backward.move(-dx, -dy);
    forward.set_value(_goban);
    backward.set_value(_goban);
    if (!forward.value || !backward.value)
        return false;
    if (forward.value == _opp || backward.value == _opp)
        return false;
    allies += (forward.value == _player);
    allies += (backward.value == _player);
    last_forward = forward;
    last_backward = backward;
    forward.move(dx, dy);
    backward.move(-dx, -dy);
    forward.set_value(_goban);
    backward.set_value(_goban);
    allies += (forward.value == _player);
    allies += (backward.value ==_player);
    if (allies != 1 && allies != 2)
        return false;
    if (!forward.value || forward.value == _opp) {
        if (!backward.value || backward.value == _opp || last_forward.value != EMPTY_INTERSECTION)
            return false;
        return _end_pattern_verif(-dx, -dy, backward, allies);
    }
    if (!backward.value || backward.value == _opp) {
        if (!forward.value || forward.value == _opp || last_backward.value != EMPTY_INTERSECTION)
            return false;
        return _end_pattern_verif(dx, dy, forward, allies);
    }
    if ((last_backward.value == EMPTY_INTERSECTION && _end_pattern_verif(dx, dy, forward, allies)) ||
        (last_forward.value == EMPTY_INTERSECTION && _end_pattern_verif(-dx, -dy, backward, allies)))
        return true;
    if (allies == 1)
        return false;
    last_forward = forward;
    last_backward = backward;
    forward.move(dx, dy);
    backward.move(-dx, -dy);
    forward.set_value(_goban);
    backward.set_value(_goban);
    return ((backward.value == EMPTY_INTERSECTION && last_forward.value == EMPTY_INTERSECTION) ||
    (forward.value == EMPTY_INTERSECTION && last_backward.value == EMPTY_INTERSECTION));
}

bool    Game::_double_three()
{
//    return false;
    int     three_count = 0;
    // 4 direction possible horizontal, vertical, and 2 diagonals
    three_count += _directional_three(1, 0);
    three_count += _directional_three(0, 1);
    if (three_count == 2)
        return true;
    three_count += _directional_three(1, 1);
    if (three_count == 2)
        return true;
    three_count += _directional_three(-1, 1);
    // if it creates at least 2 free_three on different direction : double three
    if (three_count == 2)
        return true;
    _precedent_captured.clear();
    return false;
}
