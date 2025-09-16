#ifndef CARD_H
#define CARD_H
struct Card {
char value;
bool isFaceUp;
bool isMatched;
Card(char val) : value(val), isFaceUp(false), isMatched(false){}
};
#endif //CARD_H
