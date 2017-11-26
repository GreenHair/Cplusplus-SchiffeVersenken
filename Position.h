#ifndef POSITION_H
#define POSITION_H

class Position
{
	public:
		int x;
		int y;
		Position(int _x, int _y)
		:x(_x),y(_y){}
		
		// to do Überladen des == operators

		Position();

		~Position();
		
		bool operator == (Position& pos1);

	protected:
};

#endif
