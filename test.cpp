#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <tuple>
#include <chrono>
#include <sys/time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
using namespace std;

struct Position
{
    int     x;
    int     y;

    Position(int x = 0, int y = 0);
    void    redefine(int ,int );
    bool operator == (const Position& p) const {return x == p.x && y == p.y;}
    bool operator != (const Position& p) const {return !operator==(p);}
};


Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

void    Position::redefine(int x, int y)
{
    this->x = x;
    this->y = y;
}

struct OneStruct {
    int     a;

    OneStruct(int a);
};

OneStruct cpy(OneStruct st) {
    OneStruct cpy = st;
    cout << &cpy << endl;
    cout << &st << endl;
    return (cpy);
}

OneStruct::OneStruct(int a) {
    this->a = a;
}

class   OneClass{
    public:
    int     a;

    OneClass(){a = 10;}

};

void    fnc(OneStruct st)
{
    cout << &st << endl;
}

void     test1(array<list<int>,12 > &test)
{

    test[0].push_back(15);
}

int     test2()
{
    cout << "aa" << endl;
    return 1;
}


void    test3(int *iss)
{
    iss[0] = 15;

}

int main() {

    list<Position>  lst;
    Position        pos(10,10);
    lst.push_back(pos);
    cout << lst.size() <<endl;
    lst.remove(pos);
    cout << lst.size() <<endl;

}