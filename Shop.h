#pragma once
#include <vector>

#include "Item.h"

class Shop
{
public:
	Shop(const std::string& name, const std::vector<Item>& items);
	std::vector<Item> getGoods() const;
	void ShowGoods() const;

private:
	std::string shopName;
	std::vector<Item> goods;
};