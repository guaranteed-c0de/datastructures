using namespace std;
#include "MemoryGame.h"
#include <iostream>

int main() {
MemoryGame game;

/*game.displayTerminal()*/
initscr();            // start ncurses mode
    cbreak();             // disable line buffering
    noecho();             // don’t echo typed chars to the screen
    keypad(stdscr, TRUE); // enable arrow keys

    // Main game loop
    while (!game.allMatched()) {
        game.displayTerminalNcurses();  // draw the grid to the screen

        int row, col;
        mvprintw(LINES - 2, 0, "Enter row and col: ");  // print prompt
        refresh();

        scanw("%d %d", &row, &col);  // get input
        if (game.flipCard(row, col)) {
            game.checkMatch();
        }
    }

    clear();
    mvprintw(LINES / 2, (COLS - 20) / 2, "You win! Congratulations!");
    refresh();
    getch();   // wait for a key before exiting

    // End ncurses
    endwin();
//SFML version.
/*while(!game.allMatched()) {
  game.displayTerminal();
    
  int row, col;
    cout << "Enter x and y coordinates: ";
    cin >> col >> row;
    if(game.flipCard(row, col)) game.checkMatch();
}
    cout << "You win! Congratualtions!";  */
    return 0; 
}