#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "board.h"
class Play{
    Board board;
    Play(Board board);
    Play();
    //int pickTile();
    bool validate(int row, int col);
    int countBombs(int row, int col);
    bool checkWin();
    bool isCellBomb(int row, int col);
    void markPlayerBoard(int row, int col, char type);
    void markGameBoard(int row, int col, char type);
    void gameIntro();
    bool start();
    int selectDifficulty();
    bool lose();
    bool win();
    void revealSquare(int row, int col);
};



#endif