#include "Title.h"
#include "Entity.h"
#include "player.h"
#include "Screen.h"
#include <stdio.h>
#include <Windows.h>
#include "parson.h"
#include <stdbool.h>

// 게임 시작 - 게임 종료 - 최고점수

void view_Title(Entity_Setting_* player)
{

	int titleCursor = 10;   // 10 / 12 / 14

	// JSON 존재 여부 확인
	JSON_Value* rootValue = json_parse_file("player.json");
	bool saveExists = (rootValue != NULL);



	if (saveExists) {
		Load_player(player);
	}
	else {
		memset(player, 0, sizeof(Entity_Setting_)); // 안전 초기화
	}

	// 네
	while (1)
	{
		system("cls");

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
				case 10:  // 이어하기 or 시작
					
					if (saveExists)
					{
						// 이미 Load_player 했으므로 그냥 return
						//json_value_free(rootValue);

						return;
					}
					else
					{
						Creative_player(player);
						Save_player(player);
						json_value_free(rootValue);
						return;
					}
					return;

				case 12:  // 점수 (추후)
					break;

				case 14:  // 종료
					json_value_free(rootValue);
					exit(0);
				}
			}
		}

		TitleRender(&titleCursor, player);
		Sleep(500);
	}
}



void TitleRender(int* titleCursor, Entity_Setting_* player)
{
	ScreenClear();
	if (player->Type == 98)
	{
		gotoxy(20, 4);
		printf("미궁탐험");
		//ScreenPrint(20, 4, "미궁탐험");

		gotoxy(20, 10);
		printf("이어하기");
		gotoxy(20, 12);
		printf("점수");
		gotoxy(20, 14);
		printf("종료");
		// ScreenPrint(20, 10, "이어하기");
		// ScreenPrint(20, 12, "점수");
		// ScreenPrint(20, 14, "종료");

		gotoxy(20, 16);
		printf("↑↓ : 이동 | Enter : 확정");
		//ScreenPrint(20, 16, "↑↓ : 이동 | Enter : 확정");

		// 현재 선택된 위치에 커서 출력
		gotoxy(16, *titleCursor);
		printf(">>");
		//ScreenPrint(16, *titleCursor, ">>");
		// 타이틀 내부에서만 스크린프린트를 사용하고있습니다.
		// 그리고 메인부터 다른함수는 프린트f를 사용하고있습니다.
	}
	else
	{

		gotoxy(20, 4);
		printf("미궁탐험");

		gotoxy(20, 10);
		printf("시작");
		gotoxy(20, 12);
		printf("점수");
		gotoxy(20, 14);
		printf("종료");
		// ScreenPrint(20, 10, "시작");
		// ScreenPrint(20, 12, "점수");
		// ScreenPrint(20, 14, "종료");

		gotoxy(20, 16);
		printf("↑↓ : 이동 | Enter : 확정");
		//ScreenPrint(20, 16, "↑↓ : 이동 | Enter : 확정");

		gotoxy(16, *titleCursor);
		printf(">>");
		// 현재 선택된 위치에 커서 출력
		//ScreenPrint(16, *titleCursor, ">>");

	}
	//ScreenFlipping();
}