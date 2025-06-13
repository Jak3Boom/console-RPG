#pragma once
#include <iostream>
#include <string>

class Enemy
{
public:
	Enemy();

	void TakeDamage(int dmg);
	int getAttack();
	int getHP();
	bool isDead();

	void ShowStats();

private:
	std::string type;
	int hp;
	int attack;
};