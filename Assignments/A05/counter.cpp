//GAYAL HEWAKURUPPU
//OOP 2143 - ASSIGNMENT 5
//DATE - 10/31/2018
//Github repo - https://github.com/gayalhk/2143-OOP-Hewakuruppu/tree/master/Assignments/A05

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include <functional>
#include<cstdlib>

using namespace std;

class Counter {
private:
	sf::Font font;                     // clocks font
	int fontSize;                      // size of font in pixels
	sf::Text time;                     // var to hold clock digits
	sf::Clock clock;                   // SFML clock type
	sf::Time start;
	sf::Time end;
	sf::Time elapsed;                  // SFML time type 
	sf::Color textColor;               // Color of clock text
	sf::Color backgroundColor;         // Color behind clock
	sf::Vector2f clockCoord;           // Locations to print clock
	sf::RectangleShape counterRectangle; // Rectangle representing counter back.

public:
	
	//PARAMETERIZED CONSTRUCTOR
	//PARAMETERS - Integers for start and end time
	//PURPOSE - This constructor creates the clock and the rectangle
	//          and centers them in the window
	Counter(int s,int e) {
		fontSize = 80;
		start = sf::seconds(s);
		end = sf::seconds(e);
		elapsed = clock.getElapsedTime();

		if (!font.loadFromFile("arial.ttf"))
		{
			cout << "Error loading font 'arial.ttf'...";
			
		}

		counterRectangle.setSize(sf::Vector2f(200.f, 100.f));
		counterRectangle.setFillColor(backgroundColor.White);
		time.setFont(font);
		time.setString("0");
		time.setCharacterSize(fontSize);
		time.setFillColor(textColor.Red);
		time.setStyle(sf::Text::Bold);
		centreCounter();  //calls function to center clock

	}

	//CENTRECOUNTER FUNCTION
	//PARAMETERS - none
	//PURPOSE - To set the position of the timer and the rectangle
	//          in the center of the window. This function is called
	//          in the constructor
	void centreCounter() {
		time.setPosition(sf::Vector2f(300.f, 300.f));
		counterRectangle.setPosition(sf::Vector2f(250.f, 300.f));
	}

	//SET TIME FUNCTION
	//PARAMETERS - integer
	//PURPOSE - This function takes in an integer, converts it to a 
	//          string and sets it as the SFML text(timer).
	void setTime(int t) {
		string txt = to_string(t);
		time.setString(txt);
	}

	//DRAW COUNTER FUNCTION
	//PARAMETERS - reference to the SFML window
	//PURPOSE - This function draws both the timer and the rectangle
	//           to the SFML Window.
	void drawCounter(sf::RenderWindow &window) {
	    window.draw(counterRectangle);
		window.draw(time);
	}

	//COUNTER TYPE FUNCTION
	//PARAMETERS - Start time and End time
	//PURUPOSE - This fuction decides whether to use an incrementing
	//           or decrementing timer and then calls the SET TIME
	//           function accordingly.
	void counterType(int s, int e) {
		elapsed = clock.getElapsedTime();

		if (s < e)
			setTime(elapsed.asSeconds());

		else if (s > e)
			setTime(start.asSeconds() - elapsed.asSeconds());
	}

};

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "Gayal Hewakuruppu");
	
	//Integers for start or end
	int start = 20;
	int end = 0;

	//Creating a counter
	Counter C1(start,end);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		C1.counterType(start, end);

		window.clear();
		C1.drawCounter(window);
		window.display();
	}

	return 0;
}
