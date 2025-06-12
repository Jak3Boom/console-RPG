#pragma once
#include "Location.h"
#include "Shop.h"

class Town : public Location
{
public:
	Town(const std::string& name, const std::string& desc, const std::string& shopName, const std::vector<Item>& items);

	void Enter() override;
	char Action() override;

	std::string getName() { return name; }
	Shop& getShop() { return shop; }

private:
	Shop shop;
};