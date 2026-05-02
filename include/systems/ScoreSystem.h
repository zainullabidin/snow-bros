#pragma once
#include "../characters/enemy/Enemy.h"
#include <ctime>


void ScooooooreInc(const EnemyType& enemyType, float &score,  bool was_murdered_by_chainReaction);
void ScoreBonusLevel(float &score);