#ifndef ENEMY_H
#define ENEMY_H

#include "MazeGame.h"

int randomInt(int min, int max);
void attackEnemy(Creature& enemy, int chance, int minDmg, int maxDmg);

class Enemy : public Creature {
private:
	
public:
	Enemy() : Creature(ENEMY_HP) {}

	Enemy(int health) : Creature(health) {}
	
	Enemy (int health, int maxHealth) : Creature(health, maxHealth) {}

	void lightAttack(Creature& player) {
		attackEnemy(player, 80, 10, 15);
	}

	void heavyAttack(Creature& player) {
		attackEnemy(player, 50, 20, 30);
	}
	
};

#endif