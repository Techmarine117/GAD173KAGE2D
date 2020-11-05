#include "example.h"

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	float winWidth = m_window.getSize().x;
	float winHeight = m_window.getSize().y;
	tileWith = winWidth / GRID_ROW_COUNT;
	tileHeight = (winHeight * 0.5) / GRID_COLUMN_COUNT;

	
	// creates horizonal lines
	for (size_t i = 0; i < GRID_COLUMN_COUNT; i++) 
	{
		horizonalLines[i] = sf::RectangleShape();
		horizonalLines[i].setSize(sf::Vector2f(winWidth, 2));
		horizonalLines[i].setPosition(sf::Vector2f(0, tileHeight * (i + 1)));
		horizonalLines[i].setFillColor(sf::Color::Green);

	}

	// creates vertilcal lines
	for (size_t i = 0; i < GRID_ROW_COUNT; i++) 
	{
		vertilcalLines[i] = sf::RectangleShape();
		vertilcalLines[i].setSize(sf::Vector2f(winHeight * 0.5, 2));
		vertilcalLines[i].setRotation(90);
		vertilcalLines[i].setPosition(sf::Vector2f( tileWith * (i + 1),0));
		vertilcalLines[i].setFillColor(sf::Color::Green);



	}


	return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	for (size_t i = 0; i < GRID_COLUMN_COUNT; i++) 
	{
		m_window.draw(horizonalLines[i]);

	}

	for (size_t i = 0; i < GRID_ROW_COUNT; i++) 
	{
		m_window.draw(vertilcalLines[i]);
	}
	
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

