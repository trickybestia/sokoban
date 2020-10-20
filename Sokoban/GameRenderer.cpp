#include "GameRenderer.h"

using namespace sf;

GameRenderer::GameRenderer(Game* game, sf::Vector2i renderSize, sf::Vector2i tileSize) : renderSize(renderSize), tileSize(tileSize)
{
	this->game = game;
	window = nullptr;
	fps = 1;
}
GameRenderer::~GameRenderer()
{
	delete window;
}
void GameRenderer::Run()
{
	int renderZoneX = renderSize.x * tileSize.x;
	int renderZoneY = renderSize.y * tileSize.y;
	window = new RenderWindow(VideoMode(renderZoneX, renderZoneY), L"Сокобан");
	Vector2u windowSize = window->getSize();
	window->setSize(Vector2u(windowSize.x * 1.5, windowSize.y * 1.5));
	Event event;
	Clock clock;

	floor.setRepeated(true);
	Sprite floorSprite(floor, IntRect(0, 0, renderZoneX, renderZoneY));
	Sprite wallSprite(wall, IntRect(0, 0, tileSize.x, tileSize.y));
	Sprite targetSprite(target, IntRect(0, 0, tileSize.x, tileSize.y));
	Sprite playerSprite(player, IntRect(0, 0, tileSize.x, tileSize.y));
	Sprite crateSprite(crate, IntRect(0, 0, tileSize.x, tileSize.y));

	while (window->isOpen() && !game->GetWin())
	{
		clock.restart();
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window->close();
				break;
			case Event::KeyPressed:
				keys.SetKeyState(event.key.code, true);
				break;
			case Event::KeyReleased:
				keys.SetKeyState(event.key.code, false);
				break;
			}
		}

		if (keys.GetKeyState(Keyboard::W) || keys.GetKeyState(Keyboard::Up))
			game->MovePlayer(Game::Up);
		if (keys.GetKeyState(Keyboard::A) || keys.GetKeyState(Keyboard::Left))
			game->MovePlayer(Game::Left);
		if (keys.GetKeyState(Keyboard::S) || keys.GetKeyState(Keyboard::Down))
			game->MovePlayer(Game::Down);
		if (keys.GetKeyState(Keyboard::D) || keys.GetKeyState(Keyboard::Right))
			game->MovePlayer(Game::Right);

		window->clear();
		window->draw(floorSprite);

		for (int i = 0; i <= Tile::Player; i++)
		{
			for (auto tile : game->tiles)
			{
				if (tile->type != i) continue;
				Sprite* sprite = nullptr;
				switch (tile->type)
				{
				case Tile::Player:
					sprite = &playerSprite;
					break;
				case Tile::Wall:
					sprite = &wallSprite;
					break;
				case Tile::Target:
					sprite = &targetSprite;
					break;
				case Tile::Crate:
					sprite = &crateSprite;
					break;
				}
				sprite->setPosition(Vector2f(tileSize.x * tile->x, tileSize.y * tile->y));
				window->draw(*sprite);
			}
		}
		window->display();
		sleep(milliseconds(1000.0 / fps) - clock.getElapsedTime());
	}
	window->clear(Color::Yellow);
	Text winMessage(L"Вы победили!", font);
	winMessage.setFillColor(Color::Black);
	winMessage.move(Vector2f((renderZoneX - winMessage.getLocalBounds().width) / 2, (renderZoneY - winMessage.getLocalBounds().height) / 2));
	window->draw(winMessage);
	window->display();
	while (window->isOpen())
	{
		while (window->waitEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window->close();
			}
		}
	}
}