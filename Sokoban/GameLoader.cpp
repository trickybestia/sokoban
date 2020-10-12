#include "GameLoader.h"

using namespace std;

Game* GameLoader::Load(wstring& filePath, int& sizeX, int& sizeY)
{
	Game* game = new Game();

	ifstream file(filePath);

	file >> sizeX;
	file >> sizeY;

	for (int x = 0; x < sizeX; x++)
	{
		game->tiles.push_back(new Tile(x, -1, Tile::Wall, true));
		game->tiles.push_back(new Tile(x, sizeY, Tile::Wall, true));
	}
	for (int y = 0; y < sizeY; y++)
	{
		game->tiles.push_back(new Tile(-1, y, Tile::Wall, true));
		game->tiles.push_back(new Tile(sizeX, y, Tile::Wall, true));
	}

	string line;
	getline(file, line);
	for (int y = 0; getline(file, line); y++)
	{
		for (int x = 0; x < sizeX;x++)
		{
			switch (line[x])
			{
			case 'w':
				game->tiles.push_back(new Tile(x, y, Tile::Wall, true));
				break;
			case 't':
				game->tiles.push_back(new Tile(x, y, Tile::Target, false));
				break;
			case 'c':
				game->tiles.push_back(new Tile(x, y, Tile::Crate, true));
				break;
			case 'p':
				Tile* player = new Tile(x, y, Tile::Player, true);
				game->tiles.push_back(player);
				game->player = player;
				break;
			}
		}
	}
	file.close();

	return game;
}