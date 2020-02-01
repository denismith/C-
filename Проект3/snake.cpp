#include <SFML/Graphics.hpp>

using namespace sf;

#define         OCTAGON_SPEED        1
int main()
{
	sf::Font font;
	sf::Text text;
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(400, 400), "SFML Works!");
	int x = window.getSize().x / 2.;
	int y = window.getSize().y / 2.;

	// Flags for key pressed
	bool upFlag = false;
	bool downFlag = false;
	bool leftFlag = false;
	bool rightFlag = false;

	sf::Clock timer;
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{

		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					// If escape is pressed, close the application
				case  sf::Keyboard::Escape: window.close(); break;

					// Process the up, down, left and right keys
				case sf::Keyboard::Up:     upFlag = true; break;
				case sf::Keyboard::Down:    downFlag = true; break;
				case sf::Keyboard::Left:    leftFlag = true; break;
				case sf::Keyboard::Right:   rightFlag = true; break;
				default: break;
				}
			}

			// If a key is released
			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
					// Process the up, down, left and right keys
				case sf::Keyboard::Up:     upFlag = false; break;
				case sf::Keyboard::Down:    downFlag = false; break;
				case sf::Keyboard::Left:    leftFlag = false; break;
				case sf::Keyboard::Right:   rightFlag = false; break;
				default: break;
				}
			}
				// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// Тогда закрываем его
				window.close();
		}
/////////////////////////////////////////////////////////////
		window.clear(Color(250, 220, 100, 0));
		// define a 120x50 rectangle
		sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
		// change the size to 100x100
		rectangle.setSize(sf::Vector2f(380.f, 380.f));
		rectangle.setFillColor(sf::Color(255, 248, 220));
		rectangle.setOutlineThickness(10.f);
		rectangle.setOutlineColor(sf::Color(100, 0, 0));
		// set the absolute position of the entity
		rectangle.setPosition(10.f, 10.f);
		window.draw(rectangle);

		sf::CircleShape octagon(5.f, 8);
		octagon.setFillColor(sf::Color(0, 100, 0));
		octagon.setOutlineThickness(2.f);
		octagon.setOutlineColor(sf::Color(0, 0, 0));
		octagon.setPosition(200.f, 200.f);
		
		if (x<10 || x>(int)window.getSize().x - 10 || y<10 || y>(int)window.getSize().y - 10) {
			font.loadFromFile("Anton-Regular.ttf");

			text.setFont(font); // font is a sf::Font

			// set the string to display
			text.setString("Game Over");

			// set the character size
			text.setCharacterSize(50); // in pixels, not points!

									   // set the color
			text.setFillColor(sf::Color::Red);
			// set the text style
			text.setStyle(sf::Text::Bold);
			window.clear();
			text.setPosition(80.f, 180.f);
			window.draw(text);
		}
		/*if (x>(int)window.getSize().x - 10) x = window.getSize().x - 11;
		if (y<10) y = 10;
		if (y>(int)window.getSize().y - 10) y = window.getSize().y - 11;*/
		// Update coordinates
		if (leftFlag) x -= OCTAGON_SPEED;
		if (rightFlag) x += OCTAGON_SPEED;
		if (upFlag) y -= OCTAGON_SPEED;
		if (downFlag) y += OCTAGON_SPEED;

		octagon.setPosition(x, y);
		//octagon.setRotation(timer.getElapsedTime().asSeconds() / M_PI * 90.f);
		window.draw(octagon);
/////////////////////////////////////////////////////////////
		// Отрисовка окна	
		window.display();

	}

	return 0;
}