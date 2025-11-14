#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy 
#include <stdlib.h> // malloc, free 

// 형변환(Type casting) : int, char, unsigned char // int -> float

typedef enum {
	정수, 실수, 데이터
}CustomType;

// 구조체 선언.
typedef struct
{
	int value;
	char* text;

}Data;

typedef enum {
	불, 물, 풀
}MonsterType; // 상성 시스템








typedef struct {
	MonsterType monsterType;

	// 누가 우위에 있는가?
	// 우위에 있을 때 얼마만큼의 benefit 받는가?
	// if(비교 대상보다 우위에 있다면) benefit 함수를 실행하라
}Monster;

void* CompareMonsterType(MonsterType a, MonsterType b)
{
	return 1; // 크다
	return 0; // 같다
	return -1; // 작다
}

// 타입이 쌜때 같을때 클때 한번에 표현할 수 있는 함수. void*
void SelectTypeResult()
{

}

void Strength()
{

}
void EqualThanOther()
{

}
void WeakThanOther()
{

}

void TypeSynergyAttcked(Monster a, Monster b)
{
	if (CompareMonsterType(a.monsterType, b.monsterType) < 0)
	{

	}


}

void SelectNyumberByType(void* selectedPtr, CustomType type)
{
	// 어떤 조건을 기준으로 : 실수 타입이면 실수로, 정수 타입이면 정수로 읽어라.

	if (type == 실수)
	{
		// 실수
		// 정수값을 저장을 해서, 실수로 변환한다음에 출력
		printf("%f\n", *(float*)selectedPtr);
	}
	else if (type == 정수)
	{
		// 정수
		printf("%d\n", *(int*)selectedPtr);
	}
	else if (type == 데이터)
	{
		// 데이터의 value text 출력하는 코드
		// void* 주소만 저장하는. 자료형 읽을래
		
		printf("value 의 내용 : %d\n", ((Data*)selectedPtr)->value);
		printf("text의 내용 : %s\n", ((Data*)selectedPtr)->text);
	}

}

void PointerCastingTest()
{
	CustomType m_type1 = 정수;
	CustomType m_type2 = 실수;
	CustomType m_type3 = 데이터;
	int a = 10;
	float b = 0.5f;

	Data data;
	data.text = malloc(sizeof(char) * 100);
	strcpy(data.text, "피카피카");
	data.value = 10;

	SelectNyumberByType(&a, m_type1);
	SelectNyumberByType(&b, m_type2);
	SelectNyumberByType(&data , m_type3);

}


int main()
{
	// 예제
	// 최대 체력
	// 현재 체력
	// 비율 ? / ?

	int MaxHP = 100;
	int NowHP = MaxHP;
	NowHP -= 20;

	float ratio = (float)NowHP / MaxHP;
	// 정수 / 정수 그 결과값을 정수형으로 출력한다.
	printf("현재 체력 (%d) / 최대 체력 (%d) = 체력비율(%0.2f)\n", NowHP, MaxHP, ratio * 100);

	// 명시적 형변환 : (타입), 형변환이 일어났음을 직접 선언 
	// 묵시적 형변환 : 자동으로 발생하는 형변환

	// case1. 실수, 정수 연산처리할 때 => 실수로 변경된다.
	// 데이터가 버려지는 크기 생각 . 실수가 정수보다 우선적으로 처리해야한다.
	// 1.111 -> 1
	// 1 -> 1.000

	// case2. 작은 값 큰쪽으로 맞춰야 한다.
	int a = 129;        // 4바이트 [00][00][00][10000001]
	char b = 127;       // 1바이트 [10000001]
	// a = (int)b;
	printf("b의 값 : %d\n", b);

	// case2-2. 양수, 음수 구별하는 방법 : MSB 0 , 1 음수
	// signed extension 부호 확장 방법

	// case3. 포인터를 형변환하면 어떤 일이 일어날까?
	int* aPtr = &a;

	// (리틀, 빅) 엔디안
	// 주소 : 작은 바이트 단위부터 읽는 방식.
	printf("aPtr의 값 : %d\n", *(char*)aPtr);
	//포인터 주소인데, 포인터에 타입을 선언을 하고 * 붙이는 이유가 뭘가요?
	// char* -> 시작 주소로부터 몇개의 바이트를 어떻게 해석할건가.
	// int*

	// void* (generic)범용 포인터 - 일반적인 포인터 - 누구나 사용할 수 있다.
	// 타입이 선언되지 않은 주소를 만들 수 있으면 뭔가를 할 수 있겠다.


	void* generalPtr1 = &a;
	void* generalPtr2 = &b;

	printf("generalPtr1의 값 : %0.2f\n", *(float*)generalPtr1);
	printf("generalPtr2의 값 : %d\n", *(char*)generalPtr2);

	// 실수 정수 곱한다음에 소수점의 값이 0.5 작으면 버리고 그게 아니면 올리는 반올림 구현
	// 조건문
	/*
	int num1=7;
	float num2=0.4f;
	float num3 = num1 * num2;
	printf(" num3의 값 : %0.1f\n", num3);
	if ((int)num3 - num3 < 0.5)
		num3++;

	else
	{
		num3 = (int)num3;
	}

	printf(" num3의 값 : %0.1f\n", num3);
	*/
	int c = 7;
	float d = 0.2f;

	int result = c * d;




	// 포인터 예제
	PointerCastingTest();


}


