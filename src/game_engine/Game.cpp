#include "Game.hpp"
using namespace std;

//constructor

Game::Game()
{
    _historic = new Data;
    _player = 0;
    _first_player_captures_count = 0;
    _second_player_captures_count = 0;
    _valid_new_move = true;
    _game_over = false;
    _game_tie = false;
    _goban = vector2d(GOBAN_SIZE, std::vector<char> (GOBAN_SIZE, EMPTY_INTERSECTION));
}

Game::~Game() {
    //delete _historic;
}

//a player try to make a move

void     Game::new_move(Position move)
{
    _move = move;
    if (_move_is_playable() == false)
    {
        _valid_new_move = false;
        return;
    }
    _valid_new_move = true;
    _put_stone_on_goban();
    _capture();


    _historic->push_back(_goban, _player, _mandatory_moves, _game_over, _game_tie, _first_player_captures_count,
                         _second_player_captures_count);
    if(_is_game_over() == true)
        _game_over = true;
    _change_player();
    return ;
}

void    Game::previous_data()
{
    _historic->go_back();
    _goban = _historic->_cont->goban;
    _player = _historic->_cont->player;
    _mandatory_moves = _historic->_cont->mandatory_moves;
    _game_over = _historic->_cont->game_over;
    _game_tie = _historic->_cont->game_tie;
    _first_player_captures_count = _historic->_cont->first_player_captures_count;
    _second_player_captures_count = _historic->_cont->second_player_captures_count;

}

bool    Game::_move_is_playable()
{
    if (_move.is_in_the_map() == false)
    {
        _error_code = "Move is not on the map.";
        return false;
    }
    if (_move.is_empty_on(_goban) == false)
    {
        _error_code = "Move is not on empty intersection.";
        return false;
    }
    if (_double_three() == true)
    {
        _error_code = "Move introduce a double-three.";
        return false;
    }
    if (_mandatory_moves.size() != 0)
        if (_is_in_mandatory() == false)
        {
            _error_code = "Move must break the opponent alignment by capturing a pair.";
            return false;
        }
    return true;
}

void    Game::_put_stone_on_goban()
{
    if (_player == 0)
        _goban[_move.x][_move.y] = 'B';
    else
        _goban[_move.x][_move.y] = 'W';
    
}

void    Game::_change_player()
{
    _player = !_player;
}