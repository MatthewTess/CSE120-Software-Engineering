#ifndef PLAYER_H
#define PLAYER_H

#include "MazeGame.h"

int randomInt(int min, int max);
void attackEnemy(Creature& enemy, int chance, int minDmg, int maxDmg);

class Player : public Creature {
private:
	Inventory inventory;

public:
	Inventory getInventory() {
		return inventory;
	}

	Player() : Creature(PLAYER_HP) {}

	Player(int maxHealth) : Creature(maxHealth) {}

	Player(std::string weaponName, std::string armorName) : Creature(PLAYER_HP) {
		this->inventory.setWeapon(weaponName);
		this->inventory.setArmor(armorName);
	}

	Player(std::string weaponName, std::string armorName, int potions) : Creature(PLAYER_HP) {
		this->inventory.setWeapon(weaponName);
		this->inventory.setArmor(armorName);
		this->inventory.setPotions(potions);
	}

	Player(int health, std::string weaponName, std::string armorName, int potions) : Creature(health) {
		this->inventory.setWeapon(weaponName);
		this->inventory.setArmor(armorName);
		this->inventory.setPotions(potions);
	}

	void setEquipment(std::string weaponName, std::string armorName) {
		this->inventory.setWeapon(weaponName);
		this->inventory.setArmor(armorName);
	}

	void usePotion() {
		if (inventory.getPotions() <= 0) {
			std::cout << "\nYou have no potions left!\n" << std::endl;
		}
		else if (getHealth() == PLAYER_MAX_HP) {
			std::cout << "\nYour health is already full!\n" << std::endl;
		}
		else {
			std::cout << "\nYou restored your health!\n" << std::endl;

			setHealth(getHealth() + 50);
			if (getHealth() > PLAYER_MAX_HP)
				setHealth(PLAYER_MAX_HP);
			
			inventory.setPotions(inventory.getPotions() - 1);
		}
	}	

	void openInventory() {
		std::cout << "\nInventory opened." << std::endl;
		int key = 0;
		while (key != 9) {
			std::cout << "-----------Inventory-----------\nWeapon: " << inventory.getWeapon()
				<< "\nArmor: " << inventory.getArmor()
				<< "\nAmount of Potions: " << inventory.getPotions() << std::endl;

			std::cout << "Do you want to use potion?" <<
				"\n1 - Yes\tTAB - No, close Inventory" << std::endl;

			key = _getch();

			while (key != 49 && key != 9) {
				std::cout << "Invalid input!" << std::endl;
				key = _getch();
			}

			if (key == 49)
				usePotion();
		}
		std::cout << "Inventory closed." << std::endl;
	}

	void lightAttack(Creature& enemy) {
		attackEnemy(enemy, 80, 15, 20);
	}

	void heavyAttack(Creature& enemy) {
		attackEnemy(enemy, 60, 50, 60);
	}
};

#endif