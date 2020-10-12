#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "KeyList.h"

class GameRenderer
{
private:
	Game* game;
	KeyList keys;
	sf::RenderWindow* window;
	const sf::Vector2i renderSize;
	const sf::Vector2f tileSize;
public:
	sf::Texture player;
	sf::Texture crate;
	sf::Texture wall;
	sf::Texture floor;
	sf::Texture target;
	int fps;
	GameRenderer(Game* game, sf::Vector2i renderSize, sf::Vector2i tileSize);
	void Run();
	~GameRenderer();
};