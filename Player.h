#pragma once
#include <iostream>
#include <string>
#include "Inventory.h"
#include "Item.h"

class Enemy;

class Player
{
public:
	Player(std::string name) : hp(20), attack(2), gold(100), name(name) {}

	void ShowStats();
	void TakeDamage(int dmg);
	void Heal(int amount);

	void AddItemToInventory(Item item);
	void ShowInventory();

	void Fight(Enemy& enemy);

private:
	int hp;
	int attack;
	int gold;
	std::string name;
	Inventory inventory;
};