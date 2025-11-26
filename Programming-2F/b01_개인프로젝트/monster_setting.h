#pragma once

#include "monster.h"


typedef struct M_Status {
	int STR;
	int INT;
	int VIT;
	int AGI;
	int DEX;
}Status_M;

typedef struct M_Ability {
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
}Ability_M;

typedef struct _Monster_Setting {
	int Monster_Type;
	char Name[100];
	int Level;
	int Exp;
	Status_M Monster_Stat;
	Ability_M Monster_Ability;
}Monster_Setting_;

// 몬스터 이름 설정함수
void Monster_Name_Library(Monster_Setting_* monster, int layer);

