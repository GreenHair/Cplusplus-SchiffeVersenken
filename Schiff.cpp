#include "Schiff.h"

Schiff::Schiff()
{
}

Schiff::Schiff(string _namen, int _tonnage,Position _pos,int _laenge,char _richtung, Spielfeld& _sp)
		:namen(_namen) ,tonnage(_tonnage),getroffen(false), getroffeneSektionen(0),versenkt(false)
{
	laenge = _laenge;
	Fahrzeug(_pos,_laenge,_richtung,_sp,_namen);
	for (int i = 0; i < _laenge; i++)
	{
		switch (_richtung)
		{
			case 'w':koordinaten.push_back(Position(_pos.x + i,_pos.y)); break;
			case 'o':koordinaten.push_back(Position(_pos.x - i, _pos.y)); break;
			case 's':koordinaten.push_back(Position(_pos.x, _pos.y - i)); break;
			case 'n':koordinaten.push_back(Position(_pos.x, _pos.y + i)); break;
		}
	}
}

Schiff::~Schiff()
{
}

bool Schiff::versenktBerechnen(Position torpedo,Spielfeld& sp)
{
	for(unsigned int i = 0; i < koordinaten.size(); i++)
	{
		if (koordinaten[i] == torpedo)
		{
			getroffen = true;
			getroffeneSektionen += 1;
			// Wasser an entsprechender Stelle im Spielfeld eintragen
			if (sp.grid.at(koordinaten[i].y).at(koordinaten[i].x) != (char)205 && sp.grid.at(koordinaten[i].y).at(koordinaten[i].x) != (char)186)
			{
				sp.grid.at(koordinaten[i].y).at(koordinaten[i].x) = sp.Zeichen();
				Sleep(100);
				sp.curPos(koordinaten[i].x, koordinaten[i].y);
				sp.schreiben(sp.Zeichen(), 9);
			}			
			// position aus liste entfernen
			koordinaten.erase(koordinaten.begin()+i);
			if ((double)getroffeneSektionen / laenge * 100 >= 50) 
			{
				versenkt = true;
				// Auf alle Positionen Wasser eintragen
				for each (Position pos in koordinaten)
				{
					if (sp.grid.at(pos.y).at(pos.x) == (char)205 || sp.grid.at(pos.y).at(pos.x) == (char)186)
					{
						break;
					}
					else
					{
						sp.grid.at(pos.y).at(pos.x) = sp.Zeichen();
						sp.curPos(pos.x, pos.y);
						sp.schreiben(sp.Zeichen(), 9);
					}
									
					
				}
				sp.curPos(0, 33);
				sp.schreib_string("Die " + namen + " wurde versenkt.                   ", 15);
			}
		}
	}
	return versenkt;
}

char Schiff::get_character(int pos)
{
	return namen[pos];
}
