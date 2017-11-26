#include "Spiel.h"



Spiel::Spiel()
{
	srand(time(NULL));
	int x = rand() % 65 + 5;
	int y = rand() % 25 + 5;
	int i = rand() % 3;

	char z[4] = { 'n','o','s','w' };
	
	char _rand[8] = { (char)201,(char)205,(char)187,(char)186,(char)186,(char)200,(char)205,(char)188 };
	string edge(_rand, 8);
	meinSpielfeld = Spielfeld(70, 30, '~', edge);	
	meineFlotte.push_back(Schiff("Titanic", 35000, Position(x, y), 10, z[i], meinSpielfeld));
	x = rand() % 68 + 2; y = rand() % 28 + 2; i = rand() % 3;
	meineFlotte.push_back(Schiff("Aida", 50000, Position(x, y), 4, z[i], meinSpielfeld));
	x = rand() % 65 + 5; y = rand() % 25 + 5; i = rand() % 3;
	meineFlotte.push_back(Schiff("Pinocchio", 23000, Position(x, y), 10, z[i], meinSpielfeld));
	x = rand() % 63 + 7; y = rand() % 23 + 7; i = rand() % 3;
	meineFlotte.push_back(Schiff("MSH_Vergessen", 54000, Position(x, y), 13, z[i], meinSpielfeld));
	u47 = Uboot("Uboot", Position(35, 25), 5, 'w', meinSpielfeld);

	
}


Spiel::~Spiel()
{
}

void Spiel::wasserUndSpielstand()
{
	meinSpielfeld.wasser_anzeigen();
	meinSpielfeld.schreib_string(to_string(meineFlotte.capacity() - meineFlotte.size()) +
		" von " + to_string(meineFlotte.capacity()) + " Schiffe versenkt", 15);
	meinSpielfeld.curPos(60, 32);
	meinSpielfeld.schreib_string("Ammo: " + to_string(u47.Ammo()) + " ", 15);
}

void Spiel::spielen()
{
	Position keinTreffer = Position(-1, -1);
	Position treffer;
	int c = 0,x = u47.standort.x,y = u47.standort.y, i = 1;
	char z = u47.richtung;

	wasserUndSpielstand();
	
	do
	{
		meinSpielfeld.mf_schreiben(u47);

		c = _getch();
		switch (c)
		{
		case 224:
			meinSpielfeld.mf_wischen(u47);
			switch (_getch())
			{
			case 75: (x - 1 < 1) ? x = 1 : x--; z = 'w';  break;
			case 77: (x + 1 > meinSpielfeld.max_x()) ? x = meinSpielfeld.max_x() : x++; z = 'o';  break;
			case 72: (y - 1 < 1) ? y = 1 : y--; z = 'n';  break;
			case 80: (y + 1 > meinSpielfeld.max_y()) ? y = meinSpielfeld.max_y() : y++; z = 's';  break;
			case 79: i = 0; break;
			}
			break;
		case 97: meinSpielfeld.anzeigen();
			Sleep(1000);
			wasserUndSpielstand(); break;
		case 113: i = 0; break;
		case 112: u47.ping(meinSpielfeld); break;
		case 116: treffer = u47.schiessen(meinSpielfeld); 
			if (treffer == keinTreffer)
			{
				cout << "Leider nichts getroffen";
			}
			else
			{
				meinSpielfeld.curPos(0, 33);
				meinSpielfeld.schreib_string("Treffer!" + string(20, ' '), 15);
				for (unsigned int i = 0; i < meineFlotte.size(); i++)
				{
					if (meineFlotte[i].versenktBerechnen(treffer,meinSpielfeld))
					{
						meineFlotte.erase(meineFlotte.begin() + i);
						meinSpielfeld.curPos(0, 32);
						meinSpielfeld.schreib_string(to_string(meineFlotte.capacity()-meineFlotte.size()) +
													" von " + to_string(meineFlotte.capacity()) + " Schiffe versenkt",15);
						
					}
				}				
			}
			break;

		}
		
		u47.standort = Position(x, y);
		u47.richtung = z;
	} while (i && u47.ammo.size() > 0 && meineFlotte.size() > 0);
	// vergleichen gewonnen oder verloren
	if (meineFlotte.size() == 0)
	{
		meinSpielfeld.curPos(0, 33);
		meinSpielfeld.schreib_string("Schreck der Weltmeere erste Klasse!              ", 15);
	}
	else
	{
		meinSpielfeld.curPos(0, 33);
		meinSpielfeld.schreib_string("         Game Over            ", 15);
	}
	
}

