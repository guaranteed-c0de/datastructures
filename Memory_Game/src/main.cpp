using namespace std;
#include "MemoryGame.h"
#include <iostream>

int main() {
MemoryGame game;
//For terminal:
while(!game.allMatched()) {
    game.displayTerminal();
    int row, col;
    cout << "Enter x and y coordinates: ";
    cin >> row >> col;
    if(game.flipCard(row, col)) game.checkMatch();
}
    cout << "You win! Congratualtions!";
    return 0;
}