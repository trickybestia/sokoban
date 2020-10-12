#pragma once
#include <list>
#include "Tile.h"

class Game
{
private:
	Tile* player;
	bool IsWin();
	bool win;
public:
	enum MoveDirection
	{
		Left,
		Right,
		Up,
		Down
	};
	Game(Tile* tiles, int tilesSize, bool autoAddPlayer);
	Game();
	bool GetWin();
	Tile* GetTile(int x, int y, Tile::TileType type);
	Tile* GetTile(int x, int y, bool solid);
	void MovePlayer(MoveDirection direction);
	std::list<Tile*> tiles;
	~Game();

	friend class GameLoader;
};