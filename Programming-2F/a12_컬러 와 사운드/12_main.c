#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "console_color.h"
#include "console_monster.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define BGM "bgm.wav"
// 제목 색, 제목 색 (몬스터 색), 함정 표현



int main()
{
	PlaySound(TEXT(BGM),0, SND_ASYNC);

	Monster mo1;
	mo1.text_color = 초록;
	mo1.bg_color = 검정;
	strcpy(mo1.shape, "##");

	Monster mo2;
	mo1.text_color = 밝은초록;
	mo1.bg_color = 검정;
	strcpy(mo1.shape, "@@");

	SetColor(빨강, 검정);
	printf("색 적용");

	RenderMonster(&mo1);
	RenderMonster(&mo2);

	_getch();
}