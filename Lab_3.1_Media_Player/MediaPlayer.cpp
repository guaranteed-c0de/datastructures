#include "MediaPlayer.h"
#include <filesystem> //For directory iteration (C++17)

MediaPlayer :: MediaPlayer(): window(sf::VideoMode(800,600), "SFML Media Player"),
                              currentIndex(0), isPlaying(false) {
    if (!font.loadFromFile("arial.ttf")) { //Download a free font or use system default
        //Handle error
    }   
    //Initialize GUI elements...
    currentSongText.setFont(font);
    currentSongText.setString("No song loaded");
    currentSongText.setPosition(10, 10);
                              }
    void MediaPlayer :: run() {
        while (window.isOpen()) {
            handleEvents();
            update();
            render();
        }
    }

    void MediaPlayer::handleEvents() {
        sf:: Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //Handle button clicks (e.g., if mouse intersects playButton)
            if(event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (playButton.getGlobalBounds().contains(mousePos)) {
                    if (isPlaying) {
                        music.pause();
                    }
                    else {
                        music.play();
                    }
                    isPlaying = !isPlaying;
                }
            }
        }
    }

    void MediaPlayer::update() {
        if (playlist.getLength() > 0)
    }