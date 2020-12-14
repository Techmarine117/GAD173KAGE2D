#include "Tiles.h"

Tiles::Tiles(float tileWidth, float tileHeight)
{
	tileshap = new sf::RectangleShape();
	tileshap->setSize(sf::Vector2f(tileWidth, tileHeight));

}
void Tiles::setTile(sf::Vector2f pos)
{
	tileshap->setPosition(sf::Vector2f(pos.x, pos.y));
	active = true;

}
void Tiles::DisableTile()
{
	active = false;

}
void Tiles::setcolor(sf::Color color)
{
	tileshap->setFillColor(color);

}

