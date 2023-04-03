#include "../headers/board.h"
#include "../headers/gameplay.h"
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

bool Play::start(){
    gameIntro();
    int gameDifficulty=selectDifficulty();
    //we have difficulty, now generate a board using it
    board = Board(gameDifficulty);
    board.generateBoard();
    
    int inputRow, inputCol;
    char action;
    bool gameOver=false;
    int bombs;

    while(!gameOver){
        cout<<"============================"<<endl;
        board.printBoard(1);
    
        while(true){
            cout << "Enter row and column (ex. 1 2): ";
            cin >> inputRow >> inputCol;
            if(validate(inputRow, inputCol)){
                break;
            }
            cout<<endl<<"Invalid coordinates"<<endl;
        }
        while(true){
            cout << "Enter action (O for open, F for flag, ? for mark for later, R to reset): ";
            cin >> action;
            action=toupper(action);
            if(action=='O'||action=='F'||action=='R'||action=='?'){
                break;
            }
            cout<<endl<<"Invalid action input"<<endl;
        }

        switch(action){
            case 'O':
            case 'o':
                    if(isCellBomb(inputRow,inputCol)){
                        return lose();
                    }
                    else{
                        revealSquare(inputRow,inputCol);
                    }
                break;
            case 'F':
            case 'f':
                    board.getPlayerBoard()[inputRow][inputCol]='F';
                    if(checkWin()){
                        return win();
                    }
                break;
            case '?':
                    board.getPlayerBoard()[inputRow][inputCol]='?';
                break;
            case 'R':
            case 'r':
                    board.getPlayerBoard()[inputRow][inputCol]='-';
                break;
            default: cout<<"unknown case"<<endl;
        }
    }
    board.getPlayerBoard().clear();
    board.getGameBoard().clear();
}

// Validates if tile at given row and column is a valid move
bool Play::validate(int row, int col) {
    
    int difficulty=board.getDifficulty();

    if(difficulty==EASY){
        if(row<=small&&col<=small&&row>0&&col>0){
            return true;
        }
    }
    else if(difficulty==MEDIUM){
        if(row<=medium&&col<=medium&&row>0&&col>0){
            return true;
        }
    }
    else if(difficulty==HARD){
        if(row<=large&&col<=large&&row>0&&col>0){
            return true;
        }
    }

    return false;
}

//Counts the number of bombs around a selected square
int Play::countBombs(int row, int col) {
    int count = 0;
    const vector<vector<char>>& board = this->board.getGameBoard();

    for (int i = max(1, row - 1); i <= min(MAXBOARD, row + 1); i++) {
        for (int j = max(1, col - 1); j <= min(MAXBOARD, col + 1); j++) {
            if (board[i][j] == 'X') {
                count++;
            }
        }
    }
    return count;
}

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
    
    if(board.getGameBoard()[row][col] == 'X'){
        return true;
    }
    return false;
}

// Marks the player board with the given type at the given row and column
void Play::markPlayerBoard(int row, int col, char type) {
    board.getPlayerBoard()[row][col]=type;
}

// Marks the game board with the given type at the given row and column
void Play::markGameBoard(int row, int col, char type) {
    if(board.getGameBoard()[row][col]!='X'){//dont want to overwrite the bombs, this is intended to be the board displayed when the player loses
        board.getGameBoard()[row][col]=type;
    }
}

int Play::selectDifficulty(){
    int choice;
    while (true) {
        cout << "Select a difficulty:" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice >= EASY && choice <= HARD) {
            break;
        }
        cout << "Invalid choice, please try again." << std::endl;
    }
    return choice;
}

bool Play::lose(){
    char input;
    cout << "Oops, you hit a mine! Game over."<<endl;
    cout << "Here is the final game board:"<<endl;
    board.printBoard(0);
    cout<<endl<<"Play Again? Y/N"<<endl;
    cin>>input;
    if(input=='Y'||input=='y'){
        return true;
    }
    return false;
}

bool Play::win(){
    char input;
    cout<<"Congratulations, you have cleared the minefield! You are a true champion!"<<endl;
    board.printBoard(1);
    cout<<endl<<"Play Again? Y/N"<<endl;
    cin>>input;
    if(input=='Y'||input=='y'){
        return true;
    }
    return false;
}


void Play::revealSquare(int row, int col){
    if(!validate(row,col)){
        return;
    }
    
    // cout << "Row: " << row << ", Col: " << col << endl;
    // cout << "Board size: " << board.getPlayerBoard().size() << endl;
    // cout << "Row size: " << board.getPlayerBoard()[row].size() << endl;

    if (board.getPlayerBoard()[row][col] != '-') {
        // Check if the square has already been revealed or flagged
        return;
    }
    if (board.getGameBoard()[row][col] == 'X') {
        // Check if the square contains a bomb
        return;
    }
    int numBombs = countBombs(row, col);

    board.getPlayerBoard()[row][col] = '0' + numBombs;
    if (numBombs == 0) {
        // Recursively reveal adjacent squares
        revealSquare(row-1, col-1);
        revealSquare(row-1, col);
        revealSquare(row-1, col+1);
        revealSquare(row, col-1);
        revealSquare(row, col+1);
        revealSquare(row+1, col-1);
        revealSquare(row+1, col);
        revealSquare(row+1, col+1);
    }
}
