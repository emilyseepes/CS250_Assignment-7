#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;
Game::Game()
{
    outcome = ' ';
    numMoves = 0;
}


void Game::readGame()
{

    string fileName;
    cout<< endl <<  "Please enter the name of the file you want: " ;
    cin >> fileName;
    ifstream inData;
    inData.open(fileName);




    inData >> outcome >> numMoves;

    for (int i=0; i < 6; i++)
    {
        inData >> array_Moves[i];

    }


}
