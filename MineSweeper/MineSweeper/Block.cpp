#include "Block.h"




Block::Block()
{
	Clicked = false;
	Bomb = false;
}

bool Block::attachBomb()
{
	if(Bomb)
		return false;
	else
	{
		Bomb = true;
		return true;
	}
}

string Block::print()
{
	char *myString;

	if (!Clicked)
		return ".";
	else if (!Bomb)
		return to_string(surrounding);
	else
		return "X";
}

void Block::setSurrounding(int x)
{
	surrounding = x;
}


bool Block::getBomb()
{
	return Bomb;
}

int Block::getSurrounding()
{
	return surrounding;
}

void Block::setClick()
{
	Clicked = true;
}

bool Block::getClick()
{
	return Clicked;
}

string Block::printEnd()
{
	char *myString;
	if (Bomb)
		return "X";
	if (!Clicked)
		return ".";
	else 
		return to_string(surrounding);
}

Block::~Block()
{
}
