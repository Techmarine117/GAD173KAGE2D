#pragma once

#include "app.h"
#include "Tiles.h"
#define GRID_ROW_COUNT 20
#define GRID_COLUMN_COUNT 20


class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();
	
	sf::Sprite *m_backgroundSprite;
	
	float tileWith;
	float tileHeight;

	sf::RectangleShape horizonalLines[GRID_COLUMN_COUNT];
	sf::RectangleShape vertilcalLines[GRID_ROW_COUNT];
};
