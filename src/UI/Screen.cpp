#include"../../include/UI/Screen.h"
#include <iostream>


Screen::~Screen() {
	if (backgroundMusic.getStatus() == Music::Status::Playing) {
		backgroundMusic.stop();
	}
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
   backgroundSprite.setScale(Vector2f(scaleX, scaleY));
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

void Screen::draw(RenderWindow& window) {
    window.draw(backgroundSprite);
}


void Screen::setWindow(RenderWindow& window) {
    this->window = &window;
}


void Screen::setBackgroundSize(float targetWidth, float targetHeight) 
{
    sf::Vector2u texSize = backgroundTexture.getSize();
    float scaleX = targetWidth / texSize.x;
    float scaleY = targetHeight / texSize.y;
    setBackgroundScale(scaleX, scaleY);
}