#ifndef GAME_HPP
#define	GAME_HPP

#include "Constants.hpp"
#include "Position.hpp"
#include "Data.hpp"
#include <iostream>
#include <vector>
#include <list>

class Game
{
    public:
        Game();     // constructor
        ~Game();    // destructor
        void                new_move(Position);

        void                previous_data();

        //getters
        vector2d            get_goban(){return _goban;}
        bool                get_player(){return _player;}
        Position            get_move(){return _move;}
        int                 get_first_player_capture_count(){return _first_player_captures_count;}
        int                 get_second_player_capture_count(){return _second_player_captures_count;}
        bool                new_move_is_valid(){return _valid_new_move;}
        std::string         get_error_code(){return _error_code;}
        bool                is_over(){return _game_over;}
        bool                is_tie(){return _game_tie;}

    private:

        void                _put_stone_on_goban();
        void                _change_player();

        Data*                _historic;
        vector2d            _goban;
        bool                _player;
        Position            _move;
        std::list<Position> _mandatory_moves;
        bool                _valid_new_move;
        std::string         _error_code;
        bool                _game_over;
        bool                _game_tie;

        int                 _first_player_captures_count;
        int                 _second_player_captures_count;

    //move playable
        bool                _move_is_playable();

    //rules
        bool                _double_three();

    //is_a_mandatory_move
        bool                _is_in_mandatory();

    //capture
        void                _capture();
        void                _directional_capture(int, int);
        void                _capture_stone(Position);

    //check if game is over
        bool                _is_game_over();
        bool                _is_game_tie();
        bool                _unbreakable_five_stones();
        void                _directional_five(int , int , std::list<std::list<Position> >&);
        // case unique five
        bool                _is_unbreakable_five_stones(std::list<Position>);
        void                _vulnerable(Position);
        void                _directional_vulnerability(int, int, Position);
        // case two five
        bool                _are_unbreakables_five_stones(std::list<std::list<Position> >);
        std::list<Position> _vulnerables_stones(std::list<Position>, std::list<Position>);
        std::list<Position> _find_central_stones();
        void                _move_capture_both(Position, Position);
};

#endif