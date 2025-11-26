#include "Title.h"
#include "Console.h"
#include "Screen.h"
#include <stdio.h>

// 게임 시작 - 게임 종료 - 최고점수

void GameTitle()
{
	int titleCursor = 10;
		int input = 0;
	while (1)
	{
		GoToXY(16, titleCursor);
		SetDataYPosInput(&titleCursor, 10, 14, 2);

		// 입력했을 때 y의 좌표가 변경되어야 한다.


		if (_kbhit())
		{
			input = _getch();

			if (input == 224 || input == 0)
			{
				input = _getch();
				switch (input) {
				case 13:
					printf("0");

					break;
				}
			}
		}
		TitleRender(&titleCursor);
		
	}

	// 텍스트 입력으로 진행 하는 구조.
	//printf("0 : 시작 | 1 : 점수 확인 | 2 : 게임종료");
	//int a = 0;
	//scanf("%d", &a);
	// 숫자 0 1 2



	_getch();
}

void TitleRender(int* titleCursor)
{
	ScreenClear;

	ScreenPrint(20, 4, "타이틀");
	ScreenPrint(20, 5, "게임을 시작하기 위해서 키보드를 입력해주세요");

	ScreenPrint(20, 10, "시작");
	ScreenPrint(20, 12, "점수");
	ScreenPrint(20, 14, "종료");

}

void SetDataYPosInput(int* y, int Minheight, int MAXheight, int interval)
{
	ScreenPrint(16, &y, ">>");

	unsigned char input = 0;

	if (_kbhit())
	{
		input = _getch();

		if (input == 224 || input == 0)
		{
			input = _getch();
			switch (input) {
			case 72:
				*y - interval;

				break;
			case 80:
				*y + interval;

				break;

				if (*y >= MAXheight)
				{
					*y = MAXheight;
				}
				else if (*y <= Minheight)
				{
					*y = Minheight;
				}
			}
		}
	}
}