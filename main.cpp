#include <iostream>
#include <fstream>
#include "Opening.h"
#include "game.h"
#include <stdlib.h>
#include <iomanip>

using namespace std;


int GetNumOpenings(); //Done
void CompareOpenings(Opening openings[], int numOpenings);
bool DetectOpening(Game *game, Opening opening);
string GetString(); //Done
void Menu();//Done
void ReadOpenings(Opening arr[], int size); //Done
void PrintOpenings(Opening arr[], int size); //Done


int main()
{
    Menu();
    return 0;
}


void Menu()
{
    int numOpenings = 0;
    numOpenings = GetNumOpenings();
    Opening openings[numOpenings];
    ReadOpenings(openings, numOpenings);
    while(true)
    {
        int action;
        cout<<"Print Stored Openings (1)"<<endl;
        cout<<"Load  Game   File     (2)"<<endl;
        cout<<"Exit                  (0)"<<endl<<endl;
        cout<<"Enter action:";
        cin>>action;
        cin.ignore();
        cout<<endl;
        switch(action)
        {
        case 0:
            cout<<"Exit Selected"<<endl;
            break;
        case 1:
            PrintOpenings(openings, numOpenings);
            break;
        case 2:
            CompareOpenings(openings, numOpenings);
            break;
        default:
            cout<<"Invalid Action"<<endl;
        }
        if(action == 0)
            break;
    }
}
string GetString()
{
    string filename;
    cout<<"Please enter game filename:";
    cin>>filename;
    cin.ignore();
    return filename;

}



int GetNumOpenings()
{
    ifstream infile;
    infile.open("openings.txt");
    int numOpenings;
    infile>>numOpenings;
    infile.close();
    return numOpenings;
}


void CompareOpenings(Opening openings[], int numOpenings)
{
   Game* game = new Game;
   game->readGame();
    for(int i = 0; i<6; i++) {
        if (DetectOpening(game, openings[i])) {
            cout << "Detected Opening: " << openings[i].name << " " << "(" << openings[i].white << "," << openings[i].draw << "," << openings[i].black << ")" << endl << endl;
        }
    }
    delete game;

}



bool DetectOpening(Game *game, Opening opening)
{

    bool same = true;

    for (int i = 0; i < opening.numOpeningMoves && same; i++) {
        if (game->array_Moves[i] != opening.moves[i]) {
            same = false;
        } else {

        }
    }


    return same;

}


void PrintOpenings(Opening arr[], int size)
{
    cout << left << setw(40) << "NAME" << left << setw(20) << "MOVES" << left << setw(20) << "WIN PERCENTAGES" <<left << setw(25) << "TIMES PLAYED" << endl << endl;

    for (int i=0; i < size; i++)
    {
        cout << left << setw(40) << arr[i].name;

        for(int j=0; j< arr[i].numOpeningMoves; j++)
        {
            cout << arr[i].moves[j] << " ";
        }

        cout <<"  ";

        cout << right <<setw(10) << arr[i].black << "," << right << arr[i].draw << "," << right <<arr[i].white << right << setw(20) <<arr[i].times_played << right << endl << endl;
    }
}




void ReadOpenings(Opening arr[], int size)   ///size is the number of openning
{
    //FILL IN
    string moves[6];
    ifstream inData;
    inData.open("opening.txt");
    inData.ignore();
    inData.ignore();

    for(int i=0; i <size; i++)
    {
        getline(inData, arr[i].name);

        inData >> arr[i].numOpeningMoves;

        for(int j=0; j < arr[i].numOpeningMoves; j++)
        {
            inData >> arr[i].moves[j];
        }
        inData >> arr[i].times_played;

        inData >> arr[i].white;
        inData >> arr[i].draw;
        inData >> arr[i].black;
        inData.ignore();
    }
    inData.close();





}

