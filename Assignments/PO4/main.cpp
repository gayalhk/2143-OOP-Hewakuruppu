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


int main(int argc,char*argv[]) {

	ifstream infile;
	infile.open("gen_zero.txt");
	ofstream outfile;
	outfile.open("output.txt");
	
	int rows, cols;
	infile >> rows >> cols;
	
	gameOfLife Gol(cols*10, rows*10); //CREATING A GAMEBOARD

	Gol.initGame(rows, cols, infile); //READ FROM INPUT TO INITIALIZE GAMEBOARD

	Gol.printWorld(rows, cols, outfile); //PRINT GAMEBOARD IN ARRAY FORMAT
	
	//DISPLAY THE GAMEBOARD ON THE SCREEN
	while (Gol.Window.isOpen())
	{
		Event event;
		while (Gol.Window.pollEvent(event))
		{
			Gol.drawWorld();
			if (event.type == Event::Closed)
				Gol.Window.close();
		}
	}

	return 0;
}
