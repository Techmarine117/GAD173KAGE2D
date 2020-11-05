#pragma once
#include<SFML/Graphics.hpp>
class Tiles
{
public:
	bool active;
	sf::RectangleShape* tileshap;

	Tiles(float tileWidth, float tileHeight);

	void Tiles::setcolor(sf::Color color);
	void Tiles::setTile(sf::Vector2f pos);
	void Tiles::DisableTile();




};

