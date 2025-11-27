#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "monster_setting.h"

// 1. 주인공. 플레이어블 캐릭터. 조작하는 대상.
// 데이터로 표현하세요. 구조체로 만드세요.

// 키보드 입력을 받을건가? 화면의 이동을 구현할 것인가?
// printf(정보) (1) (2) (3) ...
// scanf (1) -> "결과"

// 게임목표 : 10줄 지우면 게임 클리어
// 목표를 쉽게 달성하지 못하게 하는 요인 추가.

// 게임 설꼐 : Data Init() 1번만 - GameLoop() 계속 - GameEnd()


/*
*  개발목표 : 변화의 미궁 탐사
*  입력방법 : 키보드입력
*  개발목차 :  1. 몬스터와 플레이어 제작
*				ㄴ 몬스터 15종 구성요소 제작
*			    ㄴ 플레이어 구성요소 제작
*				ㄴ 플레이어 스킬제작
*				ㄴ 아이템 제작
*			  2. 전투시스템 구성
*				ㄴ 데미지 시스템 제작
*					ㄴ 현재HP와 누적데미지 계산 과 완화
*				ㄴ 선공시스템 제작
*					ㄴ AGI에 의한 선공시스템
*			  3. 미궁건설
*				ㄴ 10층의 구성
*					ㄴ 계층이 높아질수록 몬스터 강화
*					ㄴ 일부 계층 돌파시 출현 몬스터 변경
*				ㄴ 10개의 방
*					ㄴ 4개의 몬스터룸, 3개의 공터, 2개의 이동룸, 1개의 이벤트룸
*					ㄴ 몬스터 조우시 2마리씩 랜덤출현
*  게임목표 : 10층의 보스 토벌
*
*  개발노트
* 몬스터와 플레이어의 기본적인 요소 스테이터스와 어빌리티 구축
* 플레이어의 기본 구조체 구축
* 몬스터의 기본 구조체 구축
* 미궁계층 + 방 구조체 선언
* 몬스터 enum 구조체 간편화 밑 몬스터 라이브러리 제작
* 랜덤 몬스터 출력 > 스위치로 몬스터 type 분류후 & 스텟분배
* 몬스터 능력치 배분 확인완료
* 전투시스템 완성 단/ 방어력 > 공격력 시 체력이 추가되어버림.
* 
*/






int main()
{
	srand(time(NULL));
	int layer = 1;
	Monster_Setting_ monster_1;

	Monster_Setting_ monster_2;

	monster_1.Monster_Ability.Damage = 0;
	monster_2.Monster_Ability.Damage = 0;

	Monster_Name_Library(&monster_1, layer);
	Monster_Status_Library(&monster_1);
	Monster_Ability_Setting(&monster_1, layer);
	printf("%d 층\n", layer);
	printf("몬스터_1 의 정보\n");
	printf("몬스터의 이름 : %s\n", monster_1.Name);
	printf("HP	: %d / %d\n", monster_1.Monster_Ability.NOW_HP, monster_1.Monster_Ability.MAX_HP);
	printf("MP	: %d / %d\n", monster_1.Monster_Ability.NOW_MP, monster_1.Monster_Ability.MAX_MP);
	printf("ATK : %d\n", monster_1.Monster_Ability.ATK);
	printf("MATK: %d\n", monster_1.Monster_Ability.MATK);
	printf("DEF : %d\n", monster_1.Monster_Ability.DEF);
	printf("MDEF: %d\n", monster_1.Monster_Ability.MDEF);
	// printf("AVO : %d\n", monster_1.Monster_Ability.AVOID);
	// printf("CRT : %d\n", monster_1.Monster_Ability.CRT);
	// printf("CRTD: %d\n", monster_1.Monster_Ability.CRTD);
	// printf("HIT	: %d\n", monster_1.Monster_Ability.HIT);
	printf("SPD : % d\n", monster_1.Monster_Ability.SPEED);

	Monster_Name_Library(&monster_2, layer);
	Monster_Status_Library(&monster_2);
	Monster_Ability_Setting(&monster_2, layer);
	printf("%d 층\n", layer);
	printf("몬스터_2 의 정보\n");
	printf("몬스터의 이름 : %s\n", monster_2.Name);
	printf("HP	: %d / %d\n", monster_2.Monster_Ability.NOW_HP, monster_2.Monster_Ability.MAX_HP);
	printf("MP	: %d / %d\n", monster_2.Monster_Ability.NOW_MP, monster_2.Monster_Ability.MAX_MP);
	printf("ATK : %d\n", monster_2.Monster_Ability.ATK);
	printf("MATK: %d\n", monster_2.Monster_Ability.MATK);
	printf("DEF : %d\n", monster_2.Monster_Ability.DEF);
	printf("MDEF: %d\n", monster_2.Monster_Ability.MDEF);
	// printf("AVO : %d\n", monster_1.Monster_Ability.AVOID);
	// printf("CRT : %d\n", monster_1.Monster_Ability.CRT);
	// printf("CRTD: %d\n", monster_1.Monster_Ability.CRTD);
	// printf("HIT	: %d\n", monster_1.Monster_Ability.HIT);
	printf("SPD : % d\n", monster_2.Monster_Ability.SPEED);

	

	while (monster_1.Monster_Ability.NOW_HP > 0 ||
		monster_2.Monster_Ability.NOW_HP > 0)
	{
		int Damage = 0;
		printf("배틀\n");

		if (monster_1.Monster_Ability.SPEED < monster_2.Monster_Ability.SPEED)
		{
			// 스피드로 인한 선공개념
			printf(" 선공권은 %s 가 가져간다.\n", monster_2.Name);
			// 몬스터 1이 받을 데미지
			monster_1.Monster_Ability.NOW_HP =
				monster_1.Monster_Ability.NOW_HP - (monster_2.Monster_Ability.ATK - monster_1.Monster_Ability.DEF);
			// 몬스터 1이 받는 데미지 출력
			printf(" %s 가 %s 에게 %d 의 데미지를 주었다!\n", monster_2.Name, monster_1.Name,
				monster_2.Monster_Ability.ATK - monster_1.Monster_Ability.DEF);
			// 몬스터 1의 현재 체력 출력
			printf("%s 의 남은 HP : %d\n",monster_1.Name, monster_1.Monster_Ability.NOW_HP);
			// 몬스터 2가 받을 데미지
			monster_2.Monster_Ability.NOW_HP =
				monster_2.Monster_Ability.NOW_HP - (monster_1.Monster_Ability.ATK - monster_2.Monster_Ability.DEF);
			// 몬스터 2가 받은 데미지 출력
			printf(" %s 가 %s 에게 %d 의 데미지를 주었다!\n", monster_1.Name, monster_2.Name,
				monster_1.Monster_Ability.ATK - monster_2.Monster_Ability.DEF);
			// 몬스터 2의 현재 체력 출력
			printf("%s 의 남은 HP : %d\n",monster_2.Name, monster_2.Monster_Ability.NOW_HP);
		}
		else if (monster_1.Monster_Ability.SPEED > monster_2.Monster_Ability.SPEED)
		{
			// 스피드로 인한 선공개념
			printf(" 선공권은 %s 가 가져간다.\n", monster_1.Name);
			// 몬스터 2이 받을 데미지
			monster_2.Monster_Ability.NOW_HP =
				monster_2.Monster_Ability.NOW_HP - (monster_1.Monster_Ability.ATK - monster_2.Monster_Ability.DEF);
			// 몬스터 2이 받는 데미지 출력
			printf(" %s 가 %s 에게 %d 의 데미지를 주었다!\n", monster_1.Name, monster_2.Name,
				monster_2.Monster_Ability.DEF - monster_1.Monster_Ability.ATK);
			// 몬스터 2의 현재 체력 출력
			printf("%s 의 남은 HP : %d",monster_2.Name, monster_2.Monster_Ability.NOW_HP);
			// 몬스터 1가 받을 데미지
			monster_1.Monster_Ability.NOW_HP =
				monster_1.Monster_Ability.NOW_HP - (monster_1.Monster_Ability.DEF - monster_2.Monster_Ability.ATK);
			// 몬스터 1가 받은 데미지 출력
			printf(" %s 가 %s 에게 %d 의 데미지를 주었다!\n", monster_2.Name, monster_1.Name,
				monster_1.Monster_Ability.DEF - monster_2.Monster_Ability.ATK);
			// 몬스터 1의 현재 체력 출력
			printf("%s 의 남은 HP : %d",monster_1.Name, monster_1.Monster_Ability.NOW_HP);

		}
		
		if (monster_1.Monster_Ability.NOW_HP <= 0)
		{
			printf("%s 는 쓰러졋다!", monster_1.Name);
			break;
		}
		else if (monster_2.Monster_Ability.NOW_HP <= 0)
		{
			printf("%s 는 쓰러졋다!", monster_2.Name);
			break;
		}

	}
	_getch();
}