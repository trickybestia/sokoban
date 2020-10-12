#include "KeyList.h"

bool KeyList::GetKeyState(sf::Keyboard::Key key)
{
	for (auto iter : this->pressedKeys)
		if (iter == key)
			return true;;

	return false;;
}
void KeyList::SetKeyState(sf::Keyboard::Key key, bool pressed)
{
	if (pressed)
		this->pressedKeys.push_back(key);
	else this->pressedKeys.remove(key);
}