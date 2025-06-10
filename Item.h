#pragma once
#include <string>

class Player;

class Item
{
public:
	Item(std::string name, std::string type, int value, int price);
	void Use(Player& player);

	std::string getName() const { return name; }
	std::string getType() const { return type; }
	int getValue() const { return value; }
	int getPrice() const { return price; }

private:
	std::string name;
	std::string type;
	int value;
	int price;
};