#include "SearchSpace.hpp"

using namespace std;

void    add_pos_to_list(Position pos, array<list<Position>, 12>& possibles_moves, const Game game)
{
    for (int i = 0; i != 12; i++) {
        if (possibles_moves[i].empty())
            continue;
        for (list<Position>::iterator it = possibles_moves[i].begin(); it != possibles_moves[i].end(); it++)
            if (it->x == pos.x && it->y == pos.y) {
                if (i!=11) {
                    possibles_moves[i].erase(it);
                    possibles_moves[i+1].push_front(pos);
                }
                return;
            }
    }
    possibles_moves[0].push_back(pos);
}

void    remove_pos_from_list(Position pos, array<list<Position>, 12>& possibles_moves)
{
    for (int i = 0; i != 12; i++)
        possibles_moves[i].remove(pos);
}

void    alignement_has_two_stone(int dx, int dy, array<list<Position>, 12>& possibles_moves, Game game)
{
    Position    last_move = game.get_move();

    for (int i = 1; i < 5; i++) {
        last_move.move(dx, dy);
        if(!last_move.is_on_the_map())
            break;
        add_pos_to_list(last_move, possibles_moves, game);
    }
}

void    possible_alignement(int dx, int dy, array<list<Position>, 12>& possibles_moves, Game game)
{
    Position    last_move = game.get_move();

    for (int i = 1; i < 5; i++) {
        last_move.move(dx, dy);
        last_move.set_value(game.get_goban());
        if (!last_move.value)
            break;
        if (last_move.value != EMPTY_INTERSECTION) {
            alignement_has_two_stone(dx,dy, possibles_moves,game);
            break;
        }
    }
    last_move = game.get_move();
    for (int i = 1; i < 5; i++) {
        last_move.move(-dx, -dy);
        last_move.set_value(game.get_goban());
        if (!last_move.value)
            break;
        if (last_move.value != EMPTY_INTERSECTION) {
            alignement_has_two_stone(-dx,-dy, possibles_moves,game);
            break;
        }
    }
}

array<list<Position>, 12> update_good_move(array<list<Position>, 12> possibles_moves, Game game)
{
    Position    last_move = game.get_move();
    Position    pos;

//    remove_pos_from_list(last_move, possibles_moves);
    for (int i = -1; i != 2; i++)
        for (int j = -1; j != 2; j++)
            if (i || j) {
                pos = last_move;
                pos.move(i, j);
                pos.set_value(game.get_goban());
                if (pos.value)
                    add_pos_to_list(pos, possibles_moves, game);
            }
    possible_alignement(1, 0, possibles_moves, game);
    possible_alignement(0, 1, possibles_moves, game);
    possible_alignement(1, 1, possibles_moves, game);
    possible_alignement(1, -1, possibles_moves, game);
    return possibles_moves;
}
