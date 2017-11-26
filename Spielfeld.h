#ifndef SPIELFELD_H
#define SPIELFELD_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Uboot;

class Spielfeld
{
	private:
		char fuellzeichen;
		string umrandung;
		int ausdehnung_x;
		int ausdehnung_y;
	
	public:
		vector<vector<char>> grid;		
		
		Spielfeld(int ausdehnung_x, int ausdehnung_y, char fill_char, string edge);
		Spielfeld();
		~Spielfeld();
		
		char Zeichen();
		int max_x();
		int max_y();
		
		void anzeigen();
		void wasser_anzeigen();
		void schreiben(char c, int farbe);
		void schreib_string(string s, int farbe);
		void curPos(int x, int y);
		void mf_schreiben(Uboot uboot);		
		void mf_schreiben(string name, char richtung,int x, int y,string bstring, int farbe);
		
		void mf_wischen(Uboot uboot);
		
	protected:
};

#endif
