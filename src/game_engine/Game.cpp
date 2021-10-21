#include "Game.hpp"
using namespace std;

//constructor

Game::Game() : _player(0), _first_player_captures_count(0), _second_player_captures_count(0), _goban(vector2d(GOBAN_SIZE, std::vector<char> (GOBAN_SIZE, EMPTY_SQUARE)))
{}

//a player try to make a move

int     Game::new_move(Position move)
{
    _move = move;
    _captured_stones.clear();
    if (_move_is_playable() == false)
        return -1;
    _put_stone_on_goban();
    _capture();
    if(_is_game_over() == true)
        return 0;
    _change_player();
    return 1;
}

bool    Game::_move_is_playable()
{
    if (_move.is_in_the_map() == false)
        return false;
    if (_move.is_empty_on(_goban) == false)
        return false;
    if (_double_three() == true)
    {
        cout << "double_three" << endl;
        return false;
    }
    if (_mandatory_moves.size() != 0)
        if (_is_in_mandatory() == false)
            return false;
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