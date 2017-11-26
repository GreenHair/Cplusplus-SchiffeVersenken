#pragma once
#include "Uboot.h"
class Ping :
	public Fahrzeug
{
private:
	int laenge = 6;
	char echolot = '.';
public:
	Ping(Spielfeld sp,Position& pos, char& richtung);
	~Ping();
};

