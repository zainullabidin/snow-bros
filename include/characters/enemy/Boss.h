#pragma once
#include "Enemy.h"

enum class phaseStage { PHASE_1, PHASE_2, PHASE_3 };

class Boss : public Enemy {
protected:
	phaseStage phase;

public:
	Boss(): phase(phaseStage::PHASE_1)
	{
		gemDrop = 200;
		health = 100;      // initially full health
		maxHealth = 100;
	};

    virtual ~Boss() {};

	virtual void onPhaseChange() = 0;
	// virtual void drawHealthBar(sf::RenderWindow& w);

	phaseStage getPhase ();
	bool isBoss() override;

};