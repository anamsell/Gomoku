#include "AI.hpp"
#include <ctime>
#include <cstdlib>
using namespace std;

int         heuristic(Game& game, char player) {
//    return 5;
    //return score of the situation for the computer ( or the player when we just want to simulate the algo move).
    // high score mean good situation. low mean bad
    if (game.is_over()) {
        if (game.is_tie())
            return 0;
        if (game.get_player() == player) //get player will return actual player so who lost the game.
            // if get player == player it means we loose here .
            return INT32_MIN + 1;
        return INT32_MAX - 1;
    }
    int     score = 0;

    score += game.get_fp_capture_count();
    score -= game.get_sp_capture_count();
    if (player == 'W') //if its second player need to do opposite.
        return -score;
    return score;

}

Position    artificial_intelligence(Game& game)
{
    Game                    game_cpy;
    Position                best_move(0,0);
    int                     max_value;
    int                     new_value;
    int                     depth = 1;
    char                    player;
    Position                pos;
//    printf("start algo\n");

    player = game.get_player();
//    printf("%c\n",player);
    max_value = INT32_MIN; //starting at player turn so looking to maximize score aka heuristic value
    game.possibles_moves = update_good_move((game.possibles_moves), game);
    for (int i = 11; i != -1; i--)
        for (auto &&pos: game.possibles_moves[i]) {
            game_cpy = game;
            game_cpy.new_move(pos);
            if (!game_cpy.new_move_is_valid())
                continue;
            new_value = minmax(depth - 1, game_cpy, false, INT32_MIN, INT32_MAX, player);
            if (new_value > max_value) {
                max_value = new_value;
                best_move = pos;
            }
        }
//    printf("end algo\n");
    return best_move;
}

int         minmax(int depth, Game game, bool maximum, int alpha, int beta, char player)
{
    Game            game_cpy;
    int             value;
    Position                pos;

    if (depth == 0 or game.is_over())
        return heuristic(game, player);
    game.possibles_moves = update_good_move(game.possibles_moves, game);
    if (maximum) {
        value = INT32_MIN;
        for (int i = 11; i != -1; i--)
            for (auto &&pos: game.possibles_moves[i]) {
//                printf("pos : %d %d, i : %d, depth : %d\n", pos.x, pos.y, i, depth);
                game_cpy = game;
                game_cpy.new_move(pos);
                if (!game_cpy.new_move_is_valid())
                    continue;
                value = max(value, minmax(depth - 1, game_cpy, false, alpha, beta, player));
                alpha = max(alpha, value);
                if (beta <= alpha) {
//                    printf("cut BETA\n");
                    return value;
                }
            }
    }
    else {
        value = INT32_MAX;
        for (int i = 11; i != -1; i--)
            for (auto &&pos: game.possibles_moves[i]) {
                game_cpy = game;
                game_cpy.new_move(pos);
                if (!game_cpy.new_move_is_valid())
                    continue;
                value = min(value, minmax(depth - 1, game_cpy, true, alpha, beta, player));
                beta = min(beta, value);
                if (beta <= alpha) {
//                    printf("cut ALPHA\n");
                    return value;
                }
            }
    }
//    printf("value %d\n",value);
    return value;
}