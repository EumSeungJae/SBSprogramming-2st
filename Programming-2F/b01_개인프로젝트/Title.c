#include "Title.h"
#include "Entity.h"
#include "player.h"
#include "Screen.h"
#include <stdio.h>
#include <Windows.h>
#include "parson.h"

// 게임 시작 - 게임 종료 - 최고점수

void view_Title(Entity_Setting_* player)
{
	Creative_player(player);

	int titleCursor = 10;   // 10 / 12 / 14
	JSON_Value* loadrootValue = json_parse_file("player.json");
	if (loadrootValue == NULL) {
		printf("player.json 로드 실패! 초기값을 생성합니다.\n");
		return;
	}
	JSON_Object* loadrootObject = json_value_get_object(loadrootValue);

	FILE* fp = fopen("player.json", "r");

	system("cls");

	if (fp != NULL)
	{
		Load_player(player);
		while (1)
		{

			if (_kbhit())
			{
				int key = _getch();

				// 방향키
				if (key == 224)
				{
					key = _getch();

					if (key == 72)      // ↑
						titleCursor -= 2;
					else if (key == 80) // ↓
						titleCursor += 2;

					if (titleCursor < 10) titleCursor = 14;
					if (titleCursor > 14) titleCursor = 10;
				}

				// 엔터키
				if (key == 13)
				{

					switch (titleCursor)
					{
					case 10:  // 이어하기
						Load_player(player);
						return;
					case 12:  // 점수

						break;
					case 14:  // 종료
						exit(0);
					}
				}
			}
			TitleRender(&titleCursor, player);

		}
	}
	else
	{
		while (1)
		{

			if (_kbhit())
			{
				int key = _getch();

				// 방향키
				if (key == 224)
				{
					key = _getch();

					if (key == 72)      // ↑
						titleCursor -= 2;
					else if (key == 80) // ↓
						titleCursor += 2;

					if (titleCursor < 10) titleCursor = 14;
					if (titleCursor > 14) titleCursor = 10;
				}

				// 엔터키
				if (key == 13)
				{

					switch (titleCursor)
					{
					case 10:  // 시작
						
						return;
					case 12:  // 점수

						// 점수 페이지 나중에 구현
						break;
					case 14:  // 종료
						exit(0);
					}
				}
			}
			TitleRender(&titleCursor, player);

		}
	}
	system("cls");
}


void TitleRender(int* titleCursor, Entity_Setting_* player)
{
	ScreenClear();
	if (player->Type == 98)
	{
		ScreenPrint(20, 4, "미궁탐험");

		ScreenPrint(20, 10, "이어하기");
		ScreenPrint(20, 12, "점수");
		ScreenPrint(20, 14, "종료");

		ScreenPrint(20,16, "↑↓ : 이동 | Enter : 확정");

		// 현재 선택된 위치에 커서 출력
		ScreenPrint(16, *titleCursor, ">>");
	}
	else
	{
		ScreenPrint(20, 4, "미궁탐험");

		ScreenPrint(20, 10, "시작");
		ScreenPrint(20, 12, "점수");
		ScreenPrint(20, 14, "종료");

		ScreenPrint(20, 16, "↑↓ : 이동 | Enter : 확정");

		// 현재 선택된 위치에 커서 출력
		ScreenPrint(16, *titleCursor, ">>");
	}
	ScreenFlipping();
}