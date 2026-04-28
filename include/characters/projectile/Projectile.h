#pragma once
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace std;


enum class ProjectileType { SNOWBALL, KNIFE, ROCKET};

class Projectile
{
protected:
	
	sf::Texture tp; 
	sf::Sprite projectile; 

    int Volume;
	sf::SoundBuffer soundEffect; 
	sf::Sound launchSound; 

	float x, y; 
	float Vx, Vy;
	float hitboxWidth, hitboxHeight; 

	int damage; 
	int duration; 

	bool isActive; 
	bool isPlayerProjectile; 

public:
	Projectile();

	virtual ~Projectile();



    void playSound();

    void stopSound();

	// getters

	float getX();
	float getY();
	float getVx();
	float getVy();
	float getHitboxWidth();
	float getHitboxHeight();
	int getDamage();
	int getDuration();
	bool getIsActive();
	bool getIsPlayerProjectile();

    int getVolume() const;

	//  setters 

    void setVolume(int vol);
	void setPosition(float newX, float newY);
	void setVelocity(float newVx, float newVy);
	void setHitboxSize(float newW, float newH);
	void setDamage(int newDam);
	void setDuration(int newDur);
	void setIsActive(bool Action);
	void setIsPlayerProjectile(bool value);

	// pure virtuals

	virtual ProjectileType getType() const = 0; 

	virtual sf::Sprite getSprite() = 0; 
	virtual sf::Sound getLaunchSound() = 0; 

	virtual void update(float deltaTime) = 0;	
	virtual void draw(sf::RenderWindow& w) = 0;	

    // decision needed for argument
	virtual void onHit() = 0;		// collision

	
    // Common functions
		
	sf::FloatRect getHitbox() const;
	void deactivate();


};