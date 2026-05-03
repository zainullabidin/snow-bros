#include"../../../include/characters/enemy/Boss.h"



// void Boss::drawHealthBar(RenderWindow& w) {
//     // Implementation for drawing the health bar will go here
// }

phaseStage Boss::getPhase() {
    return phase;
}

bool Boss::isBoss() {
    return true;
}