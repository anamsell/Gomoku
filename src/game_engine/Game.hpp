#ifndef GAME_HPP
#define	GAME_HPP

#include "Constants.hpp"
#include "Position.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <array>

class Game
{
    public:
        Game();     // constructor
        ~Game();    // destructor
        void                new_move(Position);

        //getters
        vector2d            get_goban() const{return _goban;}
        char                get_player() const{return _player;}
        char                get_opponnent() const{return _opp;}
        Position            get_move() const{return _new_move;}
        int                 get_turn()const{return _turn;}

        int                 get_actual_player_count() const{if (_player == FIRST_PLAYER) return _fp_captures_count; return _sp_captures_count ;}

        std::list<Position> get_fp_stones() const {return _fp_stones;}
        int                 get_fp_capture_count() const{return _fp_captures_count;}
        int                 get_fp_free_three_number() const {return _sp_free_three.size();}

        std::list<Position> get_sp_stones() const {return _sp_stones;}
        int                 get_sp_capture_count() const{return _sp_captures_count;}
        int                 get_sp_free_three_number() const {return _sp_free_three.size();}

        bool                new_move_is_valid() const{return _valid_new_move;}
        std::string         get_error_code() const{return _error_code;}
        bool                is_over() const{return _game_over;}
        bool                is_tie() const{return _game_tie;}


        std::array<std::list<Position>, 12>    possibles_moves;

        std::list<Position> get_precedent_captured() const{return _precedent_captured;}

    private:

        void                _put_stone_on_goban();
        void                _change_player();

        vector2d            _goban;
        char                _player;
        char                _opp;
        Position            _new_move;
        int                 _turn;
        std::list<Position> _fp_stones;
        std::list<Position> _sp_stones;

        std::list<Position> _mandatory_moves;
        bool                _valid_new_move;
        std::list<Position> _precedent_captured;

        std::string         _error_code;
        bool                _game_over;
        bool                _game_tie;

        int                 _fp_captures_count;
        int                 _sp_captures_count;

        std::list<Position> _fp_free_three;
        std::list<Position> _sp_free_three;

    //move playable
        bool                _move_is_playable();

    //rules
        bool                _double_three();
        bool                _directional_three(int dx, int dy);
        bool                _end_pattern_verif(int dx, int dy, Position pos, unsigned int allies);

    //is_a_mandatory_move
        bool                _is_in_mandatory();

    //capture
        bool                _capture();
        void                _directional_capture(int, int, std::list<Position>& captures);
        void                _capture_stones(const std::list<Position>&);

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
        static std::list<Position>  _vulnerables_stones(std::list<Position>, std::list<Position>);
        std::list<Position> _find_central_stones();
        void                _move_capture_both(Position, Position);
        // opponent taking the last 2 stones when five stone
        bool                _opponent_can_take_last_stones();
        bool                _player_stones_vulnerable();
};

#endif
