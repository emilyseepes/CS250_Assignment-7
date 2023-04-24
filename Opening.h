#ifndef OPENING_H_INCLUDED
#define OPENING_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Opening{
   Opening(); //constructor


    string name;
    int numOpeningMoves;
    string moves[6]; //The actual moves
    string times_played; //official number opening has been played in tournaments


//Percentages
    double white; //% of white's victory
    double black; // % of black's victory
    double draw; //% of draw

};

#endif // OPENING_H_INCLUDED
