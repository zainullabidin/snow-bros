#include "../../include/systems/ScoreSystem.h"

void ScooooooreInc(const EnemyType &enemyType, float &score, bool was_murdered_by_chainReaction)
{
    srand(time(0));
    float addScore = 0;

    switch (enemyType)
    {
    case EnemyType::BOTOM:
        addScore = rand() % (500 - 100 + 1) + 100;
        if (was_murdered_by_chainReaction)
            addScore += addScore * 0.1; // 10 % bonussssss

        score += addScore;
        break;

    case EnemyType::FOOGA:
        addScore = rand() % (800 - 200 + 1) + 200;
        if (was_murdered_by_chainReaction)
            addScore += addScore * 0.1; // 10 % bonussssss

        score += addScore;
        break;

    case EnemyType::TORNADO:
        addScore = rand() % (1200 - 300 + 1) + 300;
        if (was_murdered_by_chainReaction)
            addScore += addScore * 0.1; // 10 % bonussssss
        score += addScore;
        break;

    // fixed for mogera and gamakichi
    case EnemyType::MOGERA:
        addScore = 5000;
        score += addScore;
        break;

    case EnemyType::GAMAKICHI:
        addScore = 10000;
        score += addScore;
        break;

    default:
        break;
    }
}

void ScoreBonusLevel(float &score)
{
    score += 1000;
}