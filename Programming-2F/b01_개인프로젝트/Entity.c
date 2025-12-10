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


	if (player->Layer >= 1 && player->Layer <= 3)
	{
		// 1층~3층
		int list[] = { 박쥐, 고블린, 스켈레톤, 울프, 스파이더 };
		monster->Type = list[type];
	}
	else if (player->Layer >= 4 && player->Layer <= 6)
	{
		int list[] = { 슬라임, 홉고블린, 스켈나이트, 코볼트, 포이즌스파이더 };
		monster->Type = list[type];
	}
	else if (player->Layer >= 7 && player->Layer <= 10)
	{
		int list[] = { 데몬슬라임, 오크, 리치, 라이칸, 데몬스파이더 };
		monster->Type = list[type];
	}
	else
	{
		printf("계층 몬스터 설정 오류");
	}


}

void Monster_Status_Setting(Entity_Setting_* monster)
{
	switch (monster->Type)
	{
	case 박쥐:
		strcpy(monster->Name, "박쥐");
		monster->Stat.STR = 1;
		monster->Stat.INT = 1;
		monster->Stat.VIT = 1;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 1;
		monster->Exp = 10;
		break;
	case 고블린:
		strcpy(monster->Name, "고블린");
		monster->Stat.STR = 3;
		monster->Stat.INT = 0;
		monster->Stat.VIT = 3;
		monster->Stat.AGI = 3;
		monster->Stat.DEX = 6;
		monster->Exp = 15;
		break;
	case 스켈레톤:
		strcpy(monster->Name, "스켈레톤");
		monster->Stat.STR = 3;
		monster->Stat.INT = 0;
		monster->Stat.VIT = 5;
		monster->Stat.AGI = 3;
		monster->Stat.DEX = 4;
		monster->Exp = 15;
		break;
	case 울프:
		strcpy(monster->Name, "울프");
		monster->Stat.STR = 3;
		monster->Stat.INT = 0;
		monster->Stat.VIT = 4;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 2;
		monster->Exp = 15;
		break;
	case 스파이더:
		strcpy(monster->Name, "스파이더");
		monster->Stat.STR = 3;
		monster->Stat.INT = 1;
		monster->Stat.VIT = 3;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 2;
		monster->Exp = 15;
		break;
	case 슬라임:
		strcpy(monster->Name, "슬라임");
		monster->Stat.STR = 4;
		monster->Stat.INT = 4;
		monster->Stat.VIT = 10;
		monster->Stat.AGI = 4;
		monster->Stat.DEX = 8;
		monster->Exp = 30;
		break;
	case 홉고블린:
		strcpy(monster->Name, "홉 고블린");
		monster->Stat.STR = 6;
		monster->Stat.INT = 4;
		monster->Stat.VIT = 7;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 7;
		monster->Exp = 30;
		break;
	case 스켈나이트:
		strcpy(monster->Name, "스켈나이트");
		monster->Stat.STR = 7;
		monster->Stat.INT = 2;
		monster->Stat.VIT = 8;
		monster->Stat.AGI = 7;
		monster->Stat.DEX = 6;
		monster->Exp = 30;
		break;
	case 코볼트:
		strcpy(monster->Name, "코볼트");
		monster->Stat.STR = 6;
		monster->Stat.INT = 3;
		monster->Stat.VIT = 7;
		monster->Stat.AGI = 10;
		monster->Stat.DEX = 4;
		monster->Exp = 30;
		break;
	case 포이즌스파이더:
		strcpy(monster->Name, "포이즌 스파이더");
		monster->Stat.STR = 5;
		monster->Stat.INT = 6;
		monster->Stat.VIT = 10;
		monster->Stat.AGI = 4;
		monster->Stat.DEX = 5;
		monster->Exp = 30;
		break;
	case 데몬슬라임:
		strcpy(monster->Name, "데몬 슬라임");
		monster->Stat.STR = 8;
		monster->Stat.INT = 8;
		monster->Stat.VIT = 20;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 8;
		monster->Exp = 50;
		break;
	case 오크:
		strcpy(monster->Name, "오크");
		monster->Stat.STR = 10;
		monster->Stat.INT = 4;
		monster->Stat.VIT = 18;
		monster->Stat.AGI = 8;
		monster->Stat.DEX = 10;
		monster->Exp = 50;
		break;
	case 리치:
		strcpy(monster->Name, "리치");
		monster->Stat.STR = 6;
		monster->Stat.INT = 18;
		monster->Stat.VIT = 6;
		monster->Stat.AGI = 6;
		monster->Stat.DEX = 14;
		monster->Exp = 50;
		break;
	case 라이칸:
		strcpy(monster->Name, "라이칸");
		monster->Stat.STR = 12;
		monster->Stat.INT = 6;
		monster->Stat.VIT = 12;
		monster->Stat.AGI = 12;
		monster->Stat.DEX = 8;
		monster->Exp = 50;
		break;
	case 데몬스파이더:
		strcpy(monster->Name, "데몬 스파이더");
		monster->Stat.STR = 10;
		monster->Stat.INT = 10;
		monster->Stat.VIT = 12;
		monster->Stat.AGI = 8;
		monster->Stat.DEX = 10;
		monster->Exp = 50;
		break;
	}
}

void view_monster_Library(Entity_Setting_* Data1, Entity_Setting_* Data2)
{
	Monster_Name_Library(Data1, Data2);
	char spawn[10] = { 0 };
	if (Data2->Layer > 0 && Data2->Layer < 4)
	{
		strcpy(spawn, "false");

		switch (Data1->Type)
		{
		case 박쥐:
			strcpy(spawn, "true");
			break;
		case 고블린:
			strcpy(spawn, "true");
			break;
		case 스켈레톤:
			strcpy(spawn, "true");
			break;
		case 울프:
			strcpy(spawn, "true");
			break;
		case 스파이더:
			strcpy(spawn, "true");
			break;
		}
	}
	else if (Data2->Layer > 3 && Data2->Layer < 7)
	{
		strcpy(spawn, "false");

		switch (Data1->Type)
		{
		case 슬라임:
			strcpy(spawn, "true");
			break;
		case 홉고블린:
			strcpy(spawn, "true");
			break;
		case 스켈나이트:
			strcpy(spawn, "true");
			break;
		case 코볼트:
			strcpy(spawn, "true");
			break;
		case 포이즌스파이더:
			strcpy(spawn, "true");
			break;
		}
	}
	else if (Data2->Layer > 6 && Data2->Layer < 11)
	{
		strcpy(spawn, "false");

		switch (Data1->Type)
		{
		case 데몬슬라임:
			strcpy(spawn, "true");
			break;
		case 오크:
			strcpy(spawn, "true");
			break;
		case 리치:
			strcpy(spawn, "true");
			break;
		case 라이칸:
			strcpy(spawn, "true");
			break;
		case 데몬스파이더:
			strcpy(spawn, "true");
			break;
		}
	}

	Monster_Status_Setting(Data1);
	Monster_Ability_Setting(Data1, Data2);
	printf("선택된 층 : %d\n", Data2->Layer);
	printf("출현 : %s\n", spawn);
	printf("몬스터의 이름 : %s\n", Data1->Name);
	printf("HP	: %d / %d\n", Data1->Ability.NOW_HP, Data1->Ability.MAX_HP);
	printf("MP	: %d / %d\n", Data1->Ability.NOW_MP, Data1->Ability.MAX_MP);
	printf("ATK : %d\n", Data1->Ability.ATK);
	printf("MATK: %d\n", Data1->Ability.MATK);
	printf("DEF : %d\n", Data1->Ability.DEF);
	printf("MDEF: %d\n", Data1->Ability.MDEF);
	printf("SPD : % d\n", Data1->Ability.SPEED);
}

void Monster_Library_Data()
{
	Entity_Setting_ Data1; // 더미 타입데이터
	Entity_Setting_ Data2; // 더미 계층데이터

	Data1.Type = 0;
	Data2.Layer = 1;

	int selected = 0;

	while (1)
	{
		system("cls");
		printf(" ========== 몬스터 도감 ==========\n");
		view_monster_Library(&Data1, &Data2);
		printf("↑↓ : 계층 | ←→ : 다음몬스터 | Enter : 나가기\n");

		if (_kbhit())
		{
			int key = _getch();

			if (key == 224) // 방향키 입력
			{
				key = _getch();

				switch (key)
				{
				case 72: // ↑계층조작
					Data2.Layer++;
					if (Data2.Layer > 10)
						Data2.Layer--;
					break;

				case 80: // ↓계층조작
					Data2.Layer--;
					if (Data2.Layer < 1)
						Data2.Layer++;
					break;

				case 75: // ← (이전장)
					Data1.Type--;
					if (Data1.Type < 0)
					{
						Data1.Type++;
					}

					break;

				case 77: // → (다음장)
					Data1.Type++;
					if (Data1.Type > Type_END)
					{
						Data1.Type--;
					}

					break;
				}
			}
			else if (key == 13) // Enter
			{

				return;
				break;
			}
		}
		Sleep(1000);
	}
}

void Encount_Boss(Entity_Setting_* monster)
{
	printf("보스와 마주쳣다!");

	strcpy(monster->Name, "스파이더 퀸");
	monster->Stat.STR = 12;
	monster->Stat.INT = 8;
	monster->Stat.VIT = 18;
	monster->Stat.AGI = 12;
	monster->Stat.DEX = 10;
	monster->Exp = 100;

}
