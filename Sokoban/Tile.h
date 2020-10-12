#pragma once

struct Tile
{
	enum TileType
	{
		Wall,
		Player,
		Crate,
		Target
	};
	int x;
	int y;
	TileType type;
	bool solid;
	Tile(int x, int y, TileType type, bool solid);
	Tile();
};