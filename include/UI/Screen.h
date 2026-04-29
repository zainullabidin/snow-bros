#pragma once

#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "../main/Game_state.h"

using namespace std;
using namespace sf;

class Screen
{
protected:
	RenderWindow *window = nullptr;
	
	int Volume; 

    Font font;

    Texture backgroundTexture;
	Sprite backgroundSprite;
	
	Music backgroundMusic;

public:

	Screen() : Volume(100){}
	

	virtual ~Screen();

	//pure virtuals							
	virtual void draw(RenderWindow& window) = 0;									
	virtual GameState Update(float deltaTime, RenderWindow& window) = 0;									
	virtual void OnActivate() = 0;										
	virtual void OnExit() = 0;

	void setBackgroundSize(float targetWidth, float targetHeight);

	void setVolume(int vol);
	int getVolume() const;
	void setWindow(RenderWindow& window);
	
	// SFML components
	void loadBackground(const string& texturePath);
	void setBackgroundScale(float scaleX, float scaleY);
	void loadFont(const string& fontPath);
	void loadBackgroundMusic(const string& musicFilePath);
	void playMusic();
	void stopMusic();
};