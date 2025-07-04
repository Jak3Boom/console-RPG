#include "Inventory.h"
#include "Item.h"

void Inventory::TakeItem(Item item)
{
	bag.push_back(item);
}

void Inventory::OpenInventory()
{
	if (bag.empty())
	{
		std::cout << "Пусто!" << std::endl;
	}
	else
	{
		std::cout << "\nИнвентарь:" << std::endl;
		for (int i = 0; i < bag.size(); ++i)
		{
			std::cout << "-----------------------------------------------------------------" << std::endl;
			std::cout << (i + 1) << ". " << bag[i].getName() << "(тип: " << bag[i].getType() << "; значение: " << bag[i].getValue() << ")\n";
		}
		std::cout << "-----------------------------------------------------------------\n" << std::endl;

		std::cout << std::endl;
	}
}