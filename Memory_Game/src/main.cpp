using namespace std;
#include "MemoryGame.h"
#include <iostream>

int main() {
MemoryGame game;


initscr();            
    cbreak();             // disable line buffering
    noecho();             // don’t echo typed chars to the screen
    keypad(stdscr, TRUE); // enable arrow keys

    // Main game loop
    
       // game.displayTerminalNcurses();  

//SFML version.
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
