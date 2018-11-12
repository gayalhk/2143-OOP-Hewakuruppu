//GAYAL HEWAKURUPPU
//OOP 2143 - ASSIGNMENT 6
//DATE - 11/10/2018
//Github repo - https://github.com/gayalhk/2143-OOP-Hewakuruppu/tree/master/Assignments/A06

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
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

		counterRectangle.setSize(sf::Vector2f(100.f, 100.f));
		counterRectangle.setFillColor(backgroundColor.White);
		time.setFont(font);
		time.setString("0");
		time.setCharacterSize(fontSize);
		time.setFillColor(textColor.Red);
		time.setStyle(sf::Text::Bold);
		changeClockPosition(300.0, 300.0);  //calls function to center clock

	}

	//SET TIME FUNCTION
	//PARAMETERS - integer
	//PURPOSE - This function takes in an integer, converts it to a 
	//          string and sets it as the SFML text(timer).
	void setTime(int t) {
		string txt = to_string(t);
		time.setString(txt);
	}

	//CHANGE FONT COLOR
	//PARAMETERS - sf:: Color
	//PURPOSE - To change the color of the time
	void changeFontColor(sf::Color color) {
		time.setFillColor(color);
	}

	//CHANGE FONT SIZE
	//PARAMETERS - an integer
	//PURPOSE - To change the size of the time
	void changeFontSize(int size) {
		time.setCharacterSize(size);
	}

	//CHANGE Background COLOR
	//PARAMETERS - sf:: Color
	//PURPOSE - To change the color of the rectangle
	void changeBackgroundColor(sf::Color color) {
		counterRectangle.setFillColor(color);
	}

	//CHANGE BORDER COLOR
	//PARAMETERS - sf:: Color
	//PURPOSE - To change the color of the border of the rectangle
	void changeBorderColor(sf::Color color) {
		counterRectangle.setOutlineColor(color);
	}

	//CHANGE COUNTER POSITION FUNCTION
	//PARAMETERS - two floats for x and y positions
	//PURPOSE - To set the position of the timer and the rectangle
	//          in any given (x,y) coordinates in the window. This function 
	//          is called in the constructor
	void changeClockPosition(float X,float Y) {
		time.setPosition(sf::Vector2f(X, Y));
		counterRectangle.setPosition(sf::Vector2f(X, Y));
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
	void updateCounter(int s, int e) {
		elapsed = clock.getElapsedTime();

		if (s < e)
			setTime(elapsed.asSeconds());

		else if (s > e)
			setTime(start.asSeconds() - elapsed.asSeconds());
	}

	//move clock FUNCTION
	//PARAMETERS - none
	//PURUPOSE - This fuction moves the clock around the window
	//           like a screen saver
	void moveClock() {
		elapsed = clock.getElapsedTime();
		int e = elapsed.asSeconds();


		if (e <= 1) {
			time.move(0.4f, 0.4f);
			counterRectangle.move(0.4f, 0.4f);
		}
		else if (e > 1 && e<=5) {
			time.move(-0.4f, -0.4f);
			counterRectangle.move(-0.4f, -0.4f);
		}
		else if (e > 5) {
			time.move(0.4f, 0.2f);
			counterRectangle.move(0.4f, 0.2f);
		}

	}

};

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "Gayal Hewakuruppu");
	
	//Integers for start or end
	int start = 0;
	int end = 20;

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

		C1.updateCounter(start, end);
		C1.moveClock();

		window.clear();
		C1.drawCounter(window);
		window.display();
	}

	return 0;
}
