#pragma once
#include <iostream>
#include <string>
#include "Inventory.h"
#include "Item.h"

class Enemy;

class Player
{
public:
	Player(std::string name);

	void ShowStats();
	void TakeDamage(int dmg);
	void Heal(int amount);

	void buyItem(Item item);
	void AddItemToInventory(Item item);
	void ShowInventory();

	void Fight(Enemy& enemy);

	void addGold(int value);
	void subtractGold(int value);
	int getGold();

private:
	int hp;
	int attack;
	int gold;
	std::string name;
	Inventory inventory;
};