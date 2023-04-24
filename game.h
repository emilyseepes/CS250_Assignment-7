#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Game{
    Game();//constructor
    char outcome; // 'B' for Black win; W for white win, D for Draw
    int numMoves; //moves in game
    string array_Moves[6]; //array of moves


    void readGame();
};


#endif // GAME_H_INCLUDED
