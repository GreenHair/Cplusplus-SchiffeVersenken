#include "Uboot.h"

Uboot::Uboot()
{
}

Uboot::Uboot(string _namen,Position _pos,int _laenge,char _richtung, Spielfeld& _sp)
{
	Fahrzeug(_pos,_laenge,_richtung,_sp,_namen);
	name = _namen;
	standort = _pos;
	richtung = _richtung;
	for (int i = 0; i < 25; i++)
	{
		ammo.push_back(Torpedo());
	}
}

Uboot::~Uboot()
{
//	cout<<"Hello Constructor\n";
//	system("pause");
}

string Uboot::get_name()
{
	return name;
}

int Uboot::get_x()
{
	return standort.x;
}

int Uboot::get_y()
{
	return standort.y;
}

Position Uboot::get_pos()
{
	return standort;
}

char Uboot::get_richtung()
{
	return richtung;
}

int Uboot::Ammo()
{
	return ammo.size();
}

void Uboot::set_position(Position pos, char r)
{
	standort = pos;
	richtung = r;
}

void Uboot::ping(Spielfeld sp)
{
	Ping echo(sp,standort,richtung);
}

Position Uboot::schiessen(Spielfeld sp)
{
	Position keinTreffer = Position(-1, -1);
	Position treffer = ammo.at(ammo.size() - 1).abfeuern(sp, standort, richtung);
	ammo.pop_back();
	sp.curPos(60, 32);
	sp.schreib_string("Ammo: " + to_string(ammo.size()) + " \n", 15);
	return treffer;
}
