#ifndef BOARD_H
#define BOARD_H

#include <vector>
#define EASY 1 //9x9 board, 10 mines
#define MEDIUM 2 //16x16 board 40 mines
#define HARD 3 //24x24 board 120 mines
#define MAXBOARD 25
using namespace std;

    const int small = 9;
    const int medium = 16;
    const int large = 24;

    const int easyMine=10;
    const int medMine=40;
    const int hardMine=120;

class Board{
   // char gameBoard[MAXBOARD][MAXBOARD];
   // char playerBoard[MAXBOARD][MAXBOARD];
    vector<vector<char>> gameBoard;
    vector<vector<char>> playerBoard;
    int difficulty;
    public:
        void printBoard(int which);
        void generateBoard();
        Board(int difficulty);
        Board();
        int getDifficulty();
        vector<vector<char>>& getGameBoard();
        vector<vector<char>>& getPlayerBoard();
};
// some declarations in
// the header file.
#endif