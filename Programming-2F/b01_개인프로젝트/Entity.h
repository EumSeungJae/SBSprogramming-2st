#pragma once

//몬스터 종류
typedef enum _Monster_Select_Type {
	박쥐,
	고블린,
	스켈레톤,
	울프,
	스파이더,

	슬라임,
	홉고블린,
	스켈나이트,
	코볼트,
	포이즌스파이더,

	데몬슬라임,
	오크,
	리치,
	라이칸,
	데몬스파이더,
	Type_END,
	플레이어 = 98,
	BossMonster
}Monster_Type_;

// 플레이어가 사용할 아이템 및 장비기초
typedef struct _Item {
	int HP_heal;
	int MP_heal;
	int escape;
}Item_;

typedef struct _Equipment {
	int Main_weapon;
	int Sup_weapon;
	int Head;
	int Armor;
	int Boots;
	int Gloves;
}Equipment_;

// 능력치
typedef struct _Status {
	int STR;
	int INT;
	int VIT;
	int AGI;
	int DEX;
}Status_;

typedef struct _Ability {
	int MAX_HP; // 최대체력
	int MAX_MP; // 최대마나
	int NOW_HP; // 현재체력
	int NOW_MP; // 현재마나
	int Use_HP; // 소실체력
	int Use_MP; // 소실마나
	int ATK;    // 공격력
	int DEF;	// 방어력
	int MATK;	// 마법공격력
	int MDEF;	// 마법방어력
	int SPEED;  // 속도
	int AVOID;  // 회피
	int HIT;	// 명중
	int CRT;	// 크리티컬
	int CRTD;	// 크리티컬 데미지
}Ability_;

typedef struct _Entity {
	int Type;
	char Name[50];
	int Level;
	int Max_Exp;
	int Exp;
	int Layer;
	Status_ Stat;
	Ability_ Ability;
	int turn;
	int Stet_point;
	int Skill_point;
	int coin;
	int text_color;
	int bg_color;
	int room_type;
}Entity_Setting_;



// 몬스터용 함수

// 몬스터 이름 설정함수
void Monster_Name_Library(Entity_Setting_* monster, Entity_Setting_* player);
void Monster_Status_Setting(Entity_Setting_* monster);
void view_monster_Library(Entity_Setting_* Data1, Entity_Setting_* Data2);
void Monster_Library_Data();


