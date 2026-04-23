#include"../../../include/characters/enemy/Boss.h"

//=====================================================================
// needs health bar implementation
//====================================================================


// void Boss::drawHealthBar(sf::RenderWindow& w) {
//     // Implementation for drawing the health bar will go here
// }

phaseStage Boss::getPhase() {
    return phase;
}

bool Boss::isBoss() {
    return true;
}