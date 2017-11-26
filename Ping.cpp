#include "Ping.h"



Ping::Ping(Spielfeld sp, Position& pos, char& richtung)
{
	char z;
	int j = 1;
	for (int i = 0; i < laenge; i++)
	{
		int x = pos.x;
		int y = pos.y;
		
        switch (richtung)
        {
			case 'w': x -= j; y += i; z = 's'; break;
			case 'o': x += j; y -= i; z = 'n'; break;
			case 's': x -= i; y += j; z = 'w'; break;
			case 'n': x += i; y -= j; z = 'o'; break;
        }			
		string ping(i + j, echolot);
		string wasser(i + j, sp.Zeichen());		
		sp.mf_schreiben(ping, z, x, y, wasser, 14);
		Sleep(600);
		sp.mf_schreiben(wasser, z, x, y, ping, 9);
		j++;
	}
}


Ping::~Ping()
{
}
