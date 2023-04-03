//#include "../headers/board.h"
#include "board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;
/*
Reminder, 2d columns are id[row][column]
*/


Board::Board(int difficulty){
//0 easy, 1 medium, 2 hard
//board is pregenerated 25x25 empty chars, we will never use the 0 column
//10 mines, 40 mines, 120 mines
    this->difficulty=difficulty;
    // for(int i=0;i<MAXBOARD;i++){//initialize the memory
    //     for(int j=0;j<MAXBOARD;j++){
    //         gameBoard[i][j]='-';
    //         playerBoard[i][j]='-';
    //     }
    // }
    gameBoard.resize(MAXBOARD, vector<char>(MAXBOARD, '-'));
    playerBoard.resize(MAXBOARD, vector<char>(MAXBOARD, '-'));
}
Board::Board(){}

vector<vector<char>>& Board::getPlayerBoard()
{
    return playerBoard;
}
vector<vector<char>>& Board::getGameBoard()
{
    return gameBoard;
}

int Board::getDifficulty(){
    return difficulty;
}

void Board::printBoard(int which) {
    // Code to print the game board
    //0 is game board
    //1 is player board

    // if(difficulty==EASY){
    //     for(int i=0;i<=small;i++){
    //         for (int j=1; j<=small;j++){
    //             if(which==0){cout<<gameBoard[i][j]<<" ";}
    //             else if(which==1){cout<<playerBoard[i][j]<<" ";}
    //         }
    //         cout<<endl;
    //     }
    // }
    // else if(difficulty==MEDIUM){
    //     for(int i=0;i<=medium;i++){
    //         for (int j=1; j<=medium;j++){
    //             if(which==0){cout<<gameBoard[i][j]<<" ";}
    //             else if(which==1){cout<<playerBoard[i][j]<<" ";}
    //         }
    //         cout<<endl;
    //     }
    // }
    // else if(difficulty==HARD){
    //     for(int i=0;i<=large;i++){
    //         for (int j=1; j<=large;j++){
    //             if(which==0){cout<<gameBoard[i][j]<<" ";}
    //             else if(which==1){cout<<playerBoard[i][j]<<" ";}
    //         }
    //         cout<<endl;
    //     }
    // }

    if(difficulty==EASY){
    cout << "   ";
    for (int i=0; i < small; i++) {
        cout << "| " << i+1 << " ";
    }
    cout << "|" << endl;
    cout << "  _";
    for (int i=0; i < small; i++) {
        cout << "|___";
    }
    cout << "|" << endl;

    for (int i=0; i < small; i++) {
        cout << setw(2) << i+1 << "|";
        for (int j = 0; j < small; j++) {
            if(which==0){cout<<setw(2)<<gameBoard[i][j]<<"  ";}
            else if(which==1){cout<<setw(2)<<playerBoard[i][j]<<"  ";}
        }
        cout << "|" << endl;
    }

    cout << "  -";
    for (int i=0; i < small; i++) {
        cout << "|---";
    }
    cout << "|" << endl;
    }


    else if(difficulty==MEDIUM){
        cout << "   ";
        for (int i=0; i < medium; i++) {
            cout << "|" << setw(2) << i+1<<setw(2);
        }
        cout << "|" << endl;
        cout << "  _";
        for (int i=0; i < medium; i++) {
            cout << "|___";
        }
        cout << "|" << endl;

        for (int i=0; i < medium; i++) {
            cout << setw(2) << i+1 << "|";
            for (int j = 0; j < medium; j++) {
                if(which==0){cout<<setw(2)<<gameBoard[i][j]<<"  ";}
                else if(which==1){cout<<setw(2)<<playerBoard[i][j]<<"  ";}
            }
            cout << "|" << endl;
        }

        cout << "  -";
        for (int i=0; i < medium; i++) {
            cout << "|---";
        }
        cout << "|" << endl;
    }
    else if(difficulty==HARD){
        cout << "   ";
        for (int i=0; i < large; i++) {
            cout << "| " << setw(2) << i+1;
        }
        cout << "|" << endl;
        cout << "  _";
        for (int i=0; i < large; i++) {
            cout << "|___";
        }
        cout << "|" << endl;

        for (int i=0; i < large; i++) {
            cout << setw(2) << i+1 << "|";
            for (int j = 0; j < large; j++) {
                if(which==0){cout<<setw(2)<<gameBoard[i][j]<<"  ";}
                else if(which==1){cout<<setw(2)<<playerBoard[i][j]<<"  ";}
            }
            cout << "|" << endl;
        }

        cout << "  -";
        for (int i=0; i < large; i++) {
            cout << "|---";
        }
        cout << "|" << endl;
    }




}

void Board::generateBoard() {
    srand(time(nullptr));



    if(difficulty==EASY){
        for(int i=0; i<=easyMine;){
            int row = rand()%small+1;
            int col = rand()%small+1;
            if(gameBoard[row][col]!='X'){
                gameBoard[row][col]='X';//set to mine 
                i++;
            }
            //this will only iterate i to the mine count if the rand generates an empty spot to place

        }
    }
    else if(difficulty==MEDIUM){
        for(int i=0; i<=medMine;){
            int row = rand()%medium+1;
            int col = rand()%medium+1;
            if(gameBoard[row][col]!='X'){
                gameBoard[row][col]='X';
                i++;
            }
        }
    }
    else if(difficulty==HARD){
        for(int i=0; i<=hardMine;){
            int row = rand()%large+1;
            int col = rand()%large+1;
            if(gameBoard[row][col]!='X'){
                gameBoard[row][col]='X';
                i++;
            }
        }
    }
}