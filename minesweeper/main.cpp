


//#include "headers/board.h"
#include "board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>



using namespace std;
int main(int argc, char* argv[]){
    cout<<"Testing output before"<<endl;

    Board board(HARD);
    board.generateBoard();
    cout<<"board generated"<<endl;
    board.printBoard(0);
    cout<<"testing output after"<<endl;
}