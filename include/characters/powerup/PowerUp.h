
#pragma once
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace std;


enum class PowerUpType { SNOWBALL_BOOST, SPEED_BOOST, BALLOON_MODE, DISTANCE_INCREASE, EXTRA_LIFE };

class PowerUp
{
protected:
	
	sf::Texture puTexture;
	sf::Sprite puSprite;

    int Volume;
	sf::SoundBuffer soundEffect;
	sf::Sound claimSound;

	bool fromShop; 

	float x, y;
	float hitboxWidth, hitboxHeight;

	int gemCost;
	float duration;
	
	bool Collected;
	float timeRemaining;


public:
    PowerUp() ;

	virtual ~PowerUp();

    void playSound();
    void stopSound();

    // getters 
	float getX();
	float getY();

	float getHitboxWidth();
	float getHitboxHeight();

	int getGemCost();
	int getDuration();
	
	bool getIsActive();
	float getTimeRemaining();

	bool getFromShop();
	int getVolume() const;


	//setters 
    void setVolume(int vol);
	void setPosition(float newX, float newY);
	void setHitboxSize(float width, float height);

	void setIsActive(bool active);
	void setTimeRemaining(float time);

	void setFromShop(bool value);



	// pure virtuals (Must override)
	
	virtual PowerUpType getPowerUpType() = 0; 
	virtual const sf::Sound& getClaimSound() = 0;	

	virtual void draw(sf::RenderWindow& w) = 0; 
	virtual void Apply() = 0; 
	virtual void Remove() = 0; //  for temporary



	//common characteristics 
    virtual void Update(float deltaTime) = 0; 

    bool isPermanent();
	bool isTemporary();

	void updateTimer();  
	sf::FloatRect getHitbox();

};