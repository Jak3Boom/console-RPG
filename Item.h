#pragma once
#include <string>

class Player;

class Item
{
public:
	Item(std::string name, std::string type, int value);
	void Use(Player& player);

	std::string getName() {return name; }

	std::string getType() { return type; }

	int getValue() { return value; }

private:
	std::string name;
	std::string type;
	int value;
};