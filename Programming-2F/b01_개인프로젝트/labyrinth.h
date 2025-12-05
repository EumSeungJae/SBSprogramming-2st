#pragma once
#include "Entity.h"

typedef enum Layer {
	F0,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10
}F_Layer;

typedef enum Room {
	Monster_room,
	Void_room,
	Event_room,
	Up_room,
	Down_room
}Room;

void Labyrinth_Outside(
	Entity_Setting_* monster_1,
	Entity_Setting_* monster_2,
	Entity_Setting_* player);

void Labyrinth_in_room(
	Entity_Setting_* monster_1,
	Entity_Setting_* monster_2,
	Entity_Setting_* player);

void labyrinth_up_down(Entity_Setting_* player, int* room_type);