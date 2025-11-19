#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#define 몬스터의대화 3

typedef struct Pos {
	int x;
	int y;
}Pos;

// 구조체 선언
typedef enum MonsterType {
	슬라임,
	늑대,
	픽시,
	none
}Monstertype;

typedef struct _Monster {
	Monstertype type;
	char name[100]; // 배열도 포인터, 포인터로 표현할 수 있다.
	char dialogue[3][100]; // 대사
	Pos pos;
}Monster;

typedef enum _Location {
	물, 숲, 산, 들판
}Location;

// 배열

// 포인터

// 모든 몬스터가 같이 사용하는 함수, 몬스터 정보, 장소
void MonsterEncount(Monster* monster, Monster* monster2, Location location)
{
	// 몬스터가, 누군가와 조우했을 때면 실행한다.
   // 몬스터의 좌표가 같을 때만 아래 코드를 실행하세요.

	bool encount = monster->pos.x == monster2->pos.x && monster->pos.y == monster2->pos.y;
	if (!encount)
	{
		printf("두 몬스터는 따로있습니다.");
		return;
	}

	/*
	char* temp="";
	switch (location)
	{
	case 물: temp = "물"; break;
	case 숲: temp = "숲"; break;
	case 산: temp = "산"; break;
	case 들판: temp = "들판"; break;
	}
	*/

	char locationName[100];
	if (location == 물)
	{
		strcpy(locationName, "물");
	}
	else if (location == 숲)
	{
		strcpy(locationName, "숲");
	}
	else if (location == 산)
	{
		strcpy(locationName, "산");
	}
	else if (location == 들판)
	{
		strcpy(locationName, "들판");
	}
	else
	{
		printf("지정되지 않은 지역입니다. location 조건을 추가해주세요.");
		return;
	}


	//printf("%s 에서, %s 이(가) 나타났다!\n", temp, monster->name);
	printf("%s 에서, %s 이(가) 나타났다!\n", locationName, monster->name);

	int index = rand() % 3 + 1;
	printf("생성된 index 값 = %d \n", index);
	printf("[%s] : %s\n", monster->name, monster->dialogue[index - 1]);

	for (int index = 0; index < 몬스터의대화; index++)
	{
		printf("[%s] : %s\n", monster->name, monster->dialogue[index]);
		printf("[%s] : %s\n", monster2->name, monster2->dialogue[index]);
		Sleep(1000);
	}
}

void Monstername(Monster* monster)
{
	for (int i = 0; i < 10; i++)
	{
		int index = rand() % none;

		printf("만들어진 종족 : %d\n", index);
	}
}

int main()
{
	srand(time(NULL));

	Monster slim;
	Location location = (rand() % 4 + 1) - 1;
	printf("만들어진 location 값 : %d\n", location);
	strcpy(slim.name, "슬라임");
	slim.pos.x = 10;
	slim.pos.y = 10;
	strcpy(slim.dialogue[0], "난 나쁜 슬라임이 아니야!\n");
	strcpy(slim.dialogue[1], "보글보글 보보보글!\n");
	strcpy(slim.dialogue[2], "...!\n");

	Monster wolf;
	strcpy(wolf.name, "늑대");
	wolf.pos.x = 10;
	wolf.pos.y = 10;
	strcpy(wolf.dialogue[0], "왈 왈!\n");
	strcpy(wolf.dialogue[1], "컹 컹!\n");
	strcpy(wolf.dialogue[2], "멍 멍!\n");

	Monster pixy;
	strcpy(pixy.name, "픽시");
	pixy.pos.x = 10;
	pixy.pos.y = 9;
	strcpy(pixy.dialogue[0], "꺄르르륵!\n");
	strcpy(pixy.dialogue[1], "끼얏호우!\n");
	strcpy(pixy.dialogue[2], "보라색맛!\n");

	Monster monster_1;
	monster_1.type = (rand() % 4 + 1) - 1;
	Monstername(&monster_1);
	Monster monster_2;
	Monster monster_3;


	printf("%s : %s\n", slim.name, slim.dialogue);

	MonsterEncount(&slim, &wolf, location);
	//MonsterEncount(&wolf, location);
}