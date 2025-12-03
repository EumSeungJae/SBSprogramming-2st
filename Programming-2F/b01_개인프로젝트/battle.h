#pragma once

void Player_Ability_Setting(Entity_Setting_* player);
void Monster_Ability_Setting(Entity_Setting_* monster, Entity_Setting_* player);
void Monster_Encount(Entity_Setting_* monster_1, Entity_Setting_* monster_2, Entity_Setting_* player);
void BattleSystem_Encount_1(Entity_Setting_* monster, Entity_Setting_* player, int* turn);
void BattleSystem_Encount_2(Entity_Setting_* monster_1, Entity_Setting_* monster_2, Entity_Setting_* player, int* turn);
void Attack(Entity_Setting_* attacker, Entity_Setting_* target, int* turn);
void player_DIE(Entity_Setting_* player);
void GameEnd();
