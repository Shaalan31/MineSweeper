#pragma once
#include "Block.h"
#include <ctime>
#include <iostream>

using namespace std;
class Grid
{
	int firstX;
	int firstY;
	int won;
	bool status;
	int row;
	int col;
	Block ** game;
public:
	Grid();
	Grid(int row, int col, int bomb,int x, int y);
	void Print();
	void addNeighbours(int x, int y);
	void countNeighbours();
	bool withInRange(int test, bool);
	void start(int rowNum, int colNum,bool flag);
	bool getStatus();
	bool endGameWin();
	void printEnd();

	~Grid();
};

