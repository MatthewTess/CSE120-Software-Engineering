#include "MazeGame.h"

//Function to get random Integer number 
int randomInt(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

void attackEnemy(Creature& enemy, int chance, int minDmg, int maxDmg) {
	if (randomInt(1, 100) <= chance) {
		int damage = randomInt(minDmg, maxDmg);
		enemy.calculateDamage(damage);
		std::cout << "Succesfull attack! With " << damage << " damage." << std::endl;
	}
	else {
		std::cout << "Missed attack!" << std::endl;
	}
}

//Function to show player's and enemy's HP during the fight
void showStats(Creature& player, Creature& enemy) {
	std::cout << "Player's HP: " << player.getHealth() << "/" << player.getMaxHealth() <<
				"\tEnemy's HP: " << enemy.getHealth() << "/" << enemy.getMaxHealth() << std::endl;
}

//Function to read player's input during the fight
void playerInput(Player& player, Enemy& enemy, bool& isBlocking) {
	std::cout << "\nYour turn! What are you going to do?"
		<< "\n1 - Use Light Attack."
		<< "\t2 - Use Heavy Attack."
		<< "\t3 - Block enemy's attack."
		<< "\t4 - Use potion(" << player.getInventory().getPotions() << " potion(s) left)." << std::endl;

	std::cout << "\nYou choose: ";
	int key = 0;

	while (key != 1 && key != 2 && key != 3 && key != 4) {
		
		std::cin >> key;

		if (key == 1) {
			player.lightAttack(enemy);
			break;
		}
		else if (key == 2) {
			player.heavyAttack(enemy);
			break;
		}
		else if (key == 1) {
			isBlocking = true;
			break;
		}
		else if (key == 4) {
			player.usePotion();
			break;
		}
		else {
			std::cout << "Choose valid option!" << std::endl;
		}

	}
}

//Functions that describe the combat logic
void fight(Player& player, Enemy& enemy) {
	std::cout << "\nYou encountered an enemy!" << std::endl;

	showStats(player, enemy);
	bool isBlocking = false;

	while (player.getHealth() > 0 && enemy.getHealth() > 0) {
		
		playerInput(player, enemy, isBlocking);

		showStats(player, enemy);

		if (enemy.getHealth() <= 0) {
			std::cout << "\nYou defeated the enemy!" << std::endl;
		} 
		else {
			std::cout << "\nIt's enemy's turn!\nEnemy is attacking you";

			if (isBlocking) {
				std::cout << "!\nYou succesfully blocked it's attack!" << std::endl;
				isBlocking = false;
			}
			else {
				if (randomInt(0, 1) == 0) {
					std::cout << " using light attack!" << std::endl;
					enemy.lightAttack(player);
				}
				else {
					std::cout << " using heavy attack!" << std::endl;
					enemy.heavyAttack(player);
				}
			}
			showStats(player, enemy);
		}
	}
}

void bossFight(Player& player, Boss& boss) {
	std::cout << "\nYou encountered the boss!" << std::endl;

	showStats(player, boss);

	bool isBlocking = false;

	while (!player.isDead() && !boss.isDead()) {

		playerInput(player, boss, isBlocking);

		showStats(player, boss);

		if (boss.isDead()) {
			std::cout << "\nYou defeated the Boss!\nCongratulations you win!" << std::endl;
		}
		else {
			std::cout << "\nIt's boss turn!\nBoss is attacking you!" << std::endl;

			if (isBlocking) {
				std::cout << "You succesfully blocked it's attack!" << std::endl;
				isBlocking = false;
			}
			else {
				boss.attack(player);
			}
			showStats(player, boss);

			if (player.isDead()) {
				std::cout << "Game Over! You Lost!" << std::endl;
				return;
			}
		}
	}
}

//Function that describes the logic of the labyrinth
void startMazeGame(Player& player) {
	std::cout << "Welcome to the Maze!" << std::endl;

	std::string weaponName;
	std::cout << "\nChoose your weapon: ";
	std::getline(std::cin, weaponName);

	std::string armorName;
	std::cout << "Choose your armor: ";
	std::getline(std::cin, armorName);

	player.setEquipment(weaponName, armorName);

	std::cout << "\nHINT: press Tab to open the Inventory\n" << std::endl;
	
	srand((unsigned)time(NULL));
	
	std::string direction;

	for (int i = 1; i <= MAZE_SIZE; i++) {
		
		if (_getch() == 9)
			player.openInventory();

		std::cout << "\nWhich way do You want to go? (left ot right): ";
		std::cin >> direction;

		while (direction != "left" && direction != "right") {
			std::cout << "Invalid direction. Please enter left or right: ";
			std::cin >> direction;
		}

		int typeOfRoom = randomInt(-1, 1);

		if (typeOfRoom == -1) {
			//if getTypeOfRoom() returns -1 there is a trap in this room
			std::cout << "You stepped on a trap!" << std::endl;
			player.calculateDamage(10);

			std::cout << "Player's HP: " << player.getHealth() << std::endl;

			if (player.isDead()) {
				std::cout << "Game Over! You Lost!" << std::endl;
				return;
			}
		} 
		else if (typeOfRoom == 0) {
			
			Enemy enemy;
			fight(player, enemy);

			if (player.isDead()) {
				std::cout << "Game Over! You Lost!" << std::endl;
				return;
			}
		}
		else if (typeOfRoom == 1) {
			std::cout << "This room is empty." << std::endl;
		}
	}

	if (player.getHealth() != 0) {
		Boss boss;
		bossFight(player, boss);
	}
}
