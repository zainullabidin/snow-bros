#include"../../../include/characters/powerup/PowerUp.h"

//==================================================================================
// needs implementation in update timer(to be done by Z) at bottom + set sound path
//==================================================================================

// constructor
PowerUp::PowerUp() : Volume(0.5f), 
fromShop(false), x(0), y(0), hitboxWidth(0), hitboxHeight(0),
    gemCost(0), duration(0), Collected(false), timeRemaining(0) 
{
    // simply load sound once in the constructor
    soundEffect.loadFromFile("assets/sounds/powerup_claim.wav"); // need to correct
    claimSound.setBuffer(soundEffect);
}

// sfml setting
void PowerUp::setVolume(int vol) {
    Volume = vol;
    claimSound.setVolume(Volume);
}

int PowerUp::getVolume() const {
    return Volume;
}


void PowerUp::playSound() {
    if (claimSound.getStatus() != Sound::Playing)
        claimSound.play();
}

void PowerUp::stopSound() {
    claimSound.stop();
}

PowerUp::~PowerUp() {}


// getters 
float PowerUp::getX() {
    return x;
}

float PowerUp::getY() {
    return y;
}

float PowerUp::getHitboxWidth() {
    return hitboxWidth;
}

float PowerUp::getHitboxHeight() {
    return hitboxHeight;
}

int PowerUp::getGemCost() {
    return gemCost;
}

int PowerUp::getDuration() {
    return duration;
}

bool PowerUp::getIsActive() {
    return Collected;
}

float PowerUp::getTimeRemaining() {
    return timeRemaining;
}

bool PowerUp::getFromShop() {
    return fromShop;
}


// setters
void PowerUp::setPosition(float newX, float newY) {
    x = newX;
    y = newY;
}

void PowerUp::setHitboxSize(float width, float height) {
    hitboxWidth = width;
    hitboxHeight = height;
}

void PowerUp::setIsActive(bool active) {
    Collected = active;
}

void PowerUp::setTimeRemaining(float time) {
    timeRemaining = time;
}

void PowerUp::setFromShop(bool value) {
    fromShop = value;
}


// methods
bool PowerUp::isPermanent() {
    return duration == 0;
}

bool PowerUp::isTemporary() {
    return duration > 0;
}

FloatRect PowerUp::getHitbox() {
    return FloatRect(x, y, hitboxWidth, hitboxHeight);
}




// void PowerUp::updateTimer() {
//     // Implementation for updateTimer will go here
// }