#include "board.h"
#include "gameplay.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>


using namespace std;




Play::Play(){};
Play::Play(Board board){
    this->board=board;
}

void Play::gameIntro(){
    cout << "Welcome to Minesweeper!\n";
    cout << "Uncover all the squares that do not contain a mine.\n";
    cout << "To uncover a square, type the row and column of the square.\n";
    cout << "For example, to uncover the square in the first row and second column, type 1 2.\n";
    cout << "If you uncover a square with a mine, the game is over!\n";
    cout << "If you uncover all the squares that do not contain a mine, you win!\n";
    
}

void Play::start(){

}

// Validates if tile at given row and column is a valid move
bool Play::validate(int row, int col) {
    
    int difficulty=board.getDifficulty();

    if(difficulty==EASY){
        if(row<=small&&col<=small){
            return true;
        }
    }
    else if(difficulty==MEDIUM){
        if(row<=medium&&col<=medium){
            return true;
        }
    }
    else if(difficulty==HARD){
        if(row<=large&&col<=large){
            return true;
        }
    }

    return false;
}

// Counts the number of bombs on the board
// int Play::countBombs() {
//     // TODO: Implement
// }

// Checks if the player has won the game
bool Play::checkWin() {
    // method, check playerBoard for flags (F) and see if all flags line up with bombs (X)
    for (int i = 1; i <= small; i++) {
        for (int j = 1; j <= small; j++) {
            if (board.getPlayerBoard()[i][j] == 'F' && board.getGameBoard()[i][j] != 'X') {
                // If player has marked flag on wrong position
                return false;
            }
            if (board.getPlayerBoard()[i][j] != 'F' && board.getGameBoard()[i][j] == 'X') {
                // If player has not marked flag on a bomb
                return false;
            }
        }
    }
    return true;
}


// Checks if cell at given row and column is a bomb
bool Play::isCellBomb(int row, int col) {
    // TODO: Implement
    return false;
}

// Marks the player board with the given type at the given row and column
void Play::markPlayerBoard(int row, int col, char type) {
    // TODO: Implement
}

// Marks the game board with the given type at the given row and column
void Play::markGameBoard(int row, int col, char type) {
    // TODO: Implement
}


