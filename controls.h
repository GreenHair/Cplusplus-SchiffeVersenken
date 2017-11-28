#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

class controls
{
public:
	controls();
	~controls();

	static void sizeOfWindow(int breite, int hoehe);

	static void fontSize(short fwSize, short fhSize);

	void curPos(int x, int y);


};

