#include "Grid.h"



Grid::Grid()
{
}

Grid::Grid(int row, int col, int bomb, int x, int y)
{
	won = (row * col) - bomb;
	firstX = x;
	firstY = y;
	status = true;
	this->col = col;
	this->row = row;
	game = new Block *[row];
	for (int i = 0; i < row; i++)
	{
		game[i] = new Block[col];
	}

	time_t t = time(0);
	//long x = (long)t;
	int k = bomb;

	int index1; //row
	int index2; // col
	while (k != 0)
	{
		index1 = rand() % row ;
		index2 = rand() % col ;
		if (index1 == firstY && index2 == firstX)
			continue;
		else if (game[index1][index2].attachBomb())
		{
			k--;
		}
	}
	countNeighbours();
}

void Grid::Print()
{
	cout << "\t";
	for (int i = 0; i < col; i++)
		cout << i << "\t";
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		cout << i << "\t";
		for (int j = 0; j < col; j++)
		{
			cout << game[i][j].print() << "\t";
		}
		cout << endl;
	}
}

void Grid::addNeighbours(int x, int y)
{
	int counter = 0;


	if (withInRange(x-1,1) && withInRange(y-1,0))
	{
		counter += (int)game[y - 1][x - 1].getBomb();
	}
	if (withInRange(x, 1) && withInRange(y - 1, 0))
	{
		counter += (int)game[y - 1][x].getBomb();
	}
	if (withInRange(x+1, 1) && withInRange(y - 1, 0))
	{
		counter += (int)game[y - 1][x + 1].getBomb();
	}


	if (withInRange(x - 1, 1) && withInRange(y, 0))
	{
		counter += (int)game[y ][x - 1].getBomb();
	}
	if (withInRange(x + 1, 1) && withInRange(y, 0))
	{
		counter += (int)game[y][x + 1].getBomb();
	}


	if (withInRange(x - 1, 1) && withInRange(y + 1, 0))
	{
		counter += (int)game[y + 1][x - 1].getBomb();
	}
	if (withInRange(x, 1) && withInRange(y + 1, 0))
	{
		counter += (int)game[y + 1][x].getBomb();
	}
	if (withInRange(x + 1, 1) && withInRange(y + 1, 0))
	{
		counter += (int)game[y + 1][x + 1].getBomb();
	}


	game[y][x].setSurrounding(counter);
}

void Grid::countNeighbours()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			addNeighbours(j,i);
		}
	}
}

bool Grid::withInRange(int test, bool isCol)
{
	if (test < 0)
		return false;
	if (isCol)
	{
		if (test >= col)
			return false;
	}
	else
	{
		if (test >= row)
			return false;
	}
	return true;
}

void Grid::start(int colNum, int rowNum, bool flag)
{
	//for simplicity
	int x = colNum;
	int y = rowNum;
	if (flag && game[rowNum][colNum].getBomb())
	{
		game[rowNum][colNum].setClick();
		status = false;
		return;
	}
	if (game[rowNum][colNum].getBomb() || game[rowNum][colNum].getClick())
		return;

	game[rowNum][colNum].setClick();
	won--;


	//call all the next surroundings

	if (withInRange(x - 1, 1) && withInRange(y - 1, 0))
	{
		start(x-1,y-1,0);
	}
	if (withInRange(x, 1) && withInRange(y - 1, 0))
	{
		start(x, y - 1,0);
	}
	if (withInRange(x + 1, 1) && withInRange(y - 1, 0))
	{
		start(x + 1, y - 1,0);
	}


	if (withInRange(x - 1, 1) && withInRange(y, 0))
	{
		start(x - 1, y ,0);
	}
	if (withInRange(x + 1, 1) && withInRange(y, 0))
	{
		start(x + 1, y,0);
	}


	if (withInRange(x - 1, 1) && withInRange(y + 1, 0))
	{
		start(x - 1, y + 1,0);
	}
	if (withInRange(x, 1) && withInRange(y + 1, 0))
	{
		start(x, y + 1,0); 
	}
	if (withInRange(x + 1, 1) && withInRange(y + 1, 0))
	{
		start(x + 1, y + 1,0);
	}

}

bool Grid::getStatus()
{
	return status;
}

bool Grid::endGameWin()
{
	if(won != 0)
		return false;
	return true;
}

void Grid::printEnd()
{
	cout << "\t";
	for (int i = 0; i < col; i++)
		cout << i << "\t";
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		cout << i << "\t";
		for (int j = 0; j < col; j++)
		{
			cout << game[i][j].printEnd() << "\t";
		}
		cout << endl;
	}
}


Grid::~Grid()
{
}
