#pragma once
#include <iostream>
#include <vector>

class Item;

class Inventory
{
public:
	void TakeItem(Item item);
	void OpenInventory();

private:
	std::vector<Item> bag;
};