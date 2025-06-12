#include <windows.h>

#include "Player.h"
#include "GameLogic.h"
#include "Forest.h"

// Отображение главного меню
void showMainMenu()
{
	std::cout << "=== ГЛАВНОЕ МЕНЮ ===" << std::endl;
	std::cout << "1. Исследовать мир" << std::endl;
	std::cout << "2. Мой персонаж (характеристики, инвентарь)" << std::endl;
	std::cout << "3. Выйти из игры" << std::endl;
}

// Обработчик места назначения
void handleWorldExploration(Player& player, Town& nilfgaard, Town& novigrad, Town& moscow, Forest& darkForest)
{
	bool exploring = true;

	while (exploring)
	{
		std::cout << "Куда отправимся?\n1. Город\n2. На поиски приключений\n3. Выход в главное меню\n";

		char worldChoice;
		std::cin >> worldChoice;
		clearConsole();

		switch (worldChoice)
		{
		case '1':
			handleTownChoice(player, nilfgaard, novigrad, moscow);
			break;
		case '2':
			handleAdventures(darkForest);
			break;
		case '3':
			exploring = false;
			break;
		default:
			std::cout << "Такого варианта нет!" << std::endl;
			Sleep(1000);
			clearConsole();
			break;
		}
	}
}

// Обработчик выбора города
void handleTownChoice(Player& player, Town& nilfgaard, Town& novigrad, Town& moscow)
{
	std::cout << "Какой город хочешь посетить?\n1. Нильфгаард\n2. Новиград\n3. Москва\n";
	char choice;
	std::cin >> choice;
	clearConsole();

	bool inTheTown = true;

	if (choice == '1')
	{
		std::cout << "Отправляемся в Нильфгаард!" << std::endl;
		//Sleep(2000);
		std::cout << "\n...\n" << std::endl;
		//Sleep(2000);
		nilfgaard.Enter();
		//Sleep(2000);

		while (inTheTown)
		{
			char actionChoice = nilfgaard.Action(); // Выбор действия (1. Магазин/торговец; 2. Карта)
			clearConsole();
			handleTownAction(actionChoice, player, nilfgaard, inTheTown);
		}
	}
	else if (choice == '2')
	{
		std::cout << "Отправляемся в Новиград!" << std::endl;
		//Sleep(2000);
		std::cout << "..." << std::endl;
		//Sleep(2000);
		novigrad.Enter();

		while (inTheTown)
		{
			char actionChoice = novigrad.Action();
		}
	}
	else if (choice == '3')
	{
		std::cout << "Отправляемся в Москву!" << std::endl;
		//Sleep(2000);
		std::cout << "..." << std::endl;
		//Sleep(2000);
		moscow.Enter();

		while (inTheTown)
		{
			char actionChoice = moscow.Action();
		}
	}
	else
	{
		std::cout << "Такого варианта нет!" << std::endl;
	}
}

// Обработчик выбора действия в городе
void handleTownAction(char choice, Player& player, Town& town, bool& isInTheTown)
{
	switch (choice)
	{
	case '1': // Магазин/торговец
		std::cout << "Вы отправляетесь к торговцу...\n" << std::endl;
		//Sleep(1000);

		std::cout << "Торговец: Добро пожаловать! Хотите что-то прикупить?\n" << std::endl;
		std::cout << "1. Покажи товары\n2. До свидания!\n" << std::endl;

		char shopChoice;
		std::cin >> shopChoice;

		handleShop(shopChoice, player, town);
		break;
	case '2': // Карта
		showMap(town.getName());
		break;
	case '3': // Выход из города
		std::cout << "Вы покидаете " << town.getName() << "! Счастливого пути!" << std::endl;
		isInTheTown = false;
		break;
	default:
		break;
	}
}

void showMap(const std::string& currentLocation)
{
	std::cout << "=== КАРТА МИРА ===\n";
	std::cout << "Города:\n";
	std::cout << " - Нильфгаард" << (currentLocation == "Нильфгаард" ? " (вы здесь)" : "") << "\n";
	std::cout << " - Новиград" << (currentLocation == "Новиград" ? " (вы здесь)" : "") << "\n";
	std::cout << " - Москва" << (currentLocation == "Москва" ? " (вы здесь)" : "") << "\n";
	std::cout << "Локации для приключений:\n";
	std::cout << " - Тёмный лес" << (currentLocation == "Тёмный лес" ? " (Вы здесь)" : "") << "\n";
	std::cout << "==================\n";
	std::cout << "Нажмите Enter, чтобы вернуться...\n";
	std::cin.ignore();
	std::cin.get();
	clearConsole();
}

// Обработчик действий магазина
void handleShop(char choice, Player& player, Town& town)
{
	switch (choice)
	{
	case '1': // Показать товары
		clearConsole();
		std::cout << "Торговец: Пожалуйста, выбирайте!" << std::endl;
		town.getShop().ShowGoods();
		handlePurchase(player, town);

		/*int shopChoice;
		while (!(std::cin >> shopChoice))
		{
			clearConsole();
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Торговец: Пожалуйста, выбирайте!" << std::endl;
			town.getShop().ShowGoods();
			std::cout << "Ошибка! Введите число." << std::endl;
		}*/
		break;
	case '2': // Выход
		std::cout << "Всего хорошего! Заходите ещё!" << std::endl;
		//Sleep(1000);
		clearConsole();
		break;
	default:
		break;
	}
}

// Обработчик покупки предмета
void handlePurchase(Player& player, Town& town)
{
	int availableItems = town.getShop().getGoods().size(); // Получаем количество доступных предметов в текущем магазине

	bool isInTheShop = true;
	while (isInTheShop) // Цикл работает, пока не вышли из магазина
	{
		int choice;
		while (!(std::cin >> choice)) // Проверка на int
		{
			clearConsole();
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Торговец: Пожалуйста, выбирайте!" << std::endl;
			town.getShop().ShowGoods();
			std::cout << "Ошибка! Введите число." << std::endl;
		}

		if (choice == availableItems + 1)
		{
			std::cout << "Всего хорошего! Заходите ещё!" << std::endl;
			//Sleep(1000);
			clearConsole();
			isInTheShop = false;
		}

		int itemIndex = choice - 1; // Получаем индекс предмета
		if (itemIndex >= 0 && itemIndex < availableItems)
		{
			Item selectedItem = town.getShop().getGoods()[itemIndex]; // Получаем выбранный предмет

			// Покупка товара
			if (player.getGold() >= selectedItem.getPrice())
			{
				player.buyItem(selectedItem);
				std::cout << "---------------------------------------------------------------\n";
				std::cout << "Вы купили: " << selectedItem.getName() << ". Цена - " << selectedItem.getPrice() << " золота\n";
				std::cout << "На счёте: " << player.getGold() << " золота\n";
				std::cout << "---------------------------------------------------------------\n";
			}
			else
			{
				std::cout << "Недостаточно золота!" << std::endl;
			}
		}
		else
		{
			std::cout << "Неверный выбор! Доступно товаров: 1-" << availableItems << std::endl;
		}
	}
}

// Обработчик выбора приключений
void handleAdventures(Forest& darkForest)
{
	std::cout << "Отправляемся в Тёмный лес!" << std::endl;
	//Sleep(2000);
	std::cout << "..." << std::endl;
	//Sleep(2000);
	darkForest.Enter();

	bool inTheLocation = true;
	while (inTheLocation)
	{
		char actionChoice = darkForest.Action();
	}
}

// Обработчик меню взаимодействия (характеристики, инвентарь)
void handleStatsAndInventory(Player& player)
{
	std::cout << "Выбирай:\n1. Характеристики героя\n2. Инвентарь\n";
	char choice;
	std::cin >> choice;

	if (choice == '1')
	{
		//Sleep(500);
		player.ShowStats();
	}
	else if (choice == '2')
	{
		//Sleep(500);
		player.ShowInventory();
	}
	else
	{
		std::cout << "Такого варианта нет!" << std::endl;
	}
}

// Очистка консоли
void clearConsole()
{
#if defined(_WIN32) || defined(_WIN64)
	// Способ 1 (если system("cls") работает плохо)
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
	SetConsoleCursorPosition(hStdOut, coord);
#else
	// Способ 2 (ANSI-коды для Linux/macOS)
	std::cout << "\033[2J\033[1;1H";
#endif
}

// Отобразить текст по центру
void printCentered(const std::string& text)
{
	int consoleWidth = 150;
	int textLength = text.length();
	int padding = (consoleWidth - textLength) / 2;

	std::cout << std::string(padding, ' ') << text << std::endl;
}