#pragma once

#include "player.h"

typedef struct P_Status {
	int STR;
	int INT;
	int VIT;
	int AGI;
	int DEX;
}Status_P;

typedef struct P_Ability {
	int MAX_HP; // 최대체력
	int MAX_MP; // 최대마나
	int NOW_HP; // 현재체력
	int NOW_MP; // 현재마나
	int Damage; // 받은 누적 피해량
	int Use_MP; // 사용마나
	int ATK;    // 공격력
	int DEF;	// 방어력
	int MATK;	// 마법공격력
	int MDEF;	// 마법방어력
	int SPEED;  // 속도
	int AVOID;  // 회피
	int HIT;	// 명중
	int CRT;	// 크리티컬
	int CRTD;	// 크리티컬 데미지
}Ability_P;

typedef struct _Player {
	char Name[100];
	int Level;
	int Exp;
	Status_P Player_Stat;
	Ability_P Player_Ability;
	int Stet_point;
	int Skill_point;
}Player_;