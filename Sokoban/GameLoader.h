#pragma once
#include "Game.h"
#include <string>
#include <fstream>

class GameLoader
{
public:
	static Game* Load(std::wstring& filePath, int& sizeX, int& sizeY);
};