#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 구조체 struct. 참조ref. Self 자기

typedef void (*CallBack)(int a,int b);

void Sample(void (*Cback)(int, int), int x, int y)
{
	printf("Hello World\n");
	Cback(x,y);
}

void Plus(int a, int b)
{
	printf(" %d + %d = %d\n", a, b, a + b);
}

typedef struct _Data{
	int value;
	struct _Data* next;
	void (*fp)(CallBack cb, int a, int b);
}Data;

typedef struct {
	Data* head;
}DataManager;

typedef struct {
	char c1;
	int d1;
}Text;

typedef struct {
	int Healing;
	int Deceleration;
	int Defense;
}_item_Effact;

typedef struct {
	char name[100]; // 동적 할당
	int number;
	_item_Effact Effect;
}_item;

typedef struct Item {
	char* namePtr;
	char* name[100];
	int price;
	int stat;
}Item;

// E또다른 Monster참조할 수 있게 만들어 보세요
// 형제를 가지는 몬스터다. => this 가지면 안된다.
typedef struct Monster {
	int HP;
	int ATK;
	int DEF;
	struct Monster* other;
	// 함수 포인터
	void (*Action_1)(struct Monster*);
	void (*Action_2)(this);
	void (*Action_3)(this);
}Monster;

void ActionWithBuddy(Monster* Buddy)
{
	printf("동료와 함께하는 기술!\n");
}

// 구조체, 자료형이 가지고 있는 크기를 더하면 사이즈가 나온다.
// 4 + 8 + 8 = 20
// 4(4) + 8 + 8 = 24
int main()
{
	Monster slim;
	slim.HP = 100;
	slim.DEF = 10;
	slim.Action_1 = ActionWithBuddy;
	slim.Action_2 = ActionWithBuddy;
	slim.Action_3 = ActionWithBuddy;
	Monster slim2;
	slim2.HP = 100;
	slim2.DEF = 10;
	slim2.Action_1 = ActionWithBuddy;
	slim2.Action_2 = ActionWithBuddy;
	slim2.Action_3 = ActionWithBuddy;
	slim2.other = &slim;
	slim.other = &slim2;

	slim.Action_1(slim.other);
	slim.Action_2(slim.other);

	Item item;
	item.namePtr = malloc(sizeof("빛나는 티끌"));
	item.namePtr = "빛나는 티끌";
	strcpy(item.name, "빛나는 티끌");
	printf("item에 포인터 이름 : %s\n", item.namePtr);
	printf("item에 배열 이름 : %s\n", item.name);
	printf("item에 크기 : %d\n", sizeof(item.namePtr));
	printf("item에 크기 : %d\n", sizeof(item.name));
	printf("item에 크기 : %d\n", sizeof(item.price));
	printf("item에 크기 : %d\n", sizeof(item.stat));

	/*
	_item healing_grenade;
	strcpy(healing_grenade.name, "회복수류탄");
	healing_grenade.number = 1;
	healing_grenade.Effect.Healing = 80;
	printf("item의 크기 : %d\n", sizeof(_item));
	printf("item의 크기 : %d\n", sizeof(healing_grenade));
	printf("item의 크기 : %d\n", sizeof(healing_grenade.name));
	printf("item의 크기 : %d\n", sizeof(healing_grenade.number));
	printf("item의 크기 : %d\n", sizeof(healing_grenade.Effect));
	*/

	Text t1;
	printf("Text의 크기 : %d\n", sizeof(Text));
	printf("Text의 크기 : %d\n", sizeof(t1));
	printf("Text의 크기 : %d\n", sizeof(t1.c1));
	printf("Text의 크기 : %d\n", sizeof(t1.d1));

	Data d1;
	printf("Data 구조체의 크기 : %d\n", sizeof(d1.fp));
	printf("Data 구조체의 크기 : %d\n", sizeof(d1.next));
	printf("Data 구조체의 크기 : %d\n", sizeof(d1.value));
	printf("Data 구조체의 크기 : %d\n", sizeof(d1));
	d1.value = 1;
	Data d2;
	d2.value = 10;
	d1.next = &d2;
	Data d3;
	
	

	for (int i = 0; i < 3; i++)
	{

	}

	DataManager dm;
	dm.head = &d1;
	

	//printf("dm이의 첫번째 데이터의 값 : %d\n", dm.head->value);
	//printf("dm이의 부번째 데티어의 값 : %d\n", d1.next->value);

}