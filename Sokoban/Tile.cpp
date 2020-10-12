#include "Tile.h"

Tile::Tile(int x, int y, TileType type, bool solid)
{
	this->x = x;
	this->y = y;
	this->type = type;
	this->solid = solid;
}
Tile::Tile() {}