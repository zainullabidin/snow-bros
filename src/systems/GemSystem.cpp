#include"../../include/systems/GemSystem.h"

void gems_on_murder(const EnemyType& enemyType, int &gems)
{
    switch(enemyType)
    {
        case EnemyType::BOTOM:
            gems += 7;
            break;

        case EnemyType::FOOGA:
            gems += 15;
            break;

        case EnemyType::TORNADO:
            gems += 30;
            break;
        case EnemyType::MOGERA:
            gems += 200;
            break;
        case EnemyType::GAMAKICHI:
            gems += 500;
            break;
    }
}
void gems_on_bonus(int &gems){
    gems += 10;
}


