#include <Windows.h>

#include "Player.h"
#include "Enemy.h"
#include "GameLogic.h"

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

bool Player::isDead()
{
	return hp <= 0;
}

void Player::Fight(Enemy& enemy)
{
	std::cout << "Вы вступили в бой с врагом!\n\n1. Сражаться\n2. Убежать\n";

	char choice;
	std::cin >> choice;

	switch (choice)
	{
	case '1':
		// Цикл сражения: работает, пока кто то не умрёт
		while (!isDead() && !enemy.isDead())
		{
			clearConsole();
			std::cout << "===================================\n";
			std::cout << "Ваши HP: " << getHP() << "\n";
			std::cout << "HP врага: " << enemy.getHP() << "\n";

			std::cout << "\nВы атакуете врага на " << getAttack() << " урона!\n";
			enemy.TakeDamage(getAttack()); // Наносим урон противнику

			if (enemy.isDead())
			{
				std::cout << "Вы победили!\n";
				addGold(100);
				break;
			}

			std::cout << "\nВраг атакует вас на " << enemy.getAttack() << " урона!\n";
			TakeDamage(enemy.getAttack()); // Противник наносит урон игроку

			if (isDead())
			{
				std::cout << "Вас убили...\n";
				break;
			}
			std::cout << "===================================\n";

			char fightChoice;
			do
			{
				std::cout << "Продолжить сражение?\n1. Да\n2. Нет (убежать)\n";
				std::cin >> fightChoice;

				if (fightChoice == '1')
				{
					break;
				}
				else if (fightChoice == '2')
				{
					std::cout << "Вы убежали\n";
					Sleep(1500);
					clearConsole();
					return;
				}
				else
				{
					std::cout << "Такого варианта нет\n";
				}

			} while (true);
		}
		break;
	case '2':
		std::cout << "Вы убежали\n";
		Sleep(1500);
		clearConsole();
		break;
	default:
		std::cout << "Некорректный выбор. Бой отменён.\n";
		break;
	}
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

int Player::getAttack()
{
	return attack;
}

int Player::getHP()
{
	return hp;
}

int Player::getGold()
{
	return gold;
}