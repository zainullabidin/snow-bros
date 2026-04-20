#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace std;


enum class EnemyType { BOTOM, FOOGA, TORNADO,MOGERA, GAMAKICHI };
enum class EnemyState { MOVING, ENCASED, ROLLING, DEAD };

class Enemy
{
protected:
    
	sf::Texture enTexture; 
	sf::Sprite enSprite;	

	int Volume;
	sf::SoundBuffer hitBuffer;
	sf::Sound hitSound;

	EnemyState state;  // from enum

	int health;		
	int maxHealth;	

	int minScore, maxScore; 
	int hitsToEncase;   
	float snowAccumulation; 

	int gemDrop; 

	float x, y;   // position		
	float Vx, Vy;	// velocity
	float hitboxWidth, hitboxHeight;

public:

	Enemy() :
		state(EnemyState::MOVING),  // default state -> always moving (need to confirm)
		health(0), maxHealth(0), minScore(0), maxScore(0),
		hitsToEncase(0), snowAccumulation(0),
		gemDrop(0), x(0), y(0), Vx(0), Vy(0), hitboxWidth(0), hitboxHeight(0) {
	}
	
	virtual ~Enemy();

	void playSound();
	void stopSound();

	//getters / setters 
	float getX();
	float getY();
	void setPosition(float newX, float newY);

	float getVx();
	float getVy();
	void setVelocity(float vx, float vy);

	void setHealth(int h);
	int getHealth();
	int getGemDrop();
	EnemyState getState();

	int getVolume() const;
	void setVolume(int vol);



	// pure virtuals (must override) 

	virtual sf::Sprite getSprite() = 0;  
	virtual EnemyType getEnemyType() = 0;

	virtual void update(float deltatime) = 0; 
	virtual void draw(sf::RenderWindow& w) = 0; 
	virtual void TakeDamage(int amt) = 0; 
	virtual double getSpeed() = 0; 

	virtual int getScoreValue() = 0; 

	//virtuals (can override) 
	virtual bool canFly();
	virtual bool canShoot();
	virtual bool isBoss();

	//   common functions 
	bool isAlive();
	bool isDead();
	bool isRolling();


	// rolling action need to define here in base class 
	virtual void onEncased() ; 
	void addSnow(float amount) ;


	sf::FloatRect getHitbox() const;
};