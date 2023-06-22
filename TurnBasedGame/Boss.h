#ifndef BOSS_H
#define BOSS_H

#include "MazeGame.h"

int randomInt(int min, int max);
void attackEnemy(Creature& enemy, int chance, int minDmg, int maxDmg);

class Boss : public Enemy {
private:

public:
	Boss() : Enemy(BOSS_HP) {}
	Boss(int health) : Enemy(BOSS_HP) {}
	Boss(int health, int maxHealth) : Enemy(health, maxHealth) {}

	void attack(Creature& player) {
		attackEnemy(player, 50, 30, 35);
	}
};

#endif