#include "AI.hpp"
using namespace std;
#include <ctime>
#include <cstdlib>

int         heuristic(Game game) { //return score of the situation for the player who just play the move. high score mean bad situation.
    if (game.is_over())
    {
        if (game.is_tie())
            return 0;
        return INT32_MIN;
    }
    int     score = 0;
    bool    player = !game.get_player();

    score += game.get_first_player_capture_count();
    score -= game.get_second_player_capture_count();
    if (player == 0) //if its first player need to do opposite.
        score = -score;
    return score;

}

Position    artificial_intelligence(Game game)
{
    list<Position>  possibles_moves;
    Position        best_move(18, 18);
    int             max_value;
    int             new_value;

    max_value = INT32_MIN; //starting at player turn so looking to maximize score aka heuristic value
    possibles_moves = good_moves(game);
    for (auto &&pos : possibles_moves)
    {
        new_value = minmax(1, game, 0, pos, INT32_MIN, INT32_MAX);
        if (new_value > max_value)
        {
            max_value = new_value;
            best_move = pos;
        }

    }
    return best_move;
}

int         minmax(int depth, Game game, bool maximum, Position pos, int alpha, int beta)
{
    game.new_move(pos);
    if (depth == 0 or game.is_over())
    {
        if (maximum) // if maximum == 1  it's my turn. either depth was an even number at start or I win here
            return -heuristic(game);
        return heuristic(game); // if maximum == 0 it's not my turn. either depth was an odd number or I loose here
    }
    list<Position>  possibles_moves;
    int             value;

    possibles_moves = good_moves(game);
    if (maximum)
    {
        value = INT32_MIN;
        for (auto &&pos : possibles_moves)
        {
            value = max(value, minmax(depth - 1, game, 0, pos, alpha, beta));
            if (value >= beta)
                break;
            alpha = max(alpha, value);
        }
    }
    else
    {
        value = INT32_MAX;
        for (auto &&pos : possibles_moves)
        {
            value = min(value, minmax(depth - 1, game, 1, pos, alpha, beta));
            if (value <= alpha)
                break;
            beta = min(beta, value);
        }
    }
    return value;

}