#ifndef Game_HPP
#define	Game_HPP	
#include "Position.hpp"
#include "Constants.hpp"


class Game
{
    public:
        Game();     // constructor
        int                 new_move(Position);

        //getter
        vector2d            get_goban(){return _goban;}
        bool                get_player(){return _player;}
        Position            get_move(){return _move;}
        int                 get_first_player_capture_count(){return _first_player_captures_count;}
        int                 get_second_player_capture_count(){return _second_player_captures_count;}
        std::list<Position> get_captured_stones(){return _captured_stones;}

    private:

        void                _put_stone_on_goban();
        void                _change_player();

        vector2d            _goban;
        bool                _player;
        Position            _move = {0, 0};
        std::list<Position> _captured_stones;
        std::list<Position> _mandatory_moves;

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
        bool                _unbreakable_five_stones();
        void                _directional_five(int , int , std::list<std::list<Position> >&);
        // case unique five
        bool                _is_unbreakable_five_stones(std::list<Position>);
        void                _vulnerable(Position);
        void                _directional_vulnerability(int, int, Position);
        // case two five
        bool                _are_unbreakables_five_stones(std::list<std::list<Position> >);
        std::list<Position>      _vulnerables_stones(std::list<Position>, std::list<Position>);
        std::list<Position>      _find_central_stones();
        void                _move_capture_both(Position, Position);
};

#endif