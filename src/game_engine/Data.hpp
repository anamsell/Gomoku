#ifndef DATA_HPP
#define	DATA_HPP

#include "Constants.hpp"
#include "Position.hpp"
#include <iostream>
#include <vector>
#include <list>

struct Content
{
    vector2d            goban;
    bool                player;
    std::list<Position> mandatory_moves;
    bool                game_over;
    bool                game_tie;

    int                 first_player_captures_count;
    int                 second_player_captures_count;

    Content             *previous;

};

class Data
{
    public:

    Data();     //Constructor
    ~Data();    //Destructor

    void    push_back(vector2d, bool , std::list<Position>, bool, bool, int, int);
    void    go_back();

    Content*    _cont;
    private:
    
};

#endif