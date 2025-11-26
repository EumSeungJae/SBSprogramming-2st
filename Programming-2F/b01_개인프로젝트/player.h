#pragma once





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

void Open_Inventory_Console();
void Open_Shop_Console();
void Open_Player_Ability_Console();
void Open_Player_Stetus_Console();