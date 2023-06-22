#ifndef MAZEGAME_H
#define MAZEGAME_H

#define MAZE_SIZE 10

#define POTIONS 10

#define CREATURE_HP 100
#define CREATUR_MAX_HP 100

#define PLAYER_HP 100
#define PLAYER_MAX_HP 100

#define ENEMY_HP 100
#define ENEMY_MAX_HP 100

#define BOSS_HP 150
#define BOSS_MAX_HP 150

//included libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>

//included source files
#include "Inventory.h"
#include "Creature.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

int randomInt(int min, int max);
void attackEnemy(Creature& enemy, int chance, int minDmg, int maxDmg);
void showStats(Creature& player, Creature& enemy);
void playerInput(Player& player, Enemy& enemy, bool& isBlocking);
void fight(Player& player, Enemy& enemy);
void bossFight(Player& player, Boss& enemy);
void startMazeGame(Player& player);

#endif