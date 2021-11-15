#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SDL.h>

struct Cell 
{
	Cell(bool alive = false) {
		isAlive = alive;
	}
	void Die()  { isAlive = false; }
	void Born() { isAlive = true; }
	void Flip() { isAlive = !isAlive; }
	bool isAlive	 = false;
	int neighbours   = 0;
};

struct Grid
{
	Grid() {};

	// Grid properties
	int rows		 = 0;
	int cols		 = 0;

	// Grid position (top left)
	int posX		 = 0;
	int posY		 = 0;

	// Size of the grid
	int width		 = 0;
	int height		 = 0;

	// Size of each cell
	float cellWidth  = 0;
	float cellHeight = 0;

	// Gap between the window and the grid
	int borderSize   = 20;
};

class Game
{

public:

	Game();
	~Game();

	void InitCells(int rows, int cols);
	void Run();
	void HandleEvents();
	void Draw();
	void AdjustGridSize(); // Change the grid size to always fit the window size
	
	// Limit the index between (0) -> (rows/cols)
	int  iX(int i); 
	int	 iY(int i);

	// Run the simulation
	void RunSimulation();

private:

	bool isRunning				 = false;
	bool isRunningSim			 = false;
	int  simTick				 = 0;
	int  simDelay				 = 50;

	SDL_Window      *window		 = nullptr;
	SDL_Renderer    *renderer	 = nullptr;

	int mouseX					 = 0;
	int mouseY					 = 0;
	int mouseCellX				 = 0;
	int mouseCellY				 = 0;
	bool mouseDown				 = 0;

	Grid grid;
	vector<vector<Cell>> cells;

};

