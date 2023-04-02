//#include "../headers/board.h"
#include "board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
/*
Reminder, 2d columns are id[row][column]
*/
    int small = 9;
    int medium = 16;
    int large = 24;

    int easyMine=10;
    int medMine=40;
    int hardMine=120;

Board::Board(int difficulty){
//0 easy, 1 medium, 2 hard
//board is pregenerated 25x25 empty chars, we will never use the 0 column
//10 mines, 40 mines, 120 mines
    this->difficulty=difficulty;
}

void Board::printBoard(int which) {
    // Code to print the game board
    //0 is game board
    //1 is player board

    if(difficulty==EASY){
        for(int i=1;i<=small;i++){
            for (int j=1; j<=small;j++){
                if(which==0){cout<<gameBoard[i][j];}
                else if(which==1){cout<<playerBoard[i][j];}
            }
        }
    }
    else if(difficulty==MEDIUM){
        for(int i=1;i<=medium;i++){
            for (int j=1; j<=medium;j++){
                if(which==0){cout<<gameBoard[i][j];}
                else if(which==1){cout<<playerBoard[i][j];}
            }
        }
    }
    else if(difficulty==HARD){
        for(int i=1;i<=large;i++){
            for (int j=1; j<=large;j++){
                if(which==0){cout<<gameBoard[i][j];}
                else if(which==1){cout<<playerBoard[i][j];}
            }
        }
    }

}

void Board::generateBoard() {
    srand(time(nullptr));



    if(difficulty==EASY){
        for(int i=1; i<=easyMine;){
            int row = rand()%small+1;
            int col = rand()%small+1;
            if(gameBoard[row][col]=='\0'){//if the mine spot is null
                gameBoard[row][col]='*';//set to mine 
                i++;
            }
            //this will only iterate i to the mine count if the rand generates an empty spot to place

        }
    }
    else if(difficulty==MEDIUM){
        for(int i=1; i<=medMine;){
            int row = rand()%medium+1;
            int col = rand()%medium+1;
            if(gameBoard[row][col]=='\0'){
                gameBoard[row][col]='*';
                i++;
            }
        }
    }
    else if(difficulty==HARD){
        for(int i=1; i<=hardMine;){
            int row = rand()%medium+1;
            int col = rand()%medium+1;
            if(gameBoard[row][col]=='\0'){
                gameBoard[row][col]='*';
                i++;
            }
        }
    }
}