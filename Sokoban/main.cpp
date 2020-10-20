#include "GameRenderer.h"
#include "GameLoader.h"
#include "MessageBox.h"

int main()
{
	std::wstring mapFile = L"1.map";
	int mapSizeX;
	int mapSizeY;
	Game* game;
	int i = 2;
	sf::Font font;
	font.loadFromFile("Arial.ttf");
	while (game = GameLoader::Load(mapFile, mapSizeX, mapSizeY))
	{
		GameRenderer renderer(game, sf::Vector2i(mapSizeX, mapSizeY), sf::Vector2i(32, 32));

		renderer.floor.loadFromFile("tiles.png", sf::IntRect(0, 0, 32, 32));
		renderer.crate.loadFromFile("tiles.png", sf::IntRect(32, 0, 32, 32));
		renderer.player.loadFromFile("tiles.png", sf::IntRect(64, 0, 32, 32));
		renderer.target.loadFromFile("tiles.png", sf::IntRect(96, 0, 32, 32));
		renderer.wall.loadFromFile("tiles.png", sf::IntRect(128, 0, 32, 32));
		renderer.fps = 7;
		renderer.font = font;

		renderer.Run();

		if (!game->GetWin())
		{
			delete game;
			return 0;
		}
		mapFile = std::to_wstring(i) + L".map";
		i++;
	}
	MessageBox::Show(font, L"Вы прошли все уровни!", sf::Color::Yellow);

	return 0;
}