#include "GameEditor.h"
#include <math.h>

GameEditor::GameEditor() : Scenes()
{
}

GameEditor::~GameEditor()
{
}

GameEditor& GameEditor::inst()
{
	static 	GameEditor s_instance;
	return s_instance;
}

void 	GameEditor::loadTilemap()
{
	for (size_t i = 0; i < MAX_GRID_INDEX; i++)
	{
		int y = i / GRID_ROW_COUNT;
		int x = i - y * GRID_ROW_COUNT;


		switch (cellMap[i])
		{
		case 0:
			if (tiles[i] != nullptr && tiles[i]->active)
			{
				tiles[i]->DisableTile();

			}
			break;
		case 1:
			if (tiles[i] != nullptr)
			{

				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::White);
				cellMap[i] = 1;

			}
			else
			{
				tiles[i] = new Tiles(tileWidth, tileHeight);
				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::White);
				cellMap[i] = 1;


			}
			break;
		case 2:
			if (tiles[i] != nullptr)
			{

				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Red);
				cellMap[i] = 2;

			}
			else
			{
				tiles[i] = new Tiles(tileWidth, tileHeight);
				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Red);
				cellMap[i] = 2;


			}
			break;
		case 3:
			if (tiles[i] != nullptr)
			{

				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Magenta);
				cellMap[i] = 3;

			}
			else
			{
				tiles[i] = new Tiles(tileWidth, tileHeight);
				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Magenta);
				cellMap[i] = 3;


			}
			break;
		case 4:
			if (tiles[i] != nullptr)
			{

				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Blue);
				cellMap[i] = 4;

			}
			else
			{
				tiles[i] = new Tiles(tileWidth, tileHeight);
				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Blue);
				cellMap[i] = 4;


			}
			break;
		case 5:
			if (tiles[i] != nullptr)
			{

				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Cyan);
				cellMap[i] = 5;

			}
			else
			{
				tiles[i] = new Tiles(tileWidth, tileHeight);
				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Cyan);
				cellMap[i] = 5;


			}
			break;
		case 6:
			if (tiles[i] != nullptr)
			{

				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Yellow);
				cellMap[i] = 6;

			}
			else
			{
				tiles[i] = new Tiles(tileWidth, tileHeight);
				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Yellow);
				cellMap[i] = 6;


			}
			break;
		case 7:
			if (tiles[i] != nullptr)
			{

				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Black);
				cellMap[i] = 7;

			}
			else
			{
				tiles[i] = new Tiles(tileWidth, tileHeight);
				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Black);
				cellMap[i] = 7;


			}
			break;
		case 8:
			if (tiles[i] != nullptr)
			{

				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Green);
				cellMap[i] = 8;

			}
			else
			{
				tiles[i] = new Tiles(tileWidth, tileHeight);
				tiles[i]->setTile(sf::Vector2f(x * tileWidth, y * tileHeight));
				tiles[i]->setcolor(sf::Color::Green);
				cellMap[i] = 8;


			}
			break;
		}

	}

}

bool 	GameEditor::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window->getSize().x) / resolution.x, float(m_window->getSize().y) / resolution.y);

	float winWidth = m_window->getSize().x;
	float winHeight = m_window->getSize().y;
	tileWidth = winWidth / GRID_ROW_COUNT;
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
		vertilcalLines[i].setPosition(sf::Vector2f(tileWidth * (i + 1), 0));
		vertilcalLines[i].setFillColor(sf::Color::Green);



	}


	return true;
}

void 	GameEditor::update(float deltaT)
{
	sf::Vector2f mousePosition = (sf::Vector2f)sf::Mouse::getPosition(*m_window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window->hasFocus())
	{
		
	}

	ImGui::Begin("Kage2D");
	if (ImGui::Button("Exit"))
	{
		
	}
	ImGui::End();
	int newMouseX = mousePosition.x / tileWidth;
	int newMouseY = mousePosition.y / tileHeight;
	if (newMouseX <= 0)
		newMouseX = 0;
	if (newMouseX >= GRID_ROW_COUNT - 1)
		newMouseX = GRID_ROW_COUNT - 1;

	if (newMouseY <= 0)
		newMouseY = 0;
	if (newMouseY >= GRID_COLUMN_COUNT - 1)
		newMouseY = GRID_COLUMN_COUNT - 1;


	// keyboard presses
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		selectedTileType = 1;
		selectedColor = sf::Color::White;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		selectedTileType = 2;
		selectedColor = sf::Color::Red;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		selectedTileType = 3;
		selectedColor = sf::Color::Magenta;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		selectedTileType = 4;
		selectedColor = sf::Color::Blue;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		selectedTileType = 5;
		selectedColor = sf::Color::Cyan;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		selectedTileType = 6;
		selectedColor = sf::Color::Yellow;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		selectedTileType = 7;
		selectedColor = sf::Color::Black;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		selectedTileType = 8;
		selectedColor = sf::Color::Green;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		loadScene("file");
		loadTilemap();


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		saveScene("file");

	}









	if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		int index = newMouseY * GRID_ROW_COUNT + newMouseX;
		if (tiles[index] != nullptr)
		{
			tiles[index]->setTile(sf::Vector2f(newMouseX * tileWidth, newMouseY * tileHeight));
			tiles[index]->setcolor(selectedColor);
			cellMap[index] = selectedTileType;


		}
		else
		{
			tiles[index] = new Tiles(tileWidth, tileHeight);
			tiles[index]->setTile(sf::Vector2f(newMouseX * tileWidth, newMouseY * tileHeight));
			tiles[index]->setcolor(selectedColor);
			cellMap[index] = selectedTileType;

		}


	}
}

void 	GameEditor::render()
{
	m_window->draw(*m_backgroundSprite);
	for (size_t i = 0; i < GRID_COLUMN_COUNT; i++)
	{
		m_window->draw(horizonalLines[i]);

	}

	for (size_t i = 0; i < GRID_ROW_COUNT; i++)
	{
		m_window->draw(vertilcalLines[i]);
	}

	for (size_t i = 0; i < GRID_ROW_COUNT * GRID_COLUMN_COUNT; i++)
	{
		if (tiles[i] != nullptr && tiles[i]->active)
		{
			m_window->draw(*tiles[i]->tileshap);
		}
	}

}

void 	GameEditor::cleanup()
{
	delete m_backgroundSprite;
}


void 	GameEditor::saveScene(std::string fileName)
{
	Save Saving;
	std::ostringstream os;
	for (int i : cellMap)
	{
		os << i;

	}

	std::string str(os.str());
	Saving.Saved(fileName, str);

}

void 	GameEditor::loadScene(std::string fileName)
{
	Save loader;
	std::string data = loader.Load(fileName);

	for (size_t i = 0; i < 400; i++)
	{
		char val = data.at(i);
		int num = val - 48;
		switch (num)
		{
		case 0:
			cellMap[i] = 0;
			break;
		case 1:
			cellMap[i] = 1;
			break;
		case 2:
			cellMap[i] = 2;
			break;
		case 3:
			cellMap[i] = 3;
			break;
		case 4:
			cellMap[i] = 4;
			break;
		case 5:
			cellMap[i] = 5;
			break;
		case 6:
			cellMap[i] = 6;
			break;
		case 7:
			cellMap[i] = 7;
			break;
		case 8:
			cellMap[i] = 8;
			break;


		default:
			std::cout << num;
			break;
		}

	}

}


