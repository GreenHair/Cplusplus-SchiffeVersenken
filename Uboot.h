#ifndef UBOOT_H
#define UBOOT_H

#include "Fahrzeug.h"
#include "Ping.h"
#include "Torpedo.h"
#include <string>
#include <windows.h>

class Uboot : public Fahrzeug
{
	friend class Spiel;
	private:
		string name;
		vector<Torpedo> ammo;
		
	public:
		Uboot();
		Uboot(string _namen,Position _pos,int _laenge,char _richtung, Spielfeld& _sp);
		~Uboot();
		
		string get_name();
		int get_x();
		int get_y();
		Position get_pos();
		char get_richtung();
		int Ammo();
		void set_position(Position pos, char r);
		
		void ping(Spielfeld sp);
		Position schiessen(Spielfeld sp);
		
	protected:
};

#endif
