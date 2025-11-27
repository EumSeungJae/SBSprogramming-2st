#include "battle.h"


void Player_Ability_Setting(Player_* player)
{
	player->Player_Ability.MAX_HP = player->Player_Stat.VIT * 100;
	player->Player_Ability.MAX_MP = player->Player_Stat.INT * 50;
	player->Player_Ability.NOW_HP = player->Player_Ability.MAX_HP - player->Player_Ability.Damage;
	player->Player_Ability.NOW_MP = player->Player_Ability.MAX_MP - player->Player_Ability.Use_MP;
	player->Player_Ability.ATK = player->Player_Stat.STR * 5;
	player->Player_Ability.DEF = player->Player_Stat.VIT * 5;
	player->Player_Ability.MATK = player->Player_Stat.INT * 4;
	player->Player_Ability.MDEF = (player->Player_Stat.VIT * 2) + (player->Player_Stat.INT * 2);
	player->Player_Ability.AVOID = 5;
	player->Player_Ability.HIT = player->Player_Stat.DEX + 50;
	player->Player_Ability.CRT = 20;
	player->Player_Ability.CRTD = 2;
	player->Player_Ability.SPEED = player->Player_Stat.AGI * 4;
}
void Monster_Ability_Setting(Monster_Setting_* monster, int layer)
{
	int Enhance=1;
	switch (layer)
	{
	case 2: Enhance = layer / 2; break;
	case 3: Enhance = layer / 2; break;
	case 4: Enhance = layer / 2; break;
	case 5: Enhance = layer / 2; break;
	case 6: Enhance = layer / 2; break;
	case 7: Enhance = layer / 2; break;
	case 8: Enhance = layer / 2; break;
	case 9: Enhance = layer / 2; break;
	case 10:Enhance = layer / 2; break;
	}
	monster->Monster_Ability.MAX_HP = (monster->Monster_Stat.VIT * 50) *Enhance;
	monster->Monster_Ability.MAX_MP = (monster->Monster_Stat.INT * 20) * Enhance;
	monster->Monster_Ability.NOW_HP = (monster->Monster_Ability.MAX_HP - monster->Monster_Ability.Damage);
	monster->Monster_Ability.NOW_MP = (monster->Monster_Ability.MAX_MP - monster->Monster_Ability.Use_MP);
	monster->Monster_Ability.ATK = ((monster->Monster_Stat.STR * 5)+(monster->Monster_Stat.DEX*2 ))* Enhance;
	monster->Monster_Ability.DEF = (monster->Monster_Stat.VIT * 5) * Enhance;
	monster->Monster_Ability.MATK = (monster->Monster_Stat.INT * 4) * Enhance;
	monster->Monster_Ability.MDEF = ((monster->Monster_Stat.VIT * 2) + (monster->Monster_Stat.INT * 2)) * Enhance;
	// monster->Monster_Ability.AVOID = 5;
	// monster->Monster_Ability.HIT = monster->Monster_Stat.DEX + 50;
	// monster->Monster_Ability.CRT = 20;
	// monster->Monster_Ability.CRTD = 2;
	monster->Monster_Ability.SPEED = monster->Monster_Stat.AGI * 4;
}

void BattleEncount()
{

}