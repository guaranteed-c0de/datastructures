#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include "LinkedList.h"
#include <SFML/Graphics.hpp>
#ifndef MEMORYGAME_H
#define MEMORYGAME_H
class MemoryGame{
    private:
        LinkedList cards;
        int rows, cols;
        int firstFlipIndex = -1;
        int secondFlipIndex = -1;
    void initializeDeck() {
        char values[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
        for (char val : values) {
            cards.insert(Card(val));
            cards.insert(Card(val));
        }
    } 
    void shuffle() {
        std:: vector <Card> temp;
        for (int i = 0; i<cards.size(); i++)
        {
            temp.push_back(cards.getAt(i));
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(temp.begin(), temp.end(), g);
        while (cards.size() > 0) cards.removeAt(0);
        for (const auto& c: temp) cards.insert(c);
    }
    public:
        MemoryGame(int r = 4, int c = 4) : rows(r), cols(c) {
        initializeDeck();
        shuffle();
    }
        bool flipCard(int row, int col) {
            int index = row * cols + col;
            if(index < 0 || index >= cards.size() || cards.getAt(index).isFaceUp || cards.getAt(index).isMatched)
            {
                return false;
            }
            cards.getAt(index).isFaceUp = true;

            if (firstFlipIndex == -1)
                {
                    firstFlipIndex = index;
                }
            else {
                secondFlipIndex = index;
                return true; //Pair flipped, check match next.
            }
            return false;
        }
        bool checkMatch() {
            if(firstFlipIndex == -1 || secondFlipIndex == -1) 
            {
                return false;
            }
            Card& c1 = cards.getAt(firstFlipIndex);
            Card& c2 = cards.getAt(secondFlipIndex);
            if (c1.value == c2.value)
            {
                c1.isMatched = true;
                c2.isMatched = true;
            }
            else {
                c1.isFaceUp = false;
                c2.isFaceUp = false;
            }
            firstFlipIndex = secondFlipIndex = -1;
            return allMatched();
        }
        bool allMatched() {
            for (int i = 0; i < cards.size(); i++) {
                if (!cards.getAt(i).isMatched)
                {
                    return false;
                }
                return true;
            }
        }
        //Display functions go here.
    void displayTerminal() {
        std:: cout << "Memory Game Grid:\n";
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int idx = r * cols + c;
                Card& card = cards.getAt(idx);
                if (card.isMatched) {
                    std:: cout << "[ ]";
                } else if (card.isFaceUp) {
                    std::cout << "[" << card.value << "]";
                } else {
                    std:: cout << "[*] ";
                }
            }
            std:: cout << "\n";
        }
    }
};

#endif //MEMORYGAME_H