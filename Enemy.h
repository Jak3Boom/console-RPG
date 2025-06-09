#pragma once
#include <iostream>
#include <string>

class Enemy
{
public:
	Enemy() : hp(20), attack(1) {}

	void ShowStats();
	void TakeDamage(int dmg);

private:
	std::string type;
	int hp;
	int attack;
};