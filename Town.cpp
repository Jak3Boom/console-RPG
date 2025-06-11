#include <iostream>

#include "Town.h"

Town::Town(const std::string& name, const std::string& desc, const std::string& shopName, const std::vector<Item>& items)
	: Location(name, desc),
	  shop(shopName, items) {}

void Town::Enter()
{
	std::cout << "Добро пожаловать в город " << name << "!" << std::endl;
	std::cout << description << "\n" << std::endl;
}

char Town::Action()
{
	std::cout << "=== МЕНЮ ГОРОДА ===" << std::endl;
	std::cout << "1. Торговец" << std::endl;
	std::cout << "2. Карта" << std::endl;

	char choice;
	std::cin >> choice;

	return choice;
}