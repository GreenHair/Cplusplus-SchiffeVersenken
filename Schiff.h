#ifndef SCHIFF_H
#define SCHIFF_H

#include "Fahrzeug.h"

class Schiff : public Fahrzeug
{
	private:
		string namen;
		bool getroffen,versenkt;
		int getroffeneSektionen,tonnage,laenge;
		vector<Position> koordinaten;
	
	public:
		Schiff();
		Schiff(string _namen, int _tonnage,Position _pos,int _laenge,char _richtung, Spielfeld& _sp);
		char get_character(int pos);
		~Schiff();

		bool versenktBerechnen(Position torpedo, Spielfeld& sp);

		
	
	protected:
};

#endif
