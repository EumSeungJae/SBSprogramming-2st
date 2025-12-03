#include "console_monster.h"
#include "console_color.h"
#include <Windows.h>

void RenderMonster(Monster* monster)
{
	SetColor(monster->text_color, monster->bg_color);
	// 좌표 이동하는 코드
	printf("%s\n", monster->shape);
	ResetColor();
}