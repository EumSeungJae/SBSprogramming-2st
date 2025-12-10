#define _CRT_SECURE_NO_WARNINGS
#include "labyrinth.h"
#include "player.h"
#include "battle.h"
#include <stdio.h>




void Labyrinth_Outside(
	Entity_Setting_* monster_1,
	Entity_Setting_* monster_2,
	Entity_Setting_* player
)
{
	printf("당신은 지금 지상에 있습니다.\n");
	printf("무얼하시겠습니까?\n\n");

	printf("[0] 던전입장\n");
	printf("[1] 레벨업 및 능력강화\n");
	printf("[2] 도서관\n");
	printf("[3] 종료\n");

	printf("\n당신의 행동 : ");
	int select = 0;
	scanf("%d", &select);

	switch (select) {
	case 0:
		player->Layer += 1;
		player->room_type = 0;
		Labyrinth_in_room(monster_1, monster_2, player);
		break;
	case 1:
		Open_Player_Status_Console(player);
		break;
	case 2:
		Monster_Library_Data();
		break;
	case 3:
		Save_player(player);
		printf("저장후 종료합니다.\n");
		Sleep(2000);
		exit(0);
		break;
	}
}

void Labyrinth_in_room(
	Entity_Setting_* monster_1,
	Entity_Setting_* monster_2,
	Entity_Setting_* player)
{
	system("cls");
	Open_Player_Ability_view(player);
	if (player->room_type > 4 && player->room_type < 9)
	{
		printf("당신은 지금 미궁의 빈공간에 있습니다.\n");
	}
	else if (player->room_type == 0 || player->room_type == 9)
	{
		printf("당신은 %d 층에 입장하였습니다.\n", player->Layer);
	}
	printf("무었을 하시겠습니까?\n");

	printf("[0] 탐색한다.\n");
	printf("[1] 휴식한다.\n");
	if (player->room_type == 0)
	{
		printf("[2] 올라간다.\n");
	}
	else if (player->room_type == 9 && player->Layer > 10)
	{
		printf("[2] 내려간다.\n");
	}

	int selet = 0;
	scanf("%d", &selet);

	switch (selet)
	{
	case 0:
		player->room_type = rand() % 10;
		switch (player->room_type)
		{
		case 0: // 상승방
			if (player->room_type == 0)
			{
				printf("올라가는 계단방이다.\n");

				printf("[0] 올라간다.\n");
				printf("[1] 탐색한다.\n");

				scanf("%d", &selet);

				switch (selet)
				{
				case 0:
					player->Layer -= 1;
					player->room_type = 9;
					break;
				case 1:
					player->room_type = rand() % 10;
					break;
				}

				return;
			}
			else if (player->room_type == 9 && player->Layer < 10)
			{
				printf("내려가는 계단방이다.\n");

				printf("[0] 내려간다.\n");
				printf("[1] 탐색한다.\n");
				scanf("%d", &selet);

				switch (selet)
				{
				case 0:
					player->Layer += 1;
					player->room_type = 0;
					break;
				case 1:
					player->room_type = rand() % 10;
					break;
				}

				return;
			}
			break;
		case 1:
		case 2:
		case 3:
		case 4: // 몬스터
			Monster_Encount(monster_1, monster_2, player);
			break;
		case 5:
		case 6:
		case 7: // 빈공간

			return;
		case 8: // 아이템 (미구현)

			return;
		case 9: // 하강방
			if (player->Layer == 10)
			{
				int turn = 0;
				Encount_Boss(monster_1);
				Monster_Ability_Setting(monster_1, player);
				printf("전투를 시작한다!\n");
				BattleSystem_Encount_1(
					monster_1,
					player,
					turn);
				if (monster_1->Ability.NOW_HP == 0)
				{
					printf("던전이 클리어되었다!");
					printf("마을로 돌아간다!");
					return;
				}
			}
			else {
				if (player->room_type == 0)
				{
					printf("올라가는 계단방이다.\n");

					printf("[0] 올라간다.\n");
					printf("[1] 탐색한다.\n");

					scanf("%d", &selet);

					switch (selet)
					{
					case 0:
						player->Layer -= 1;
						player->room_type = 9;
						break;
					case 1:
						return;
					}

					return;
				}
				else if (player->room_type == 9 && player->Layer < 10)
				{
					printf("내려가는 계단방이다.\n");

					printf("[0] 내려간다.\n");
					printf("[1] 탐색한다.\n");
					scanf("%d", &selet);

					switch (selet)
					{
					case 0:
						player->Layer += 1;
						player->room_type = 0;
						break;
					case 1:
						return;
					}

					return;
				}
			}

			break;
		}
		break;

	case 1:
		if (player->room_type > 1 && player->room_type < 4)
		{
			printf("체력과 마나가 회복되었다!\n");
			player->Ability.NOW_HP = player->Ability.MAX_HP;
			player->Ability.NOW_MP = player->Ability.MAX_MP;

			Save_player(player);
			printf("능력치를 강화하시겠습니까?\n");
			printf("[0] 강화한다. [1] 다음기회에.\n");

			scanf("%d", &selet);
			switch (selet)
			{
			case 0:
				Open_Player_Status_Console(player);
				break;
			case 1:
				return;
			}

			if (rand() % 3 == 0)
				Monster_Encount(monster_1, monster_2, player);
			return;

		}
		
	case 2:
		if (player->room_type == 0)
		{
			printf("올라가는 계단방이다.\n");

			printf("[0] 올라간다.\n");
			printf("[1] 탐색한다.\n");

			scanf("%d", &selet);

			switch (selet)
			{
			case 0:
				player->Layer -= 1;
				player->room_type = 9;
				break;
			case 1:
				player->room_type = rand() % 10;
				break;
			}

			return;
		}
		else if (player->room_type == 9 && player->Layer < 10)
		{
			printf("내려가는 계단방이다.\n");

			printf("[0] 내려간다.\n");
			printf("[1] 탐색한다.\n");
			scanf("%d", &selet);

			switch (selet)
			{
			case 0:
				player->Layer += 1;
				player->room_type = 0;
				break;
			case 1:
				player->room_type = rand() % 10;
				break;
			}

			return;
		}
		break;
	}

}

