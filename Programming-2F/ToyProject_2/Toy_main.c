// 포인터 공부 어떻게 하면 되나요?
// 1. 정의 > 무엇인가? 왜 써야하는가?
// 2. * , int* , *변수이름    // 각 연산자가 어떻게 쓰는가?
// 3. 포인터와 배열의 관계
// 4. 포인터를 매개변수로 사용하는 함수를 만들어보세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>
#include "Screen.h"
#include "Title.h"
#include "Console.h"

// Player 좌표 구조체. x값과 y값을 수정할 수 있게 만들어보세요.

typedef struct PlayerPos {
	int x;
	int y;
}PlayerPos;

PlayerPos playerPos = { 0,0 };

PlayerPos ePos = { 5,5 };
PlayerPos ePos2 = { 5,10 };

bool isGameOver;

// bool

bool CollisionCheck(PlayerPos player, PlayerPos enemy)
{
	if (player.x == enemy.x && player.y == enemy.y)
	{
		//GoToXY(0, 80);
		//isGameOver = true;
		//_getch;
		return true;
	}
	else {
		return false;
	}
}

void PlayerControl(PlayerPos* playerPos, unsigned char input)
{



	// PlayerControl 함수로 이동할 예정
	if (_kbhit())
	{
		input = _getch();

		if (input == 224 || input == 0)
		{
			input = _getch();
			switch (input) {
			case 72:
				(*playerPos).y -= 1;
				//printf("상단\n");
				break;
			case 80:
				(*playerPos).y += 1;
				//printf("하단\n");
				break;
			case 75:
				(*playerPos).x -= 1;
				//printf("좌측\n");
				break;
			case 77:
				(*playerPos).x += 1;
				//printf("우측\n");
				break;

			}
		}
	}

	if ((*playerPos).x >= 80)
	{
		(*playerPos).x = (*playerPos).x - 1;
	}
	else if ((*playerPos).y >= 17)
	{
		(*playerPos).y = (*playerPos).y - 1;
	}
	else if ((*playerPos).x < 0)
	{
		(*playerPos).x = (*playerPos).x + 1;
	}
	else if ((*playerPos).y < 0)
	{
		(*playerPos).y = (*playerPos).y + 1;
	}



}

void Updata(PlayerPos* ePos)
{
	// 플레이어 이외에 이동하는 코드

	(*ePos).x++; // 화면 밖으로 이동하면 문제가 발생한다. 데이터 로직상으로 막아보세요.
	//ePos.y
	if ((*ePos).x >= 80)
	{
		(*ePos).x = 0;
	}
	else if ((*ePos).x < 0)
	{
		(*ePos).x++;
	}
	//ePos.y

	// enemy와 player가 충동했는가
	if (CollisionCheck(playerPos, *ePos))
	{
		isGameOver = true;
	}
	
	//CollisionCheck(playerPos, *ePos);

	Sleep(100);


}


void Render(PlayerPos playerPos, PlayerPos ePos)
{
	//system("cls");
	//GoTOXY(playerPos.x, playerPos.y);
	//printf("@");
	ScreenClear();
	ScreenPrint(playerPos.x, playerPos.y, "@");
	ScreenPrint(ePos.x, ePos.y, "#");
	ScreenFlipping();
}
bool Quit()
{
	// 게임이 종료될 조건을 Bool 반환하는 실수로 만들어서
	int input = 0;
	//scanf("%d", &input);
	if (isGameOver)
	{
		return true;
	}
	else {
		return false;
	}
}
// 1- 이동, 몬스터 이동, 화면 Rendering + Buffer
// 2- 타이틀
// 3- 상호작용 Interact

int main()
{
	// 화면을 2개 만들어 주세요

	ScreenInit();
	GameTitle();


	//int input = 0;
	unsigned char input = 0; // 화살표 224    -128 127

	while (1) // 게임 루프
	{
		// 로직
		// 조작하는 함수 playerhandle, playercontrol
		// Update (갱신하다)
		// 렌더 (데이터 변경되면 그 것을 실행하라)

		// 플레이어의 이동.
		// scanf(); <<< breaking point 엔터키를 칠때까지



		PlayerControl(&playerPos, input);
		Updata(&ePos);
		Render(playerPos, ePos);



		if (Quit())
		{
			break;
		}

	}
}

// 개발 노트

// 플레이어의 움직임을 조작해서 화면에 움직이게 구현 (데이터) . (화면출력)
// 버그    > 플레이어가 이전에 있었던 위치에 표시가 계속해서 남는다.
// 해야할일 > 각 기능을 함수에 넣기
// system("cls") 화면을 없애도록 수정 > 화면이 깜빡거리는 문제가 발생
// '화면버퍼' - 화면0 <-, 화면1<-
// 2번째 자율행동을 선택하는 존재를 생성
// 버그 > sleepUpdata 함수에서 참조되는 확인불가 외부기호탄생
// sleep 이 문제였음. 주석처리 > 자율행동할 2번째 유닛이 안움직임
// 정상작동가능 하지만 너무 빨라 속도를 줄일필요가있음.