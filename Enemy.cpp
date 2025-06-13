#include "Enemy.h"

Enemy::Enemy() : hp(20), attack(1) {}

void Enemy::ShowStats()
{
	std::cout << "Type:\t" << type << "\nHP:\t" << hp << "\nAttack:\t" << attack << std::endl;
}

void Enemy::TakeDamage(int dmg)
{
	if (dmg <= hp)
	{
		hp -= dmg;
	}
}

int Enemy::getAttack()
{
	return attack;
}

int Enemy::getHP()
{
	return hp;
}

bool Enemy::isDead()
{
	return hp <= 0;
}
