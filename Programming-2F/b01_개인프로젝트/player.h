#pragma once
#include "Entity.h"
// 플레이어가 사용할 아이템 및 장비기초

void Creative_player(Entity_Setting_* player);
void Save_player(Entity_Setting_* player);
void Load_player(Entity_Setting_* player);
void Open_Player_Ability_view(Entity_Setting_* player);
void Open_Player_Status_Console(Entity_Setting_* player);
void ShowStatus(int stats[], const char* names[], int selected, int remainPoint);

