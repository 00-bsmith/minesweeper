


//#include "headers/board.h"
#include "board.h"
#include <stdio.h>



using namespace std;
int main(int argc, char* argv[]){

    Board board(EASY);
    board.generateBoard();
    board.printBoard(0);
}