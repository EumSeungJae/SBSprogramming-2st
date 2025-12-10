#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "player.h"
#include "Entity.h"
#include <stdio.h>
#include <string.h>
#include "parson.h"
#include "Screen.h"



void Creative_player(Entity_Setting_* player)
{
	JSON_Value* root_value = json_parse_file("player.json");
	if (root_value == NULL)
		root_value = json_value_init_object();  // 파일 없으면 새로 생성

	JSON_Object* root_object = json_value_get_object(root_value);
	printf(" === 사용할 이름을 입력하세요 ===\n");
	printf(" 이름 : ");

	char name[32] = { 0 };  // 문자열 배열
	scanf("%31s", name);    // 안전한 입력

	strcpy(player->Name, name);
	json_object_set_string(root_object, "name", player->Name);

	player->Level = 1;
	json_object_set_number(root_object, "level", player->Level);

	player->Stat.STR = 5;
	player->Stat.INT = 5;
	player->Stat.VIT = 5;
	player->Stat.AGI = 5;
	player->Stat.DEX = 5;
	json_object_set_number(root_object, "STR", player->Stat.STR);
	json_object_set_number(root_object, "INT", player->Stat.INT);
	json_object_set_number(root_object, "VIT", player->Stat.VIT);
	json_object_set_number(root_object, "AGI", player->Stat.AGI);
	json_object_set_number(root_object, "DEX", player->Stat.DEX);

	player->Exp = 0;
	player->Max_Exp = 20;
	json_object_set_number(root_object, "Exp", player->Exp);
	json_object_set_number(root_object, "Max_Exp", player->Max_Exp);

	player->Layer = 0;
	json_object_set_number(root_object, "Layer", player->Layer);

	player->Type = 98;
	json_object_set_number(root_object, "Type", player->Type);

	player->coin = 10;
	json_object_set_number(root_object, "coin", player->coin);

	player->Stet_point = 0;
	player->Skill_point = 0;
	json_object_set_number(root_object, "Stet_point", player->Stet_point);
	json_object_set_number(root_object, "Skill_point", player->Skill_point);

	player->room_type = 0;
	json_object_set_number(root_object, "room_type", player->room_type);

	json_serialize_to_file(root_value, "player.json");
	json_value_free(root_value);
}
void Save_player(Entity_Setting_* player)
{
	JSON_Value* root_value = json_value_init_object(); // default Object 생성
	JSON_Object* root_object = json_value_get_object(root_value);

	json_object_set_string(root_object, "name", player->Name);

	json_object_set_number(root_object, "level", player->Level);
	json_object_set_number(root_object, "STR", player->Stat.STR);
	json_object_set_number(root_object, "INT", player->Stat.INT);
	json_object_set_number(root_object, "VIT", player->Stat.VIT);
	json_object_set_number(root_object, "AGI", player->Stat.AGI);
	json_object_set_number(root_object, "DEX", player->Stat.DEX);
	json_object_set_number(root_object, "Exp", player->Exp);
	json_object_set_number(root_object, "Max_Exp", player->Max_Exp);
	json_object_set_number(root_object, "Layer", player->Layer);
	json_object_set_number(root_object, "Stet_point", player->Stet_point);
	json_object_set_number(root_object, "Skill_point", player->Skill_point);
	json_object_set_number(root_object, "coin", player->coin);
	json_object_set_number(root_object, "room_type", player->room_type);

	json_serialize_to_file_pretty(root_value, "player.json");
	json_value_free(root_value);
}
void Load_player(Entity_Setting_* player)
{
	JSON_Value* loadrootValue = json_parse_file("player.json");
	if (loadrootValue == NULL) {
		printf("player.json 로드 실패! 초기값을 생성합니다.\n");
		return;
	}
	JSON_Object* loadrootObject = json_value_get_object(loadrootValue);

	const char* loadName = json_object_get_string(loadrootObject, "name");
	if (loadName != NULL)
		strcpy(player->Name, loadName);
	else
		strcpy(player->Name, "Unknown");

	player->Level = json_object_get_number(loadrootObject, "level");
	player->Stat.STR = json_object_get_number(loadrootObject, "STR");
	player->Stat.INT = json_object_get_number(loadrootObject, "INT");
	player->Stat.VIT = json_object_get_number(loadrootObject, "VIT");
	player->Stat.AGI = json_object_get_number(loadrootObject, "AGI");
	player->Stat.DEX = json_object_get_number(loadrootObject, "DEX");
	player->Exp = json_object_get_number(loadrootObject, "Exp");
	player->Max_Exp = json_object_get_number(loadrootObject, "Max_Exp");
	player->Layer = json_object_get_number(loadrootObject, "Layer");
	player->coin = json_object_get_number(loadrootObject, "coin");
	player->Stet_point = json_object_get_number(loadrootObject, "Stet_point");
	player->Skill_point = json_object_get_number(loadrootObject, "Skill_point");
	player->Type = json_object_get_number(loadrootObject, "Type");
	player->room_type = json_object_get_number(loadrootObject, "room_type");
	json_value_free(loadrootValue);
}

void Open_Player_Ability_view(Entity_Setting_* player)
{
	printf("========== 플레이어 능력치 ==========\n");
	gotoxy(2, 2);
	printf("이름 : %s", player->Name);
	gotoxy(20, 2);
	printf("레벨 : %d", (int)player->Level);

	gotoxy(2, 3);
	printf("경험치 : %d / %d",
		(int)player->Exp, (int)player->Max_Exp);

	gotoxy(2, 4);
	printf("HP : %d / %d", (int)player->Ability.NOW_HP, (int)player->Ability.MAX_HP);
	gotoxy(2, 5);
	printf("ATK : %d", (int)player->Ability.ATK);
	gotoxy(20, 5);
	printf("MATK : %d", (int)player->Ability.MATK);
	gotoxy(2, 6);
	printf("DEF : %d", (int)player->Ability.DEF);
	gotoxy(20, 6);
	printf("MDEF : %d", (int)player->Ability.MDEF);

	


	gotoxy(2, 7);
	printf("탐험중인 층 : %d", (int)player->Layer);

	printf("\n\n========== 플레이어 현상황 ==========\n");

}

void Open_Player_Status_Console(Entity_Setting_* player)
{
	system("cls");
	//ScreenInit();
	Open_Player_Ability_view(player);
	printf("레벨업을 실시합니다.\n");

	// 레벨업 처리
	while (1)
	{
		if (player->Exp >= player->Max_Exp)
		{
			printf("레벨업 하였습니다.\n");
			printf("Level : %d -> %d\n",
				player->Level, player->Level + 1);
			player->Level += 1;

			player->Exp -= player->Max_Exp;
			printf("남은 경험치 : %d\n", player->Exp);

			player->Max_Exp += (player->Max_Exp * 0.2);
			printf("다음 레벨업까지 : %d / %d\n",
				player->Exp, player->Max_Exp);
			printf("획득 스탯 포인트 : 5\n");
			player->Stet_point += 5;
		}

		/* 경험치 부족하면 레벨업 종료 */
		if (player->Exp < player->Max_Exp)
		{
			printf("현재 경험치가 부족하여 더 이상 레벨업할 수 없습니다.\n");
			Sleep(2000);
			break;
		}

	}


	int stats[5] = {
		player->Stat.STR,
		player->Stat.INT,
		player->Stat.VIT,
		player->Stat.AGI,
		player->Stat.DEX
	};
	const char* statNames[5] = {
		"STR",
		"INT",
		"VIT",
		"AGI",
		"DEX"
	};
	int selected = 0;
	int remainPoint = player->Stet_point;

	Open_Player_Ability_view(&player);

	while (1)
	{
	system("cls");

		ShowStatus(stats, statNames, selected, remainPoint);
		printf("↑↓ : 이동 | ←→ : 조정 | Enter : 확정\n");

		if (_kbhit())
		{
			int key = _getch();

			if (key == 224) // 방향키 입력
			{
				key = _getch();

				switch (key)
				{
				case 72: // ↑
					if (selected > 0)
						selected--;
					break;

				case 80: // ↓
					if (selected < 4)
						selected++;
					break;

				case 75: // ← (회수)
					if (stats[selected] > 1)
					{
						stats[selected]--;
						remainPoint++;
					}
					break;

				case 77: // → (투자)
					if (remainPoint > 0)
					{
						stats[selected]++;
						remainPoint--;
					}
					break;
				}
			}
			else if (key == 13) // Enter
			{
				system("cls");
				printf("=== 최종 스탯 분배 결과 ===\n");

				for (int i = 0; i < 5; i++)
					printf("%s : %d\n", statNames[i], stats[i]);

				printf("남은 포인트 : %d\n", remainPoint);
				printf("===========================\n");

				printf("확정하려면 아무 키나 누르세요.\n");
				_getch();
				break;
			}
		}

		Sleep(600);
	}
		printf("스탯이 성공적으로 적용되었습니다.\n");
	/* ================ [3] 스탯 반영 ================ */

	player->Stat.STR = stats[0];
	player->Stat.INT = stats[1];
	player->Stat.VIT = stats[2];
	player->Stat.AGI = stats[3];
	player->Stat.DEX = stats[4];
	player->Stet_point = remainPoint;

	Save_player(player);

	system("cls");
	Open_Player_Ability_view(player);
}
void ShowStatus(int stats[], const char* names[], int selected, int remainPoint)
{
	printf("=== 스탯 분배 ===\n");
	printf("남은 포인트 : %d\n", remainPoint);
	printf("-----------------\n");

	for (int i = 0; i < 5; i++)
	{
		if (i == selected)
			printf("> %s : %d\n", names[i], stats[i]);
		else
			printf("  %s : %d\n", names[i], stats[i]);
	}
	printf("-----------------\n");
}

void Open_Inventory_Console()
{
	// 장비장착
	// 아이템 확인
	// 아이템 파기
	// 아이템 사용

	// 아이템 저장
}

void Open_Shop_Console(int layer)
{

	// 지상에서만 사용가능
	// 지상에서 선택지로 이동
	// 돌파한 최대 층수에 따라 판매아이템 증가
	// 유저가 던전에서 사냥한 몬스터에 따라 확류로 판매아이템 갯수가 증가
}