#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
class Block
{
	bool Bomb;
	bool Clicked;
	int surrounding;

public:
	Block();
	bool attachBomb();
	string print();
	void setSurrounding(int x);
	bool getBomb();
	int getSurrounding();
	void setClick();
	bool getClick();
	string printEnd();
	~Block();
};

