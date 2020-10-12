#include "GameRenderer.h"
#include "GameLoader.h"

int main()
{
	/*std::vector<Tile> map;
	for (int x = 0; x < MAP_SIZE; x++)
	{
		map.push_back(Tile(x, -1, Tile::Wall, true));
		map.push_back(Tile(x, MAP_SIZE, Tile::Wall, true));
	}
	for (int y = 0; y < MAP_SIZE; y++)
	{
		map.push_back(Tile(-1, y, Tile::Wall, true));
		map.push_back(Tile(MAP_SIZE, y, Tile::Wall, true));
	}

	map.push_back(Tile(5, 2, Tile::Wall, true));
	map.push_back(Tile(5, 6, Tile::Crate, true));
	map.push_back(Tile(5, 6, Tile::Crate, true));
	map.push_back(Tile(3, 4, Tile::Target, false));

	Game game(map.data(), map.size());*/

	std::wstring mapFile = L"map.txt";
	int mapSizeX;
	int mapSizeY;

	Game* game = GameLoader::Load(mapFile, mapSizeX, mapSizeY);
	GameRenderer renderer(game, sf::Vector2i(mapSizeX, mapSizeY), sf::Vector2i(32, 32));

	renderer.floor.loadFromFile("tiles.png", sf::IntRect(0, 0, 32, 32));
	renderer.crate.loadFromFile("tiles.png", sf::IntRect(32, 0, 32, 32));
	renderer.player.loadFromFile("tiles.png", sf::IntRect(64, 0, 32, 32));
	renderer.target.loadFromFile("tiles.png", sf::IntRect(96, 0, 32, 32));
	renderer.wall.loadFromFile("tiles.png", sf::IntRect(128, 0, 32, 32));
	renderer.fps = 7;

	renderer.Run();

	return 0;
}