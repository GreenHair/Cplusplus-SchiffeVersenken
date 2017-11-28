#include "controls.h"

controls::controls()
{
}


controls::~controls()
{
}

void controls::sizeOfWindow(int breite, int hoehe)
{
	HANDLE stdh;
	stdh = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT window;
	window.Top = 0;
	window.Left = 0;
	window.Bottom = hoehe;
	window.Right = breite;
	SetConsoleWindowInfo(stdh, true, &window);
}

void controls::fontSize(short fwSize, short fhSize)
{
	HANDLE std_out;
	std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX f_info;
	f_info.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	if (GetCurrentConsoleFontEx(std_out, true, &f_info))
	{
		//cout << "Success!" << endl;
	}
	else
	{
		cout << "Function failed\n";
		cout << GetLastError() << endl;
		cout << "Font X: " << f_info.dwFontSize.X << endl;
		cout << "Font weight: " << f_info.FontWeight << endl;
	}
	COORD f_size;
	f_size = GetConsoleFontSize(std_out, f_info.nFont);
	//cout << f_size.X << endl;
	f_size.X = fwSize;
	f_size.Y = fhSize;
	f_info.dwFontSize = f_size;
	if (SetCurrentConsoleFontEx(std_out, true, &f_info))
	{
		//cout << "Success!";
	}
	else
	{
		cout << "Function failed\n";
		cout << GetLastError() << endl;
		cout << f_info.dwFontSize.X << endl;
	}
	//system("pause");
}

void controls::curPos(int x, int y)
{
	HANDLE hStdout;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 10;
	cursor.bVisible = false;
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
	SetConsoleCursorInfo(hStdout, &cursor);
}
