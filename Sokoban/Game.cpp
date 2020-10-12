#include "Game.h"

Game::Game(Tile* tiles, int tilesSize, bool autoAddPlayer)
{
	win = false;
	bool hasPlayer = false;
	for (int i = 0; i < tilesSize; i++)
	{
		Tile* tile = new Tile(tiles[i]);
		this->tiles.push_back(tile);
		if (tiles[i].type == Tile::Player)
		{
			hasPlayer = true;
			player = tile;
		}
	}
	if (!hasPlayer && autoAddPlayer)
	{
		player = new Tile(0, 0, Tile::Player, true);
		this->tiles.push_back(player);
	}
}
Game::Game() : Game(nullptr, 0, false) {}
bool Game::GetWin()
{
	return win;
}
Tile* Game::GetTile(int x, int y, bool solid)
{
	for (auto tile : tiles)
	{
		if (tile->x == x && tile->y == y && tile->solid == solid)
			return tile;
	}
	return nullptr;
}
Tile* Game::GetTile(int x, int y, Tile::TileType type)
{
	for (auto tile : tiles)
	{
		if (tile->x == x && tile->y == y && tile->type == type)
			return tile;
	}
	return nullptr;
}
void Game::MovePlayer(MoveDirection direction)
{
	int xMove = 0;
	int yMove = 0;

	switch (direction)
	{
	case MoveDirection::Left:
		xMove = -1;
		break;
	case MoveDirection::Right:
		xMove = 1;
		break;
	case MoveDirection::Up:
		yMove = -1;
		break;
	case MoveDirection::Down:
		yMove = 1;
		break;
	}

	int newX = player->x + xMove;
	int newY = player->y + yMove;
	Tile* tile = GetTile(newX, newY, true);
	if (tile)
	{
		if (tile->type == Tile::Wall)
			return;
		if (tile->type == Tile::Crate)
		{
			if (GetTile(newX + xMove, newY + yMove, true))
				return;

			tile->x = newX + xMove;
			tile->y = newY + yMove;

			win = IsWin();
		}
	}
	player->x = newX;
	player->y = newY;
}
bool Game::IsWin()
{
	for (auto crate : tiles)
	{
		if (crate->type != Tile::Target) continue;
		if (!GetTile(crate->x, crate->y, Tile::Crate))
			return false;
	}
	return true;
}
Game::~Game()
{
	for (auto tile : tiles)
	{
		delete tile;
	}
}