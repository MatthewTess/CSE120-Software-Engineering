#ifndef CREATURE_H
#define CREATURE_H

#include "MazeGame.h"

int randomInt(int min, int max);

class Creature {
private:
	int health;
	int maxHealth;

public:
	int getHealth() {
		return health;
	}
	int getMaxHealth() {
		return maxHealth;
	}

	void setHealth(int health) {
		this->health = health;
	}
	void setMaxHealth(int maxHealth) {
		this->maxHealth = maxHealth;
	}

	Creature(int maxHealth) {
		this->health = maxHealth;
		this->maxHealth = maxHealth;
	}

	Creature(int health, int maxHealth) {
		this->health = health;
		this->maxHealth = maxHealth;
	}

	void calculateDamage(int damage) {
		health -= damage;
		if (health < 0)
			health = 0;
	}

	bool isDead() {
		if (health == 0) return true;
			
		return false;
	}
};

#endif