#include"../../include/UI/Screen.h"

#include <iostream>


Screen::~Screen() {
	if (backgroundMusic.getStatus() == sf::Music::Status::Playing) {
		backgroundMusic.stop();
	}
}

void Screen::Pause() {
    isActive = false;
}

void Screen::Resume() {
    isActive = true;
}

bool Screen::isActiveScreen() const {
    return isActive;
}

bool Screen::isFinished() const {
    return finished;
}

ScreenStatus Screen::getNextScreen() const {
    return nextScreen;
}

void Screen::setActive(bool active) {
    isActive = active;
}

void Screen::setVolume(int vol) {
    Volume = vol;
    backgroundMusic.setVolume(Volume);
}
int Screen::getVolume() const {
    return Volume;
}

void Screen::loadBackground(const std::string& texturePath) {
    if (backgroundTexture.loadFromFile(texturePath)) {
        backgroundSprite.setTexture(backgroundTexture);
    }
    else {
        std::cout << "Failed to load background texture: " << texturePath << std::endl;
    }
}

void Screen::setBackgroundScale(float scaleX, float scaleY) {
   backgroundSprite.setScale(sf::Vector2f(scaleX, scaleY));
}

void Screen::loadFont(const std::string& fontPath) {
    if (!font.loadFromFile(fontPath)) {
        std::cout << "Failed to load font: " << fontPath << std::endl;
    }
}

void Screen::loadBackgroundMusic(const std::string& musicFilePath) {
    if (backgroundMusic.openFromFile(musicFilePath)) {
        backgroundMusic.setLoop(true);
        backgroundMusic.setVolume(Volume);
    }
    else {
        std::cout << "Failed to load background music: " << musicFilePath << std::endl;
    }
}

void Screen::playMusic() {
    backgroundMusic.play();
}

void Screen::stopMusic() {
    backgroundMusic.stop();
}

void Screen::drawBackground(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
}