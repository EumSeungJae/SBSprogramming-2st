#pragma once

#include <stdio.h>
// RPG skill
// 스킬 이름

typedef enum SkillGrade
{
	Nomal, Rear = 5, Elit = 10 , Legend = 100
}SkillGrade;

typedef struct ShopSkillInfo
{
	int price;
	// 등급에 따라 등장하는 수치를 다르게 한다.
	// (1~90) 100 높은 등급은 숫자가 크다
	int ExpressWeight;

}ShopSkill;


typedef struct Skill
{
	char name[50];
	SkillGrade Grade;
	ShopSkillInfo shopInpo;

}Skill;

typedef struct ShopManager
{
	Skill skill[5]; // 어떤 기능을 해금을 해서 상점에 나오는 아이템의 수가 1 증가한다.
}ShopManager;

typedef struct Player
{
	int money;
};

void CalculateGradeWithExpressWeight(Skill skill)
{
	return skill.Grade * 10; // 0 - 50 - 100 - 1000
}

void ShopPhase(ShopManager manager, Player player)
{
	printf(" == 상점에서 팔고 있는 아이템의 목록 ==");
	for (int i = 0; i < 5; i++)
	{
		printf("[%d] | %s | %d \n", i, manager.skill[i].name, manager.skill[i].shopInpo.price);
	}
}

void BuySkill(int money,ShopSkillInfo info)
{
	if (money < info.price) return; // 구매할 수 있는 조건이 아니면 실행하지 말 것

	// 유저의 스킬에 포함시킨다.
}
void E