#pragma once
#include "Fahrzeug.h"
class Torpedo :
	public Fahrzeug
{
private:
	int reichweite = 9;
	char zeichen;
public:
	Torpedo();
	~Torpedo();

	Position abfeuern(Spielfeld sp, Position pos_uboot, char richtung);
};

