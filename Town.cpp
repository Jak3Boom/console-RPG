#include "Town.h"
#include <iostream>

Town::Town(const std::string& name, const std::string& desc) : Location(name, desc) {}

void Town::Enter()
{
	std::cout << "Добро пожаловать в город " << name << "!" << std::endl;
	std::cout << description << std::endl;
}

void Town::Action()
{

}