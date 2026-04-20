#include"../../../include/characters/enemy/Enemy.h"
#include <iostream>
using namespace std;

//===================================================================
// need inplementation by Z on bottom + add sound effect
//===================================================================

Enemy::Enemy() : Volume(0),
    state(EnemyState::MOVING),
    health(0), maxHealth(0), minScore(0), maxScore(0),
    hitsToEncase(0), snowAccumulation(0),
    gemDrop(0), x(0), y(0), Vx(0), Vy(0), hitboxWidth(0), hitboxHeight(0) 
{
    if (hitBuffer.loadFromFile("assets/sounds/enemy_hit.wav"))
    {
        hitSound.setBuffer(hitBuffer);
    }
    else
        cout << "Failed to load Enemy hit sound" << endl;
}

void Enemy::setVolume(int vol) {
    Volume = vol;
    hitSound.setVolume(Volume);
}
int Enemy::getVolume() const {
    return Volume;
}



void Enemy::playSound() {
    if (hitSound.getStatus() != sf::Sound::Playing)
        hitSound.play();
}

void Enemy::stopSound() {
    hitSound.stop();
}


Enemy::~Enemy() {}

float Enemy::getX() {
    return x;
}

float Enemy::getY() {
    return y;
}

void Enemy::setPosition(float newX, float newY) {
    x = newX;
    y = newY;
}

float Enemy::getVx() {
    return Vx;
}

float Enemy::getVy() {
    return Vy;
}

void Enemy::setVelocity(float vx, float vy) {
    Vx = vx;
    Vy = vy;
}

void Enemy::setHealth(int h) {
    health = h;
}

int Enemy::getHealth() {
    return health;
}

int Enemy::getGemDrop() {
    return gemDrop;
}

EnemyState Enemy::getState() {
    return state;
}

bool Enemy::canFly() {
    return false;
}

bool Enemy::canShoot() {
    return false;
}

bool Enemy::isBoss() {
    return false;
}

bool Enemy::isAlive() {
    return state != EnemyState::DEAD;
}
bool Enemy::isDead() {
    return state == EnemyState::DEAD;
}
bool Enemy::isRolling() {
    return state == EnemyState::ROLLING;
}
sf::FloatRect Enemy::getHitbox() const {
    return sf::FloatRect(x, y, hitboxWidth, hitboxHeight);
}


// Need implementation (To be done by Z)
	// void onEncased() {} 
	// void addSnow(float amount) {}
