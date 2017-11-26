#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include "Position.h"
#include "Spielfeld.h"
#include <windows.h>
#include <conio.h>

class Fahrzeug
{
	private:
		int laenge;
//		char richtung;		
		char kennzeichen;
	
	public:
		Fahrzeug(Position standort, int laenge, char richtung,Spielfeld& sp,string name);
		~Fahrzeug();
		
		Fahrzeug();
		
		
	
	protected:
		Position standort; // Aggregation
		char richtung;
		int max_x;
		int max_y;
};

#endif


/*
	
		int get_x();

		int get_y();
		
		int get_laenge();
		
		char get_richtung();
		
		char get_kennzeichen();
		
		char set_name(string n);
*/
