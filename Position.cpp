#include "Position.h"

Position::Position(){}

Position::~Position()
{
}

bool Position::operator==(Position & pos1)
{
	if (this->x == pos1.x && this->y == pos1.y)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}
