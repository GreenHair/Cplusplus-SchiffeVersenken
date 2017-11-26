#include "Spielfeld.h"
#include "Position.h"
#include "Fahrzeug.h"
#include "Uboot.h"
#include "consolenfarbe.h"

using namespace eku;

Spielfeld::Spielfeld(int _ausdehnung_x, int _ausdehnung_y, char _fill_char, string _edge)
:ausdehnung_x(_ausdehnung_x),ausdehnung_y(_ausdehnung_y),fuellzeichen(_fill_char),umrandung(_edge)
{
	vector <char> gridRow;
	//Zeile 1	
	gridRow.push_back(umrandung[0]);
	for(int i = 0; i < ausdehnung_x; i++)
	{
		gridRow.push_back(umrandung[1]);
	}
	gridRow.push_back(umrandung[2]);
	grid.push_back(gridRow);
	gridRow.clear();
	// Weitere Zeilen
	for(int i=0; i< ausdehnung_y; i++)
    {        
        gridRow.push_back(umrandung[3]);
        for(int j=0; j<ausdehnung_x; j++)
        {
            gridRow.push_back( fuellzeichen );
        }
        gridRow.push_back( umrandung[4] );
        grid.push_back(gridRow);
        gridRow.clear();
    }
    // Letzte Zeile    
	gridRow.push_back(umrandung[5]);
	for(int i = 0; i < ausdehnung_x; i++)
	{
		gridRow.push_back(umrandung[6]);
	}
	gridRow.push_back(umrandung[7]);
	grid.push_back(gridRow);
			
}

Spielfeld::Spielfeld(){}
Spielfeld::~Spielfeld()
{
}

void Spielfeld::anzeigen()
{
	concolinit();
	curPos(0, 0);
	for(auto zeile:grid)
	{
		for(auto zeichen:zeile)
		{
			if(zeichen != fuellzeichen)			
			{
				cout<<red<<zeichen;
			}
			else
			{
				cout<<blue<<fuellzeichen;
			}
		}
		cout<<endl;
	}
}

void Spielfeld::schreiben(char c, int farbe)
{
	concol color = (concol)farbe;
	cout<<color<<c;
}

void Spielfeld::schreib_string(string s, int farbe)
{
	concol color = (concol)farbe;
	cout << color << s;
}

void Spielfeld::curPos(int x, int y)
{
	HANDLE hStdout;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 10;
    cursor.bVisible = false;
    csbiInfo.dwCursorPosition.X=x;
    csbiInfo.dwCursorPosition.Y=y;
    SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
    SetConsoleCursorInfo(hStdout,&cursor);
}

void Spielfeld::mf_schreiben(string name, char richtung,int _x, int _y,string bstring, int farbe)
{
	concol color = (concol)farbe;
	for(int i = 0; i < name.length(); i++)
	{
		int x=_x; int y=_y;
		switch(richtung)
		{
			case 'w': x+=i;  break; 	
			case 'o': x-=i; break; 
			case 's': y-=i; break; 
			case 'n': y+=i; break; 
		}
		
		try
		{
			if(grid.at(y).at(x) == bstring.at(i))
			{
				grid.at(y).at(x) = name.at(i);
				curPos(x,y);		
				cout<<color<<name.at(i);	
			}                                                 
			else
			{
				curPos(x,y);	
				cout<<red<<grid.at(y).at(x);
			}
		}
		catch (...)
		{
			
		}
		
	}
}

void Spielfeld::mf_schreiben(Uboot uboot)
{
	string name = uboot.get_name();
	char richtung = uboot.get_richtung();
	int _x = uboot.get_x();
	int _y = uboot.get_y();
	string str(name.length(), fuellzeichen);
	mf_schreiben(name, richtung, _x, _y, str, 12);
}

void Spielfeld::mf_wischen(Uboot uboot)
{
	string name = uboot.get_name();
	char richtung = uboot.get_richtung();
	int _x = uboot.get_x();
	int _y = uboot.get_y();
	string str(name.length(), fuellzeichen);
	mf_schreiben(str, richtung, _x, _y, name, 9);
}

int Spielfeld::max_x()
{
	return ausdehnung_x;
}

int Spielfeld::max_y()
{
	return ausdehnung_y;
}

char Spielfeld::Zeichen() 
{
	return fuellzeichen;
}

void Spielfeld::wasser_anzeigen()
{
	concolinit();
	curPos(0, 0);
	for (auto zeile : grid)
	{
		for (auto zeichen : zeile)
		{
			if (zeichen == umrandung.at(0) || zeichen == umrandung.at(1) || zeichen == umrandung.at(2)
				|| zeichen == umrandung.at(3) || zeichen == umrandung.at(5) || zeichen == umrandung.at(7))
			{
				cout << red << zeichen;
			}
			else
			{
				cout << blue << fuellzeichen;
			}
		}
		cout << endl;
	}
}