#include "Enemy.h"

void Enemy::ShowStats()
{
	std::cout << "Type:\t" << type << "\nHP:\t" << hp << "\nAttack:\t" << attack << std::endl;
}

void Enemy::TakeDamage(int dmg)
{
	if (dmg < hp)
	{
		hp -= dmg;
	}
}