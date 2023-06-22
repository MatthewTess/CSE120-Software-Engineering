#ifndef INVENTORY_H
#define INVENTORY_H

#include "MazeGame.h"

//Class that represents player's inventory
class Inventory {
private:
	std::string weaponName;
	std::string armorName;
	int potions = 10;

public:
	std::string getWeapon() {
		return weaponName;
	}
	std::string getArmor() {
		return armorName;
	}
	int getPotions() {
		return potions;
	}

	void setWeapon(std::string weapon) {
		this->weaponName = weapon;
	}
	void setArmor(std::string armor) {
		this->armorName = armor;
	}
	void setPotions(int potions) {
		this->potions = potions;
	}

	Inventory() {
		potions = POTIONS;
	}

	Inventory(std::string weapon, std::string armor) {
		this->weaponName = weapon;
		this->armorName = armor;
		potions = POTIONS;
	}

	Inventory(std::string weapon, std::string armor, int potions) {
		this->weaponName = weapon;
		this->armorName = armor;
		this->potions = potions;
	}
};

#endif