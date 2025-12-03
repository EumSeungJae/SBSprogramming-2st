#pragma once


typedef enum Color {
	검정 = 0,
	파란 = 1,
	초록 = 2,
	하늘 = 3,
	빨강 = 4,
	보라 = 5,
	노랑 = 6,
	흰색 = 7,
	회색 = 8,
	밝은파랑 = 9,
	밝은초록 = 10,
	밝은하늘 = 11,
	밝은빨강 = 12,
	밝은보라 = 13,
	밝은노랑 = 14,
	밝은흰색 = 15,
}Color;

void SetColor(int text_color, Color bg_color);
void ResetColor();