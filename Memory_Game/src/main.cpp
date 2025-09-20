using namespace std;
#include "MemoryGame.h"
#include <iostream>

int main() {
MemoryGame game;
//game.displayTerminalNcurses();

while(!game.allMatched()) {
    game.displayTerminal();
    int row, col;
    cout << "Enter x and y coordinates: ";
    cin >> col >> row;
    if(game.flipCard(row, col)) game.checkMatch();
}
    cout << "You win! Congratualtions!"; 
    return 0; 
}