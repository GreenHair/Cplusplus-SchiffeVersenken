#pragma once
#include "Spielfeld.h"
#include "Schiff.h"
#include "Uboot.h"
#include <Windows.h>
//#include <future>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <vector>

using namespace std;

class Spiel
{
private:
	Position posUboot = Position(35,25);
	char r_Uboot = 'w';
public:
	Spielfeld meinSpielfeld;
	vector<Schiff> meineFlotte;
	Uboot u47;

	Spiel();
	~Spiel();
	void wasserUndSpielstand();
	void spielen();
	void musik();
};

