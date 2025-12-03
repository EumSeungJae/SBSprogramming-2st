#define _CRT_SECURE_NO_WARNINGS

#include "Entity.h"
#include "battle.h"
#include "Screen.h"
#include "Title.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

// 1. 주인공. 플레이어블 캐릭터. 조작하는 대상.
// 데이터로 표현하세요. 구조체로 만드세요.

// 키보드 입력을 받을건가? 화면의 이동을 구현할 것인가?
// printf(정보) (1) (2) (3) ...
// scanf (1) -> "결과"

// 게임목표 : 10줄 지우면 게임 클리어
// 목표를 쉽게 달성하지 못하게 하는 요인 추가.

// 게임 설꼐 : Data Init() 1번만 - GameLoop() 계속 - GameEnd()


/*
*  개발목표 : 미궁 탐사 (텍스트 RPG)
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
*	ㄴ 
* 명중시스템 도입 기본 80 < 랜덤함수 로 20%확률로 회피가능
*	ㄴ 요구사항 : DEX로 명중률을 올리는 값을 추가하고싶음
*				  AGI로 피격률을 낮추는 값을 추가하고싶음
*		ㄴ 결정사항 : 2단 계산으로 명중치 계산이후 회피계산을 넣기로 결정 
* 몬스터 조우시스템 - 1~2 마리 조우시스템
*	ㄴ 한마리의 몬스터가 쓰러질시 남은 한마리와 전투 속행
* 배틀함수 일부 수정
*	ㄴ 수정내용 : 전투중 데미지 계산 정리.
*					
* 플레이어와 몬스터 2개의 공동전투를 위해 구조체를 통합시킴
* 3개체의 전투를 하고자 코딩을 짯지만 너무 난잡해져서 Ai를 통해
* 확 축소된 코딩을 출력 및 응용
* 
* 
*/






int main()
{
	ScreenInit();
	view_Title();

	srand(time(NULL));
	Entity_Setting_ m_1;
	
	Entity_Setting_ m_2;
	
	Entity_Setting_ player;
	strcpy(player.Name, "플레이어");
	player.Stat.STR = 5;
	player.Stat.INT = 5;
	player.Stat.VIT = 5;
	player.Stat.AGI = 5;
	player.Stat.DEX = 5;
	player.Layer = 1;
	player.Type = 플레이어;


	Player_Ability_Setting(&player);

	Monster_Encount(&m_1,&m_2,&player);

	_getch();
}

void AddData()
{

}

void SaveData()
{

}

void LoadData()
{

}