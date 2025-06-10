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
	std::cout << "Куда отправимся?\n1. Город\n2. На поиски приключений\n";
	char choice;
	std::cin >> choice;

	if (choice == '1')
	{
		handleTownChoice(player, nilfgaard, novigrad, moscow);
	}
	else if (choice == '2')
	{
		handleAdventures(darkForest);
	}
	else
	{
		std::cout << "Такого варианта нет!" << std::endl;
	}
}

// Обработчик выбора города
void handleTownChoice(Player& player, Town& nilfgaard, Town& novigrad, Town& moscow)
{
	std::cout << "Какой город хочешь посетить?\n1. Нильфгаард\n2. Новиград\n3. Москва\n";
	char choice;
	std::cin >> choice;

	bool inTheTown = true;

	if (choice == '1')
	{
		std::cout << "Отправляемся в Нильфгаард!" << std::endl;
		//Sleep(2000);
		std::cout << "..." << std::endl;
		//Sleep(2000);
		nilfgaard.Enter();

		while (inTheTown)
		{
			char actionChoice = nilfgaard.Action(); // Выбор действия (1. Магазин/торговец; 2. Карта)
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

		break;
	default:
		break;
	}
}

// Обработчик действий магазина
void handleShop(char choice, Player& player, Town& town)
{
	switch (choice)
	{
	case '1': // Показать товары
		std::cout << "Пожалуйста, выбирайте!" << std::endl;
		town.getShop().ShowGoods();
		break;
	case '2': // Выход

		break;
	default:
		break;
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