//Gayal Hewakuruppu
//OOP 2143 - Program 4
//Date - 10/12/18
//Github repo - https://github.com/gayalhk/2143-OOP-Hewakuruppu/tree/master/Assignments/PO4

#include<fstream>
#include<string>
#include <SFML/Graphics.hpp>
#include"gameOfLife.h"

using namespace sf;
using namespace std;

//PARAMETERIZED CONSTRUCTOR---------------------------------------
//Creates a window and a 2D array of geoCells
//Parameters - number of rows and columns
gameOfLife::gameOfLife(int width, int height) {
	Width = width;
	Height = height;
	Window.create(VideoMode(Width, Height), "Game of Life");

	GameBoard = new golCell*[Height];

	for (int i = 0; i<Height; i++) {
		GameBoard[i] = new golCell[Width];
		for (int j = 0; j<Width; j++) {
			GameBoard[i][j].setCellPos(i, j);
		}
	}
}


//InitGame---------------------------------------------------------
//Initializes array with dead and live cells
//Parameters - rows,columns and ifstream operator 
void gameOfLife::initGame(int rows, int cols, ifstream& infile) {
	int deadAlive;
	
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			infile >> deadAlive;
			if (deadAlive == 0) {
				GameBoard[rows][cols].isAlive = false;
				GameBoard[rows][cols].Rect.setFillColor(Color::Black);
			}
			else {
				GameBoard[rows][cols].isAlive = true;
			}
		}
	}
}

//PrintWorld-----------------------------------------------------------
//Print the Gameboard in array format
//Parameters - Rows,columns and the ofstream operator.
void gameOfLife::printWorld(int rows, int cols, ofstream&outfile) {
	//Print student name
	outfile << "Gayal Hewakuruppu" << endl << endl;
	
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			outfile << int(GameBoard[rows][cols].isAlive);
		}
		outfile << endl;
	}
}

//DRAWWORLD--------------------------------------------------------
//Draws the Gameboard to the screen
void gameOfLife::drawWorld() {
	Window.clear();
	for (int i = 0; i<Height; i++) {
		for (int j = 0; j<Width; j++) {
			Window.draw(GameBoard[i][j].Rect);
		}
	}
	Window.display();
}

//CountNeighbors---------------------------------------------------
//Counts and returns the neighbors of a given cell
//Parameters - The coordinates of the desired cell
int gameOfLife::countNeighbors(int i, int j) {
	int neighbors = 0;

	if (GameBoard[i - 1][j].isAlive == true)
		neighbors++;
	else if (GameBoard[i - 1][j - 1].isAlive == true)
		neighbors++;
	else if (GameBoard[i][j - 1].isAlive == true)
		neighbors++;
	else if (GameBoard[i + 1][j - 1].isAlive == true)
		neighbors++;
	else if (GameBoard[i + 1][j].isAlive == true)
		neighbors++;
	else if (GameBoard[i + 1][j + 1].isAlive == true)
		neighbors++;
	else if (GameBoard[i][j + 1].isAlive == true)
		neighbors++;
	else if (GameBoard[i - 1][j + 1].isAlive == true)
		neighbors++;

	return neighbors;

}
