#pragma once
#include <vector>

#include "Item.h"

class Shop
{
public:
	Shop(const std::string& name, const std::vector<Item>& items);
	void ShowGoods() const;

private:
	std::string shopName;
	std::vector<Item> goods;
};