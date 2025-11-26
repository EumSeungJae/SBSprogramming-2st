#pragma once

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

typedef struct Room {
	int Monster_room;
	int Void_room;
	int Event_room;
	int Up_room;
	int Down_room;
}F_Room;
