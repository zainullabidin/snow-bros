#include"../../../include/characters/projectile/Projectile.h"
#include <iostream>
using namespace std;



//constructor
Projectile::Projectile() : Volume(0),
	x(0), y(0), Vx(0), Vy(0), hitboxWidth(0), hitboxHeight(0),
	damage(0), duration(0), isActive(true), isPlayerProjectile(true) {

    if(soundEffect.loadFromFile("assets/sounds/powerup_claim.wav")) // need to correct
    {
        launchSound.setBuffer(soundEffect);          
    } 
    else
    cout << "Failed to load sound Projectile sound" << endl;
	
}

// sfml setting
void Projectile::setVolume(int vol) {
    Volume = vol;
    launchSound.setVolume(vol);
}
int Projectile::getVolume() const {
    return Volume;
}



Projectile::~Projectile() {}

void Projectile::playSound() {
    if (launchSound.getStatus() != Sound::Playing)
        launchSound.play();
}

void Projectile::stopSound() {
    launchSound.stop();
}


// getters 
float Projectile::getX() {
    return x;
}

float Projectile::getY() {
    return y;
}

float Projectile::getVx() {
    return Vx;
}

float Projectile::getVy() {
    return Vy;
}

float Projectile::getHitboxWidth() {
    return hitboxWidth;
}

float Projectile::getHitboxHeight() {
    return hitboxHeight;
}

int Projectile::getDamage() {
    return damage;
}

int Projectile::getDuration() {
    return duration;
}

bool Projectile::getIsActive() {
    return isActive;
}

bool Projectile::getIsPlayerProjectile() {
    return isPlayerProjectile;
}


// setters
void Projectile::setPosition(float newX, float newY) {
    x = newX;
    y = newY;
}

void Projectile::setVelocity(float newVx, float newVy) {
    Vx = newVx;
    Vy = newVy;
}

void Projectile::setHitboxSize(float newW, float newH) {
    hitboxWidth = newW;
    hitboxHeight = newH;
}

void Projectile::setDamage(int newDam) {
    damage = newDam;
}

void Projectile::setDuration(int newDur) {
    duration = newDur;
}

void Projectile::setIsActive(bool Action) {
    isActive = Action;
}

void Projectile::setIsPlayerProjectile(bool value) {
    isPlayerProjectile = value;
}

FloatRect Projectile::getHitbox() const {
    return FloatRect(x, y, hitboxWidth, hitboxHeight);
}

void Projectile::deactivate() {
    isActive = false;
}