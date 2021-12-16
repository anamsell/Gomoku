#include <iostream>
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

void    test(vector<int>& bla)
{
    bla[0] = 5;
    printf("%d\n", bla[0]);
}

list<int>   test2()
{
    list<int> blabla;

    blabla.push_front(5);
    blabla.push_front(5);
    blabla.push_front(5);
    return (blabla);
}

int     main()
{
    int     a;
    int     b;

    a = 5;
    b = 6;

    printf("%d\n", min(a,b));
}