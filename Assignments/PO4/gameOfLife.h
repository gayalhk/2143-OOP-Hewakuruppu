//Gayal Hewakuruppu
//OOP 2143 - Program 4
//Date - 10/12/18
//Github repo - https://github.com/gayalhk/2143-OOP-Hewakuruppu/tree/master/Assignments/PO4

#include<fstream>
#include<string>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class gameOfLife {
public:
	//GOLCELL STRUCT------------------------------------------------------
	struct golCell {
		bool isAlive;
		int neighborCount;
		RectangleShape Rect;
		int Width;
		int Height;

		golCell() {
			Width = 10;
			Height = 10;
			Rect.setSize(sf::Vector2f(Width, Height));
			Rect.setFillColor(Color::Green);
			Rect.setOutlineColor(Color::Black);
			Rect.setOutlineThickness(1);
		}

		void setCellPos(int x, int y) {
			Rect.setPosition(x*Width, y*Height);
		}

	};
	//---------------------------------------------------------------------
	
	//MEMBERS
	int Width;
	int Height;
	RenderWindow Window;
	golCell** GameBoard;

	//METHODS
	gameOfLife(int, int);
	void initGame(int, int, ifstream&);
	void printWorld(int, int, ofstream&);
	void drawWorld();
	int countNeighbors(int, int);
};
