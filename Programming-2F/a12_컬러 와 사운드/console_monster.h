#pragma once

typedef struct Monster {
	Color text_color;
	Color bg_color;
	char shape[20];
}Monster;

void RenderMonster(Monster* monster);
