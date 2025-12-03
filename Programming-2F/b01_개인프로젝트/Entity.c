#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Entity.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void Monster_Name_Library(Entity_Setting_* monster, Entity_Setting_* player)
{
	monster->Stat.STR = 0;
	monster->Stat.INT = 0;
	monster->Stat.VIT = 0;
	monster->Stat.AGI = 0;
	monster->Stat.DEX = 0;

	int type = rand() % 5;

	if (player->Layer > 0 && player->Layer < 4)
	{

		switch (type)
		{
		case 0:
			strcpy(monster->Name, "박쥐");
			monster->Type = 박쥐;

			break;
		case 1:
			strcpy(monster->Name, "고블린");
			monster->Type = 고블린;

			break;
		case 2:
			strcpy(monster->Name, "스켈레톤");
			monster->Type = 스켈레톤;

			break;
		case 3:
			strcpy(monster->Name, "울프");
			monster->Type = 울프;

			break;
		case 4:
			strcpy(monster->Name, "스파이더");
			monster->Type = 스파이더;

			break;
		}
	}
	else if (player->Layer > 3 && player->Layer < 7)
	{

		switch (type)
		{
		case 0:
			strcpy(monster->Name, "슬라임");
			monster->Type = 슬라임;

			break;
		case 1:
			strcpy(monster->Name, "홉 고블린");
			monster->Type = 홉고블린;

			break;
		case 2:
			strcpy(monster->Name, "스켈나이트");
			monster->Type = 스켈나이트;

			break;
		case 3:
			strcpy(monster->Name, "코볼트");
			monster->Type = 코볼트;

			break;
		case 4:
			strcpy(monster->Name, "포이즌 스파이더");
			monster->Type = 포이즌스파이더;

			break;
		}
	}
	else if (player->Layer > 6 && player->Layer < 11)
	{

		switch (type)
		{
		case 0:
			strcpy(monster->Name, "데몬 슬라임");
			monster->Type = 데몬슬라임;

			break;
		case 1:
			strcpy(monster->Name, "오크");
			monster->Type = 오크;

			break;
		case 2:
			strcpy(monster->Name, "리치");
			monster->Type = 리치;

			break;
		case 3:
			strcpy(monster->Name, "라이칸");
			monster->Type = 라이칸;

			break;
		case 4:
			strcpy(monster->Name, "데몬 스파이더");
			monster->Type = 데몬스파이더;

			break;
		}
	}
	else
	{
		printf("cls");
		printf("계층 몬스터 설정 오류");
	}

}

void Monster_Status_Setting(Entity_Setting_* monster)
{
	switch (monster->Type)
	{
	case 박쥐:
		monster->Stat.STR = 1;
		monster->Stat.INT = 2;
		monster->Stat.VIT = 2;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 4;
		monster->Exp = monster->Stat.VIT;
		break;
	case 고블린:
		monster->Stat.STR = 3;
		monster->Stat.INT = 1;
		monster->Stat.VIT = 2;
		monster->Stat.AGI = 3;
		monster->Stat.DEX = 4;
		monster->Exp = monster->Stat.VIT;
		break;
	case 스켈레톤:
		monster->Stat.STR = 2;
		monster->Stat.INT = 0;
		monster->Stat.VIT = 3;
		monster->Stat.AGI = 2;
		monster->Stat.DEX = 2;
		monster->Exp = monster->Stat.VIT;
		break;
	case 울프:
		monster->Stat.STR = 5;
		monster->Stat.INT = 2;
		monster->Stat.VIT = 4;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 4;
		monster->Exp = monster->Stat.VIT;
		break;
	case 스파이더:
		monster->Stat.STR = 4;
		monster->Stat.INT = 4;
		monster->Stat.VIT = 5;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 4;
		monster->Exp = monster->Stat.VIT;
		break;
	case 슬라임:
		monster->Stat.STR = 4;
		monster->Stat.INT = 4;
		monster->Stat.VIT = 7;
		monster->Stat.AGI = 3;
		monster->Stat.DEX = 4;
		monster->Exp = monster->Stat.VIT;
		break;
	case 홉고블린:
		monster->Stat.STR = 5;
		monster->Stat.INT = 2;
		monster->Stat.VIT = 6;
		monster->Stat.AGI = 4;
		monster->Stat.DEX = 6;
		monster->Exp = monster->Stat.VIT;
		break;
	case 스켈나이트:
		monster->Stat.STR = 7;
		monster->Stat.INT = 2;
		monster->Stat.VIT = 8;
		monster->Stat.AGI = 5;
		monster->Stat.DEX = 6;
		monster->Exp = monster->Stat.VIT;
		break;
	case 코볼트:
		monster->Stat.STR = 6;
		monster->Stat.INT = 4;
		monster->Stat.VIT = 7;
		monster->Stat.AGI = 7;
		monster->Stat.DEX = 4;
		monster->Exp = monster->Stat.VIT;
		break;
	case 포이즌스파이더:
		monster->Stat.STR = 7;
		monster->Stat.INT = 6;
		monster->Stat.VIT = 10;
		monster->Stat.AGI = 8;
		monster->Stat.DEX = 8;
		monster->Exp = monster->Stat.VIT;
		break;
	case 데몬슬라임:
		monster->Stat.STR = 8;
		monster->Stat.INT = 8;
		monster->Stat.VIT = 14;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 8;
		monster->Exp = monster->Stat.VIT;
		break;
	case 오크:
		monster->Stat.STR = 10;
		monster->Stat.INT = 4;
		monster->Stat.VIT = 15;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 4;
		monster->Exp = monster->Stat.VIT;
		break;
	case 리치:
		monster->Stat.STR = 6;
		monster->Stat.INT = 15;
		monster->Stat.VIT = 6;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 10;
		monster->Exp = monster->Stat.VIT;
		break;
	case 라이칸:
		monster->Stat.STR = 10;
		monster->Stat.INT = 4;
		monster->Stat.VIT = 10;
		monster->Stat.AGI = 10;
		monster->Stat.DEX = 6;
		monster->Exp = monster->Stat.VIT;
		break;
	case 데몬스파이더:
		monster->Stat.STR = 10;
		monster->Stat.INT = 10;
		monster->Stat.VIT = 14;
		monster->Stat.AGI = 8;
		monster->Stat.DEX = 10;
		monster->Exp = monster->Stat.VIT;
		break;
	}
}

void Monster_Library_Data()
{
	Entity_Setting_ Data;
	int layer;
	int max_page = Type_END;


	switch (1)
	{
		Monster_Name_Library(&Data, layer);
		Monster_Status_Setting(&Data);
		Monster_Ability_Setting(&Data, layer);
		printf("몬스터의 이름 : %s\n", Data.Name);
		printf("HP	: %d / %d\n", Data.Ability.NOW_HP, Data.Ability.MAX_HP);
		printf("MP	: %d / %d\n", Data.Ability.NOW_MP, Data.Ability.MAX_MP);
		printf("ATK : %d\n", Data.Ability.ATK);
		printf("MATK: %d\n", Data.Ability.MATK);
		printf("DEF : %d\n", Data.Ability.DEF);
		printf("MDEF: %d\n", Data.Ability.MDEF);
		printf("SPD : % d\n", Data.Ability.SPEED);
	}
}