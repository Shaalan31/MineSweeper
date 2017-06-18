#pragma once
#include <ctime>
#include "Block.h"
#include "Grid.h"
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;


int main()
{
	
	time_t t = time(0);
	bool won = false;
	int row, coloumn, bomb;
	cout << "Please enter the number of rows : ";
	cin >> row;
	cout << "Please enter the number of coloumns : ";
	cin >> coloumn;
	cout << "Please enter the number of bombs : ";
	cin >> bomb;
	cout << "Generating Random Bomb locations";
	if (row <= 0)
		row = 1;
	if (coloumn <= 0)
		coloumn = 1;
	if (bomb >= row * coloumn)
		bomb = (row*coloumn) - 1;
	system("CLS");
	int x, y;
	cout << "Click on a block... enter the row number followed by a coloumn number : ";
	cin >> y;
	cin >> x;
	y = y%row;
	x = x%coloumn;
	Grid grid(row,coloumn,bomb,x,y);
	grid.start(x, y, 1);
	grid.Print();
	
	time_t start = time(0);
	while (grid.getStatus() && !grid.endGameWin())
	{
	
		system("CLS");
		grid.Print();
		cout << "Click on a block... enter the row number followed by a coloumn number : ";
		cin >> y;
		cin >> x;

		
		y = y%row;
		x = x%coloumn;
		grid.start(x,y,1);
		if (grid.endGameWin())
		{
			won = true;
			break;
		}
	
	} 

	double seconds_since_start = difftime(time(0), start);
	system("CLS");
	grid.printEnd();
	if (won || grid.endGameWin())
	{
		cout << "\n Congrats!!!! you won, your score is "<<(int)seconds_since_start<<endl;
	}
	else
	{
		cout << "\n HardLuck, you Lost, it took you " <<(int)seconds_since_start<<" seconds to lose :)"<< endl;
	}
	//system("Pause");
}


