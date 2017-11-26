#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <wchar.h>

#include "Spiel.h"
#include "Spielfeld.h"
#include "Fahrzeug.h"
#include "Position.h"
#include "Schiff.h"
#include "Uboot.h"
#include "Ping.h"
#include "controls.h"

using namespace std;

int main(int argc, char** argv) {

	SetConsoleTitle("Schiffe Versenken");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
	
	cout << "\n\n\n\n\t\t\tSchiffe Versenken\n\n";
		
	cout << " a = auftauchen, p = ping senden, t = torpedo abschiessen, q = beenden, Cursortasten zum fahren\n\n\t\t";
	system("pause");
	system("cls");
	
	controls::sizeOfWindow(85, 35);

	controls::fontSize(8, 16);
	
	Spiel neuesSpiel = Spiel();

	neuesSpiel.spielen();

	neuesSpiel.meinSpielfeld.anzeigen();
		
	system("pause");

	return 0;
}


