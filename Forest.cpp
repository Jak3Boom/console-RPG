#include "Forest.h"
#include <iostream>

Forest::Forest(const std::string& name, const std::string& desc) : Location(name, desc) {}

void Forest::Enter()
{
	std::cout << "Вы прибыли в " << name << "! Будьте осторожны!" << std::endl;
}

char Forest::Action()
{
	return '0';
}