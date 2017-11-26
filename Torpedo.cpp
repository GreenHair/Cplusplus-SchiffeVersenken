#include "Torpedo.h"



Torpedo::Torpedo()
{
}


Torpedo::~Torpedo()
{
}

Position Torpedo::abfeuern(Spielfeld sp, Position pos_uboot, char richtung)
{
	for (int i = 1; i <= reichweite; i++)
	{
		switch (richtung)
		{
		case 'w': pos_uboot.x --; zeichen = '-'; break;
		case 'o': pos_uboot.x ++; zeichen = '-'; break;
		case 's': pos_uboot.y ++; zeichen = '|'; break;
		case 'n': pos_uboot.y --; zeichen = '|'; break;
		}
		standort = Position(pos_uboot.x, pos_uboot.y);
		try
		{
			if (sp.grid.at(standort.y).at(standort.x) == sp.Zeichen())
			{
				sp.curPos(standort.x, standort.y);
				sp.schreiben(zeichen, 15);
				Sleep(200);
				sp.curPos(standort.x, standort.y);
				sp.schreiben(sp.Zeichen(), 9);
			}
			else
			{
				sp.curPos(standort.x, standort.y);
				sp.schreiben(sp.grid.at(standort.y).at(standort.x), 12);
				i += reichweite;  // Schleife abbrechen
				return standort;
			}
		}
		catch (...)
		{

		}
	}
	return Position(-1,-1);
}