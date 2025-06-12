#include "Player.h"
#include "Enemy.h"

Player::Player(std::string name) : hp(20), attack(2), gold(1000), name(name) {}

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

void Player::buyItem(Item item)
{
	subtractGold(item.getPrice());
	AddItemToInventory(item);
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

void Player::addGold(int value)
{
	gold += value;
}

void Player::subtractGold(int value)
{
	if (gold >= value)
	{
		gold -= value;
	}
	else
	{
		std::cout << "Недостаточно золота!" << std::endl;
	}
}

int Player::getGold()
{
	return gold;
}