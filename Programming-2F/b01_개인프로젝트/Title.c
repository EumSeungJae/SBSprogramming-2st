#include "Title.h"
#include "Screen.h"
#include <stdio.h>
#include <Windows.h>

// 게임 시작 - 게임 종료 - 최고점수

void view_Title()
{
	int titleCursor = 10;   // 10 / 12 / 14
	
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
					break;
				case 12:  // 점수
					
					// 점수 페이지 나중에 구현
					break;
				case 14:  // 종료
					exit(0);
				}
			}
		}
		TitleRender(&titleCursor);

	}
	system("cls");
}


void TitleRender(int* titleCursor)
{
	ScreenClear();

	ScreenPrint(20, 4, "타이틀");
	ScreenPrint(20, 5, "게임을 시작하기 위해서 키보드를 입력해주세요");

	ScreenPrint(20, 10, "시작");
	ScreenPrint(20, 12, "점수");
	ScreenPrint(20, 14, "종료");
	
	// 현재 선택된 위치에 커서 출력
	ScreenPrint(16, *titleCursor, ">>");
	ScreenFlipping();
}