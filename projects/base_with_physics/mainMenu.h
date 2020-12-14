#pragma once
#include "app.h"
#include "kage2dutil/physics.h"
#include"Scenes.h"
class mainMenu : public Scenes
{
public:
	mainMenu();
	virtual ~mainMenu();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	bool ismainMenu;
	int mainOffset;
	int textOffset;
	bool mouseWasPressd = false;
	sf::Vector2f WindowCenter;
	sf::Text mainText[4];
	sf::Font font;

	sf::Sprite* m_backgroundSprite;


};

