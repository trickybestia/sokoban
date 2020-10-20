#pragma once

struct Tile
{
	enum TileType
	{
		Wall,
		Crate,
		Target,
		Player
	};
	int x;
	int y;
	TileType type;
	bool solid;
	Tile(int x, int y, TileType type, bool solid);
	Tile();
};