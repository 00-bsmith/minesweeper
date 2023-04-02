#ifndef BOARD_H
#define BOARD_H

#define EASY 0 //9x9 board, 10 mines
#define MEDIUM 1 //16x16 board 40 mines
#define HARD 2 //24x24 board 120 mines
#define MAXBOARD 25
class Board{
    char gameBoard[MAXBOARD][MAXBOARD];
    char playerBoard[MAXBOARD][MAXBOARD];
    int difficulty;
    public:
        void printBoard(int which);
        void generateBoard();
        Board(int difficulty);
};
// some declarations in
// the header file.
#endif