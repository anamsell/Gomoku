#include "Game.hpp"
using namespace std;

//constructor

Game::Game()
{
    _new_move = Position(-1, -1);
    _player = FIRST_PLAYER;
    _opp = SECOND_PLAYER;
    _fp_captures_count = 0;
    _sp_captures_count = 0;
    _turn = 0;
    _valid_new_move = true;
    _game_over = false;
    _game_tie = false;
    _goban = vector2d(GOBAN_SIZE, std::vector<char> (GOBAN_SIZE, EMPTY_INTERSECTION));
}


Game::~Game()
{
}

//a player try to make a move

void     Game::new_move(Position move)
{
    _new_move = move;
    _new_move.set_value(_goban);
    if (not _move_is_playable())
    {
        _valid_new_move = false;
        return;
    }
    _turn++;
    _valid_new_move = true;
    _put_stone_on_goban();
    _mandatory_moves.clear();
    if (_is_game_over())
        _game_over = true;
    if (_player == FIRST_PLAYER)
        _fp_stones.push_back(_new_move);
    else
        _sp_stones.push_back(_new_move);
    _change_player();
}

bool    Game::_move_is_playable()
{
    if (!_new_move.value)
    {
        _error_code = "Move is not on the map.";
        return false;
    }
    if (_new_move.value != EMPTY_INTERSECTION)
    {
        _error_code = "Move is not on empty intersection.";
        return false;
    }
    if (!_mandatory_moves.empty())
        if (not _is_in_mandatory())
        {
            if (get_actual_player_count() == 8)
                _error_code = "Move must take last stones to win.";
            else
                _error_code = "Move must break the opponent alignment by capturing a pair.";
            return false;
        }
    // Trying to capture stone, if move induce capture don't need to check for double three.
    if (!_capture() && _double_three())
    {
        _error_code = "Move introduce a double-three.";
        return false;
    }
    return true;
}

void    Game::_put_stone_on_goban()
{
    _goban[_new_move.x][_new_move.y] = _player;
}

void    Game::_change_player()
{
    _opp = _player;
    if (_player == FIRST_PLAYER)
        _player = SECOND_PLAYER;
    else
        _player = FIRST_PLAYER;

}