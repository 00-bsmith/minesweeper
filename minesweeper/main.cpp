


//#include "headers/board.h"
#include "headers/board.h"
#include "gameplay.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>



using namespace std;
int main(int argc, char* argv[]){
    bool keepPlaying=true;
    Play play;
    while(keepPlaying){
        keepPlaying= play.start();
    }
}