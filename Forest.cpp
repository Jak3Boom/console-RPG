#include "Forest.h"
#include <iostream>

Forest::Forest(const std::string& name, const std::string& desc) : Location(name, desc) {}

void Forest::Enter()
{
	std::cout << "Вы прибыли в " << name << "! Будьте осторожны!\n" << std::endl;
}

char Forest::Action()
{
	std::cout << "=== МЕНЮ ЛЕСА ===\n";
	std::cout << "1. Сразиться с монстром\n";
	std::cout << "2. Искать ресурсы\n";
	std::cout << "3. Вернуться\n";

	char choice;
	std::cin >> choice;

	return choice;
}