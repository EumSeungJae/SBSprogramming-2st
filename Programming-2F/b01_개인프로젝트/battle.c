#include "Entity.h"
#include "battle.h"


#include <stdio.h>

void Player_Ability_Setting(Entity_Setting_* player)
{
	player->Ability.MAX_HP = player->Stat.VIT * 50;
	player->Ability.MAX_MP = player->Stat.INT * 20;
	player->Ability.NOW_HP = player->Ability.MAX_HP;
	player->Ability.NOW_MP = player->Ability.MAX_MP;
	player->Ability.ATK = (player->Stat.STR * 5) + (player->Stat.DEX * 2);
	player->Ability.DEF = player->Stat.VIT * 3;
	player->Ability.MATK = player->Stat.INT * 4;
	player->Ability.MDEF = (player->Stat.VIT * 2) + (player->Stat.INT * 2);
	player->Ability.HIT = 80;
	player->Ability.CRT = 20;
	player->Ability.SPEED = player->Stat.AGI * 4;
}

void Monster_Ability_Setting(Entity_Setting_* monster, Entity_Setting_* player)
{

	float Enhance = player->Layer / 2; // 플레이어의 층;
	if ((int)Enhance < 1) Enhance = 1;

	monster->Ability.MAX_HP = (monster->Stat.VIT * 50) * (int)Enhance;
	monster->Ability.MAX_MP = (monster->Stat.INT * 20) * (int)Enhance;
	monster->Ability.NOW_HP = monster->Ability.MAX_HP;
	monster->Ability.NOW_MP = monster->Ability.MAX_MP;
	monster->Ability.ATK = ((monster->Stat.STR * 5) + (monster->Stat.DEX * 2)) * (int)Enhance;
	monster->Ability.DEF = (monster->Stat.VIT * 3) * (int)Enhance;
	monster->Ability.MATK = (monster->Stat.INT * 4) * (int)Enhance;
	monster->Ability.MDEF = ((monster->Stat.VIT * 2) + (monster->Stat.INT * 2)) * (int)Enhance;
	monster->Ability.HIT = 80;
	monster->Ability.CRT = 20;
	monster->Ability.SPEED = monster->Stat.AGI * 4;
	monster->Exp = monster->Exp * (int)Enhance;
}

void Monster_Encount(Entity_Setting_* monster_1, Entity_Setting_* monster_2, Entity_Setting_* player)
{

	// 조우하는 몬스터 기본 설정 1
	int Encount_Monster = rand() % 2;

	if (player->Layer == 1) {
		Encount_Monster = 1;
	}
	// 지금 2마리와 전투하게끔 고정시켜놧습니다.

	int* turn = 0;

	switch (Encount_Monster)
	{
	case 0:
		printf(" - 몬스터 1마리와 조우했다! - \n");
		Monster_Name_Library(monster_1, player);
		Monster_Status_Setting(monster_1);
		Monster_Ability_Setting(monster_1, player);

		printf("전투를 시작한다!\n");
		BattleSystem_Encount_1(monster_1, player, &turn);
		break;
	case 1:
		printf(" - 몬스터 2마리와 조우했다! - \n");
		Monster_Name_Library(monster_1, player);
		Monster_Status_Setting(monster_1);
		Monster_Ability_Setting(monster_1, player);

		Monster_Name_Library(monster_2, player);
		Monster_Status_Setting(monster_2);
		Monster_Ability_Setting(monster_2, player);
		printf("[%s] HP ) %d [%s] HP ) %d",
			monster_1->Name,
			monster_1->Ability.NOW_HP,
			monster_2->Name,
			monster_2->Ability.NOW_HP);

		printf("전투를 시작한다!\n");
		BattleSystem_Encount_2(monster_1, monster_2, player, &turn);
		break;
	}

}

void BattleSystem_Encount_1(
	Entity_Setting_* monster_1,
	Entity_Setting_* player,
	int* turn)
{
	// 스피드순으로 공격순서 나열
	Entity_Setting_* order[2] = { monster_1 , player };

	// ---------- 1) 속도 기준 정렬 ----------
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 2; j++) {
			if (order[i]->Ability.SPEED < order[j]->Ability.SPEED) {
				Entity_Setting_* temp = order[i];
				order[i] = order[j];
				order[j] = temp;
			}
		}
	}
	// 

	// ---------- 2) 동속 처리 ----------
	if (order[0]->Ability.SPEED == order[1]->Ability.SPEED)
	{
		for (int i = 0; i < 2; i++) {
			if (order[i]->Ability.SPEED == order[i + 1]->Ability.SPEED) {
				if (rand() % 2 == 1) {
					Entity_Setting_* temp = order[i];
					order[i] = order[i + 1];
					order[i + 1] = temp;
				}
			}
		}
	}

	// ---------- 3) turn 저장 ----------
	for (int i = 0; i < 2; i++) {
		order[i]->turn = i + 1;
	}

	printf("공격순서는 %s -> %s 순으로 공격한다.\n",
		order[0]->Name,
		order[1]->Name);


	// 전투
	while (monster_1->Ability.NOW_HP > 0 &&
		player->Ability.NOW_HP > 0)
	{


		// 공격순서에 맞는 공격실행
		for (int t = 0; t < 2; t++)
		{
			// 턴 증가
			(*turn)++;

			Entity_Setting_* attacker = order[t];
			Entity_Setting_* target;

			if (attacker->Ability.NOW_HP <= 0)
				continue; // 이미 죽은 개체는 스킵

			// 공격 대상 설정
			if (attacker->Type == 플레이어)
			{
				target = monster_1;
			}
			else
			{
				target = player;
			}

			Attack(attacker, target, *turn);

			Sleep(1500);
		}
		if (monster_1->Ability.NOW_HP <= 0)
		{
			printf("%s 는 쓰러졋다!\n", monster_1->Name);
			player->Exp += monster_1->Exp;
		}
		else if (player->Ability.NOW_HP <= 0)
		{
			printf("%s 는 쓰러졋다!\n", player->Name);
			player_DIE(player);
		}

	}


}


void BattleSystem_Encount_2(
	Entity_Setting_* monster_1, 
	Entity_Setting_* monster_2,
	Entity_Setting_* player, int* turn)
{
	// 스피드순으로 공격순서 나열
	Entity_Setting_* order[3] = { monster_1 , monster_2 , player };

	// ---------- 1) 속도 기준 정렬 ----------
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (order[i]->Ability.SPEED < order[j]->Ability.SPEED) {
				Entity_Setting_* temp = order[i];
				order[i] = order[j];
				order[j] = temp;
			}
		}
	}
	// 

	// ---------- 2) 동속 처리 ----------
	if (order[0]->Ability.SPEED == order[1]->Ability.SPEED ||
		order[1]->Ability.SPEED == order[2]->Ability.SPEED)
	{
		for (int i = 0; i < 2; i++) {
			if (order[i]->Ability.SPEED == order[i + 1]->Ability.SPEED) {
				if (rand() % 2 == 1) {
					Entity_Setting_* temp = order[i];
					order[i] = order[i + 1];
					order[i + 1] = temp;
				}
			}
		}
	}

	// ---------- 3) turn 저장 ----------
	for (int i = 0; i < 3; i++) {
		order[i]->turn = i + 1;
	}

	printf("\n공격순서는 %s -> %s -> %s 순으로 진행된다.\n",
		order[0]->Name,
		order[1]->Name,
		order[2]->Name);


	// 전투
	while ((monster_1->Ability.NOW_HP > 0 ||
		monster_2->Ability.NOW_HP > 0) && player->Ability.NOW_HP > 0)
	{


		// 공격순서에 맞는 공격실행
		for (int t = 0; t < 3; t++)
		{
			// 턴 증가
			(*turn)++;

			Entity_Setting_* attacker = order[t];
			Entity_Setting_* target;

			if (attacker->Ability.NOW_HP <= 0)
				continue; // 이미 죽은 개체는 스킵

			// 공격 대상 설정
			if (attacker->Type == 플레이어)
			{
				if (monster_1->Ability.NOW_HP > 0)
					target = monster_1;
				else
					target = monster_2;
			}
			else
			{
				target = player;
			}

			Attack(attacker, target, *turn);


			if (monster_1->Ability.NOW_HP <= 0)
			{
				printf("%s 는 쓰러졋다!\n", monster_1->Name);
				player->Exp += monster_1->Exp;
				BattleSystem_Encount_1(monster_2, player, turn);
			}
			else if (monster_2->Ability.NOW_HP <= 0)
			{
				printf("%s 는 쓰러졋다!\n", monster_2->Name);
				player->Exp += monster_2->Exp;
				BattleSystem_Encount_1(monster_1, player, turn);
			}
			else if (player->Ability.NOW_HP <= 0)
			{
				printf("%s 는 쓰러졋다!\n", player->Name);
				player_DIE(player);
			}

			Sleep(1500);
		}


	}

}

void Attack(Entity_Setting_* attacker, Entity_Setting_* target, int* turn)
{
	printf("\n [%d턴] %s 의 공격!\n", turn, attacker->Name);

	if (attacker->Ability.HIT >= (rand() % 100) + 1) {
		int damage = attacker->Ability.ATK - target->Ability.DEF;

		if (target->Stat.VIT >= (rand() % 100) + 1)
		{
			printf("%s이(가) %s의 공격을 가드했다!\n", target->Name, attacker->Name);
			damage / 2;
		}

		if ((int)damage < 1)
			damage = 1;


		target->Ability.NOW_HP -= (int)damage;

		if (target->Ability.NOW_HP < 0)
			target->Ability.NOW_HP = 0;

		printf("%s → %s : %d 데미지 (남은 HP: %d)\n",
			attacker->Name, target->Name,
			(int)damage, target->Ability.NOW_HP);
	}
	else {
		printf("%s 의 공격은 빗나갓다!\n", attacker->Name);
	}
}

void player_DIE(Entity_Setting_* player)
{
	if (player->Level > 1)
	{
		player->Level = player->Level - player->Layer;
		player->Layer = 0;
		player->Exp = 0;
	}
	else if (player->Level == 1)
	{
		player->Layer = 0;
		player->Exp = 0;
	}

}

void GameEnd()
{

}

