#include "console_color.h"

#include <stdio.h>
#include <Windows.h>

void SetColor(int text_color, Color bg_color)
{
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, (bg_color << 4) | text_color);
}

void ResetColor()
{
	SetColor(Èò»ö, °ËÁ¤);
}