#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "board.h"
class Play{
    Board board;
    Play(Board board);
    Play();
    //int pickTile();
    bool validate(int row, int col);
    int countBombs();
    bool checkWin();
    bool isCellBomb(int row, int col);
    void markPlayerBoard(int row, int col, char type);
    void markGameBoard(int row, int col, char type);
    void gameIntro();
    void start();
};



#endif