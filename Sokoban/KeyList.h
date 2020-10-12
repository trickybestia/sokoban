#pragma once
#include <list>
#include <SFML/Window/Keyboard.hpp>

class KeyList 
{
private:
	std::list<sf::Keyboard::Key> pressedKeys;
public:
	void SetKeyState(sf::Keyboard::Key key, bool pressed);
	bool GetKeyState(sf::Keyboard::Key key);
};