#include "Data.hpp"
using namespace std;

//constructor

Data::Data()
{
    _cont = new Content;
    _cont->player = 0;
    _cont->game_over = false;
    _cont->game_tie = false;
    _cont->first_player_captures_count = 0;
    _cont->second_player_captures_count = 0;
    _cont->goban = vector2d(GOBAN_SIZE, std::vector<char> (GOBAN_SIZE, EMPTY_INTERSECTION));
    _cont->previous = nullptr;
}

Data::~Data()
{
    Content *tmp = _cont;
    while(tmp != nullptr)
    {
        _cont = _cont->previous;
        delete tmp;
        tmp = _cont;
    }
}

void    Data::push_back(vector2d goban, bool player, std::list<Position> mandatory_moves, bool game_over,
                        bool game_tie, int first_player_captures_count, int second_player_captures_count)
{
    Content     *next = new Content;

    next->previous = _cont;
    _cont = next;
    _cont->goban = goban;
    _cont->player = player;
    _cont->mandatory_moves = mandatory_moves;
    _cont->game_over = game_over;
    _cont->game_tie = game_tie;
    _cont-> first_player_captures_count = first_player_captures_count;
    _cont->second_player_captures_count = second_player_captures_count;
}

void    Data::go_back()
{
    Content *tmp;

    tmp = _cont;
    _cont = _cont->previous;
    delete tmp;
}