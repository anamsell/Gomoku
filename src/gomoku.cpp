/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:46:55 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 12:35:46 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "UI.hpp"
#include "Game.hpp"
using namespace std;

void    print_vect(vector2d goban)
{
    for (int i = 0; i < goban.size(); i++)
    {
        for (int j = 0; j < goban[i].size(); j++)
        {
            cout << goban[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    // UI *ui = UI::shared();
    // ui->showWindow();
    Game game;
    Position move(2,2);
    game.new_move(move);
    move.redefine(5, 5);
    game.new_move(move);
    move.redefine(0, 2);
    game.new_move(move);
    move.redefine(6, 6);
    game.new_move(move);
    move.redefine(1, 2); 
    game.new_move(move);
    move.redefine(3, 2);
    game.new_move(move);
    // move.redefine(4, 3);
    // game.new_move(move);
    // move.redefine(15, 15);
    // game.new_move(move);
    // move.redefine(6, 5);
    // game.new_move(move);
    // move.redefine(3, 6);
    // game.new_move(move);
    // move.redefine(3, 2);
    // game.new_move(move);
    print_vect(game.get_goban());

    return 0;
}
