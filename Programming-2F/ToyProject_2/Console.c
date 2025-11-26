#include "Console.h"
#include <Windows.h>

void GoToXY(int x, int y)
{
	COORD coord = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

