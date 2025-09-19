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
    void displaySFML() {
        sf:: RenderWindow window(sf:: VideoMode(400, 400), "Memory Game");
        sf:: Font font;
        if(!font.loadFromFile("arial.ttf")) {/* Handle error*/}

        while (window.isOpen()) {
            sf:: Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf:: Event::Closed) window.close();
                if (event.type == sf::Event::MouseButtonPressed) {
                    int x = event.mouseButton.x /100; //Assuming 100px per card.
                    int y = event.mouseButton.y/100;
                    if(flipCard(y, x)) checkMatch(); //y=row, x=col
                }
            }
            window.clear();
            for(int r = 0; r < rows; r++){
                for (int c = 0; c<cols; c++) {
                    int idx = r*cols + c;
                    Card& card = cards.getAt(idx);

                    sf::RectangleShape rect(sf::Vector2f(90, 90));
                    rect.setPosition(c * 100 + 5, r*100 + 5);
                    rect.setFillColor(card.isMatched ? sf::Color::Transparent :
                (card.isFaceUp ? sf::Color::White : sf::Color::Blue));
                        if(!card.isMatched) window.draw(rect);

                        if(card.isFaceUp && !card.isMatched) {
                            sf:: Text text(std::string(1, card.value), font, 50);
                            text.setPosition(c*100 + 30, r*100 + 20);
                            text.setFillColor(sf::Color::Black);
                            window.draw(text);
                        }

                }
            }
            window.display();

            if(allMatched()) {
                //Draw win message
                sf::Text winText("You Win!", font, 50);
                winText.setPosition(100, 180);
                window.draw(winText);
                window.display();
                sf::sleep(sf::seconds(3));
                window.close();
            }
        }
    }
};

#endif //MEMORYGAME_H