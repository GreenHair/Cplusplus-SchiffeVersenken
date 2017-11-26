#include "Fahrzeug.h"

Fahrzeug::Fahrzeug(){}



Fahrzeug::Fahrzeug(Position _standort, int _laenge, char _richtung, Spielfeld& _sp,string _name)
        :standort(_standort),laenge(_laenge),richtung(_richtung) 
{
	max_x = _sp.max_x();
	max_y = _sp.max_y();
	kennzeichen = 'F';
	//  Die Zeichen zur Anzeige des Fahrzeuges müssen in
	// das Grid am Standort des Fahrzeuges eingefügt werden.
	_sp.grid.at(_standort.y).at(_standort.x) = _name.at(0);
	 switch(richtung)
	 {
	 	case 'w':
	 		    for(int i=1;i < laenge;i++)
	 		    {
	 		    	try
	 		    	{
	 		    		if(_sp.grid.at(standort.y).at(standort.x+1) != (char)186 /* && _sp.grid.at(_standort.y+1).at(_standort.x) != (char)205*/)
	 		    		{
							_sp.grid.at(standort.y).at(++standort.x)   = _name.at(i);
						}
						else
						{
							break;
						}
					}
					catch(...)
					{
						_sp.grid.at(standort.y).at(standort.x)   = '-';
					}
				} break;
		case 'o':
	 		    for(int i=1;i < laenge;i++)
	 		    {
	 		       try
	 		    	{
	 		    		if(_sp.grid.at(standort.y).at(standort.x-1) != (char)186 /*&& _sp.grid.at(_standort.y+1).at(_standort.x) != '='*/)
	 		    		{
							_sp.grid.at(standort.y).at(--standort.x)   = _name.at(i);
						}
						else
						{
							break;
						}
					}
					catch(...)
					{
						_sp.grid.at(standort.y).at(standort.x)   = '-';
					}	
				} break;
		case 'n':
	 		    for(int i=1;i < laenge;i++)
	 		    {
	 		       try
	 		    	{
	 		    		//_sp.grid.at(_standort.y+1).at(_standort.x) != '|' && _sp.grid.at(_standort.y+1).at(_standort.x) != '='
	 		    		if(/*_sp.grid.at(_standort.y+1).at(_standort.x) != '|' &&*/ _sp.grid.at(_standort.y+1).at(_standort.x) != (char)205)
	 		    		{
							_sp.grid.at(++_standort.y).at(_standort.x) = _name.at(i);
						}
						else
						{
							break;
						}
					}
					catch(...)
					{
						_sp.grid.at(_standort.y).at(_standort.x)   = '-';
					}	
				} break;
		case 's':
	 		    for(int i=1;i < laenge;i++)
	 		    {
	 		       try
	 		    	{
	 		    		if(/*_sp.grid.at(standort.y-1).at(standort.x) != '|' &&*/ _sp.grid.at(standort.y-1).at(standort.x) != (char)205)
	 		    		{
							_sp.grid.at(--standort.y).at(standort.x)   = _name.at(i);
						}
						else
						{
							break;
						}
					}
					catch(...)
					{
						_sp.grid.at(standort.y).at(standort.x)   = '-';
					}	
				} break;
	 	default: ;
	 }	
	
}

Fahrzeug::~Fahrzeug()
{
}






/*
int Fahrzeug::get_x()
{
	return standort.x;
}
	
int Fahrzeug::get_y()
{
	return standort.y;
}

char Fahrzeug::get_kennzeichen()
{
	return kennzeichen;
}

char Fahrzeug::set_name(string n)
{
	name = n;
}

int Fahrzeug::get_laenge()
{
	return laenge;
}

char Fahrzeug::get_richtung()
{
	return richtung;
}
*/


