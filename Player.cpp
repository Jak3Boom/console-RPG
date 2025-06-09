#include "Player.h"
#include "Enemy.h"

void Player::ShowStats()
{
	std::cout << "Имя:\t" << name << "\nХП:\t" << hp << "\nУрон:\t" << attack << "\nЗолото:\t" << gold << std::endl;
}

void Player::TakeDamage(int dmg)
{
	if (dmg < hp)
	{
		hp -= dmg;
	}
}

void Player::Heal(int amount)
{
	hp += amount;
}

void Player::AddItemToInventory(Item item)
{
	inventory.TakeItem(item);
}

void Player::ShowInventory()
{
	inventory.OpenInventory();
}

void Player::Fight(Enemy& enemy)
{
	
}