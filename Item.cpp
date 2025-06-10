#include "Item.h"
#include "Player.h"

Item::Item(std::string name, std::string type, int value, int price) :
	name(name),
	type(type),
	value(value),
	price(price) {}

void Item::Use(Player& player)
{

}