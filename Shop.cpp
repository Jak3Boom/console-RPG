#include <iostream>

#include "Shop.h"

// Конструктор класса Shop
Shop::Shop(const std::string& name, const std::vector<Item>& items) : shopName(name), goods(items) {}

std::vector<Item> Shop::getGoods() const
{
	return goods;
}

// Показать товары
void Shop::ShowGoods() const
{
	for (int i = 0; i < goods.size(); ++i)
	{
		std::cout << (i + 1) << ". " << goods[i].getName() << "(Тип: "
									 << goods[i].getType() << ", значение: "
									 << goods[i].getValue() << ") - "
									 << goods[i].getPrice() << " золота" << std::endl;
	}
	std::cout << goods.size() + 1 << ". Выход" << std::endl;
}