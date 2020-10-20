#include "MessageBox.h"

void MessageBox::Show(sf::Font font, std::wstring text, sf::Color background)
{
	sf::Text message(text, font);
	message.setFillColor(sf::Color::Black);
	sf::FloatRect messageBounds = message.getLocalBounds();
	sf::RenderWindow window(sf::VideoMode(messageBounds.width + 50, messageBounds.height + 50), L"Сокобан");
	sf::Event event;
	while (window.isOpen())
	{
		window.clear(background);
		message.setPosition(sf::Vector2f((window.getSize().x - messageBounds.width) / 2, (window.getSize().y - message.getLocalBounds().height) / 2));
		window.draw(message);
		window.display();
		window.waitEvent(event);
		if (event.type == sf::Event::Closed)
			window.close();
	}
}