#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 함수 포인터
// 함수   : 입력값을 전달하면 출력을 반환한다.
// 포인터 : 가리키다. 주소 (0x). 
// 주소에서 데이터를 읽으려면 어떻게 해야하나요? = 어떤 형태인지 정의
// void 포인터 : 어떤 형태로든 바뀔 수 있는 주소 (형변환과 함께 사용하면)
// 포인터를 사용하는 이유 -> int *이름; *포인터변수; &변수;
// 1. 주소로 저장되어 있는 값에 접근할 수 있다. 
//  ㄴ범위가 다른 영역에서 주소에 저장된 값을 변경할 수 있다.
// 2. 주소의 크기 : 운영체제 32, 64, 사용자 정의 자료형(구조체)의 크기가 클 때 
// 3. 포인터 변수 : 주소는 가리키는 대상이 바뀔 수 있다.
// 4. 함수도 포인터 : 함수도 주소인가? 주소
void MonsterEncounter(const char* monsterName)
{
	const char* countMonster = monsterName;
	printf("조우한 몬스터의 이름 : %s\n", countMonster);
}

void Test(const char* a1)
{
	printf("%s\n", a1);
}

int Plus(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a + b);
}
int Minus(int a, int b)
{
	printf("%d - %d = %d\n", a, b, a - b);
}
int Multiplication(int a, int b)
{
	printf("%d x %d = %d\n", a, b, a * b);
}
int division(int a, int b)
{
	printf("%d / %d = %d\n", a, b, a / b);
}

void Callback()
{
	printf("콜백입니다\n");
}

typedef struct  {
	const char* name[100];

	int atk;
	int moveSpeed;

	void (*Action)(this); // 함수포인터 안에 함수포인터는 문법적으로 안된다.
}Monster;

void Move(const Monster* monster) // 리턴 값이 void, 인자 없음, 이름이 callback 함수 포인터 매개변수
{
	printf("[%s](은)는(%d)속도로 이동했다\n",monster->name, monster->moveSpeed);
}
void Attack(const Monster* monster)
{
	printf("[%s](은)는 (%d)공격력으로 공격했다\n",monster->name, monster->atk);
}
void Sample(void (*cbfp)())
{
	printf("sample 입니다.\n");
	cbfp();
}

int main()
{
	int a = 10;
	int b = 20;
	int* ptr = &a;
	printf("ptr 저장된 값 : %d\n", *ptr);
	ptr = &b;
	printf("ptr 저장된 값 : %d\n", *ptr);


	// a,b.ptr 이름을 게임에 등장하는 요소로 바꾸어서
	// const char* a1 = "고블린";
	// const char* a2 = "슬라임";
	// const char* countMonster = a1;
	// printf("조우한 몬스터의 이름 : %s\n", countMonster);
	// countMonster = a2;
	// printf("조우한 몬스터의 이름 : %s\n", countMonster);

	MonsterEncounter("고블린");

	printf("\n함수 포인터의 이해\n");
	// 함수도 주소인가?
	printf("함수 이름 : %p\n", MonsterEncounter);

	(*MonsterEncounter)("오크");
	void (*fp)(const char*) = MonsterEncounter;
	fp("스켈레톤");

	fp = Test;
	fp("Hello World");

	// 타입이 int 인자 int,int 함수를 저장하는 포인터를 생성하고 연결해보세요. (사칙연산)
	int (*mathfp)(int, int) = Plus;
	mathfp(2, 4);
	Plus(1,2);

	mathfp = Minus;
	mathfp(2, 4);
	Minus(3,4);

	Multiplication(5,6);
	division(10,2);

	// 함수 포인터를 사용하는 예제(2개)
	// 1. 구조체안에 함수 포인터를 저장하게 만들어보세요.
	// 몬스터 구조체. 어떤 행동을 할 것인가? 함수 포인터를 선언해보세요.

	/*
	Monster dodomaru;
	dodomaru.level = 4;
	dodomaru.name = "도도마루";
	if (플레이어_위치 > 5거리)
	{
		dodomaru.pattern = 돌진;
	}
	else if (플레이어_위치 < 공격사거리)
	{
		dodomaru.pattern = 공격;
	}
	else if (플레이어_행동 == 공격)
	{
		dodomaru.pattern = 회피;
	}
	*/
	Monster goblin; // init
	//goblin.name = "고블린"; < 이거 왜됨?
	strcpy(goblin.name,"고블린");
	goblin.atk = 2;
	goblin.moveSpeed = 10;
	goblin.Action = Attack; // 고블린 현재 행동 -> 공격
	goblin.Action(&goblin);		// 행동하세요.
	goblin.Action = Move;
	goblin.Action(&goblin);

	// 왜 구조체 안에 함수 포인터 사용해야 되나요?
	// 고블린(몬스터)이 공격했다.
	// 고블린(이동속도) 이동했다.
	// 구조체 해당하는 몬스터의 이름도 추가해서 Move, Attack함수에 추가해보세요

	Sample(Callback); // 함수가 함수를 인자로 받는 코드
	//void (*fp2)(const Monster*) = Attack;
	//fp2(&goblin);


	// 2. 함수를 실행시킬 수 있는 주소, 함수 안에 함수를 만들 수 있습니다.
	// 특정 기능이 끝났을 때 호출되는 함수를 구현해본다. (Call back 함수)

}