#pragma once
#include "Entity.h"
#include <stdio.h>
#include <string.h>
#include "parson.h"

void Creative_player()
{
	JSON_Value* root_value;
	JSON_Array* items;
	JSON_Object* root_Object;

	root_value = json_parse_file("player.json");
	root_Object = json_value_get_object(root_value);


}
void Load_player()
{

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

void Open_Player_Ability_Console()
{

}

void Open_Player_Status_Console(Entity_Setting_ *player)
{
	printf("STR : %d\n", player->Stat.STR);
	printf("INT : %d\n", player->Stat.INT);
	printf("VIT : %d\n", player->Stat.VIT);
	printf("AGI : %d\n", player->Stat.AGI);
	printf("DEX : %d\n", player->Stat.DEX);
	

}

