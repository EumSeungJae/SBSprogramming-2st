#pragma once

typedef enum Color {
	°ËÁ¤ = 0,
	ÆÄ¶õ = 1,
	ÃÊ·Ï = 2,
	ÇÏ´Ã = 3,
	»¡°­ = 4,
	º¸¶ó = 5,
	³ë¶û = 6,
	Èò»ö = 7,
	È¸»ö = 8,
	¹àÀºÆÄ¶û = 9,
	¹àÀºÃÊ·Ï = 10,
	¹àÀºÇÏ´Ã = 11,
	¹àÀº»¡°­ = 12,
	¹àÀºº¸¶ó = 13,
	¹àÀº³ë¶û = 14,
	¹àÀºÈò»ö = 15,
}Color;

void SetColor(int text_color, Color bg_color);



void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenRelease();
void ScreenPrint(int x, int y, char* string);
void gotoxy(int x, int y);