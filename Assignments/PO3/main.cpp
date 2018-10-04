//GAYAL HEWAKURUPPU
//OOP 2143 - PROGRAM 3
//DATE - 09/29/2018
//Github repo - https://github.com/gayalhk/2143-OOP-Hewakuruppu/tree/master/Assignments/PO3

#include <SFML/Graphics.hpp>

int main() {
	//Creating a window with dimensions of 200 each.
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	//Creating a circle with radius of 100.
	sf::CircleShape shape(100.f);
	//Making the circle green
	shape.setFillColor(sf::Color::Green);

	//While the window is open
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
