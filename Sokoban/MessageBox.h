#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class MessageBox
{
public:
	static void Show(sf::Font font, std::wstring text, sf::Color background);
};