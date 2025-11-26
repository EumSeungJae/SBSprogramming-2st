#define _CRT_SECURE_NO_WARNINGS
#include "monster.h"
#include "monster_setting.h"
#include "labyrinth.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void Monster_Name_Library(Monster_Setting_* monster, int layer)
{
	monster->Monster_Stat.STR = 0;
	monster->Monster_Stat.INT = 0;
	monster->Monster_Stat.VIT = 0;
	monster->Monster_Stat.AGI = 0;
	monster->Monster_Stat.DEX = 0;

	int type = rand() % 5;
	if (layer > 0 && layer < 4)
	{

		switch (type)
		{
		case 0:
			strcpy(monster->Name, "박쥐");
			monster->Monster_Type = 박쥐;

			break;
		case 1:
			strcpy(monster->Name, "고블린");
			monster->Monster_Type = 고블린;

			break;
		case 2:
			strcpy(monster->Name, "스켈레톤");
			monster->Monster_Type = 스켈레톤;

			break;
		case 3:
			strcpy(monster->Name, "울프");
			monster->Monster_Type = 울프;

			break;
		case 4:
			strcpy(monster->Name, "스파이더");
			monster->Monster_Type = 스파이더;

			break;
		}
	}
	else if (layer > 3 && layer < 7)
	{

		switch (type)
		{
		case 0:
			strcpy(monster->Name, "슬라임");
			monster->Monster_Type = 슬라임;

			break;
		case 1:
			strcpy(monster->Name, "홉 고블린");
			monster->Monster_Type = 홉고블린;

			break;
		case 2:
			strcpy(monster->Name, "스켈나이트");
			monster->Monster_Type = 스켈나이트;

			break;
		case 3:
			strcpy(monster->Name, "코볼트");
			monster->Monster_Type = 코볼트;

			break;
		case 4:
			strcpy(monster->Name, "포이즌 스파이더");
			monster->Monster_Type = 포이즌스파이더;

			break;
		}
	}
	else if (layer > 6 && layer < 11)
	{

		switch (type)
		{
		case 0:
			strcpy(monster->Name, "데몬 슬라임");
			monster->Monster_Type = 데몬슬라임;

			break;
		case 1:
			strcpy(monster->Name, "오크");
			monster->Monster_Type = 오크;

			break;
		case 2:
			strcpy(monster->Name, "리치");
			monster->Monster_Type = 리치;

			break;
		case 3:
			strcpy(monster->Name, "라이칸");
			monster->Monster_Type = 라이칸;

			break;
		case 4:
			strcpy(monster->Name, "데몬 스파이더");
			monster->Monster_Type = 데몬스파이더;

			break;
		}
	}
	else
	{
		printf("cls");
		printf("계층 몬스터 설정 오류");
	}
	
}

void Monster_Status_Library(Monster_Setting_* monster)
{
	switch (monster->Monster_Type)
	{
	case 박쥐 : 
		monster->Monster_Stat.STR = 1;
		monster->Monster_Stat.INT = 2;
		monster->Monster_Stat.VIT = 2;
		monster->Monster_Stat.AGI = 6;
		monster->Monster_Stat.DEX = 4;
		break;
	case 고블린:
		monster->Monster_Stat.STR = 3;
		monster->Monster_Stat.INT = 1;
		monster->Monster_Stat.VIT = 2;
		monster->Monster_Stat.AGI = 3;
		monster->Monster_Stat.DEX = 4;
		break;
	case 스켈레톤:
		monster->Monster_Stat.STR = 2;
		monster->Monster_Stat.INT = 0;
		monster->Monster_Stat.VIT = 3;
		monster->Monster_Stat.AGI = 2;
		monster->Monster_Stat.DEX = 2;
		break;
	case 울프:
		monster->Monster_Stat.STR = 5;
		monster->Monster_Stat.INT = 2;
		monster->Monster_Stat.VIT = 5;
		monster->Monster_Stat.AGI = 6;
		monster->Monster_Stat.DEX = 4;
		break;
	case 스파이더:
		monster->Monster_Stat.STR = 4;
		monster->Monster_Stat.INT = 4;
		monster->Monster_Stat.VIT = 6;
		monster->Monster_Stat.AGI = 6;
		monster->Monster_Stat.DEX = 4;
		break;
	case 슬라임:
		monster->Monster_Stat.STR = 4;
		monster->Monster_Stat.INT = 4;
		monster->Monster_Stat.VIT = 10;
		monster->Monster_Stat.AGI = 3;
		monster->Monster_Stat.DEX = 4;
		break;
	case 홉고블린:
		monster->Monster_Stat.STR = 5;
		monster->Monster_Stat.INT = 2;
		monster->Monster_Stat.VIT = 6;
		monster->Monster_Stat.AGI = 4;
		monster->Monster_Stat.DEX = 6;
		break;
	case 스켈나이트:
		monster->Monster_Stat.STR = 7;
		monster->Monster_Stat.INT = 2;
		monster->Monster_Stat.VIT = 8;
		monster->Monster_Stat.AGI = 5;
		monster->Monster_Stat.DEX = 6;
		break;
	case 코볼트:
		monster->Monster_Stat.STR = 6;
		monster->Monster_Stat.INT = 4;
		monster->Monster_Stat.VIT = 7;
		monster->Monster_Stat.AGI = 7;
		monster->Monster_Stat.DEX = 4;
		break;
	case 포이즌스파이더:
		monster->Monster_Stat.STR = 7;
		monster->Monster_Stat.INT = 6;
		monster->Monster_Stat.VIT = 10;
		monster->Monster_Stat.AGI = 8;
		monster->Monster_Stat.DEX = 8;
		break;
	case 데몬슬라임:
		monster->Monster_Stat.STR = 8;
		monster->Monster_Stat.INT = 8;
		monster->Monster_Stat.VIT = 14;
		monster->Monster_Stat.AGI = 6;
		monster->Monster_Stat.DEX = 8;
		break;
	case 오크:
		monster->Monster_Stat.STR = 10;
		monster->Monster_Stat.INT = 4;
		monster->Monster_Stat.VIT = 15;
		monster->Monster_Stat.AGI = 6;
		monster->Monster_Stat.DEX = 4;
		break;
	case 리치:
		monster->Monster_Stat.STR = 6;
		monster->Monster_Stat.INT = 15;
		monster->Monster_Stat.VIT = 6;
		monster->Monster_Stat.AGI = 6;
		monster->Monster_Stat.DEX = 10;
		break;
	case 라이칸:
		monster->Monster_Stat.STR = 10;
		monster->Monster_Stat.INT = 4;
		monster->Monster_Stat.VIT = 10;
		monster->Monster_Stat.AGI = 10;
		monster->Monster_Stat.DEX = 6;
		break;
	case 데몬스파이더:
		monster->Monster_Stat.STR = 10;
		monster->Monster_Stat.INT = 10;
		monster->Monster_Stat.VIT = 14;
		monster->Monster_Stat.AGI = 8;
		monster->Monster_Stat.DEX = 10;
		break;
	}
}
