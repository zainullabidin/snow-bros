#pragma once
#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
using namespace std;

enum class ScreenStatus { MAIN_MENU, CHARACTER_SELECT, GAME_PLAY, GAME_OVER,  LEADERBOARD, LEVEL_COMPLETE, PAUSE_MENU, SHOP, LOGIN };

class Screen
{
protected:
	
	int Volume; 

    sf::Font font;
    sf::Texture backgroundTexture;
	
	sf::Sprite backgroundSprite;
	sf::Music backgroundMusic;

	bool isActive; 
	bool finished;
	ScreenStatus nextScreen;

public:

	Screen() :
		isActive(false), Volume(100),
		finished(false), nextScreen(ScreenStatus::MAIN_MENU) {}

	virtual ~Screen();

	//pure virtuals
	virtual ScreenStatus getStatus() const = 0;									
	virtual void Render(sf::RenderWindow& window) = 0;
	virtual void HandleInput(const sf::Event& event) = 0;									
	virtual void Update(float deltaTime) = 0;									
	virtual void OnActivate() = 0;										
	virtual void OnExit() = 0;									

    // states
	virtual void Pause();
	virtual void Resume();

	// activation
	bool isActiveScreen()  const;
	bool isFinished() const;

	ScreenStatus getNextScreen() const;
	void setActive(bool active);
	void setVolume(int vol);
	int getVolume() const;

	// SFML components
	void loadBackground(const string& texturePath);
	void setBackgroundScale(float scaleX, float scaleY);
	void loadFont(const string& fontPath);
	void loadBackgroundMusic(const string& musicFilePath);
	void playMusic();
	void stopMusic();
	void drawBackground(sf::RenderWindow& window);
};