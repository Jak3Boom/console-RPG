#include <windows.h>

#include "GameLogic.h"
#include "Forest.h"

void showMainMenu()
{
	std::cout << "=== ГЛАВНОЕ МЕНЮ ===" << std::endl;
	std::cout << "1. Исследовать мир" << std::endl;
	std::cout << "2. Мой персонаж (характеристики, инвентарь)" << std::endl;
	std::cout << "3. Выйти из игры" << std::endl;
}

void handleWorldExploration(Town& nilfgaard, Town& novigrad, Town& moscow, Forest& darkForest)
{
	std::cout << "Куда отправимся?\n1. Город\n2. На поиски приключений\n";
	char choice;
	std::cin >> choice;

	if (choice == 1)
	{
		handleCityChoice(nilfgaard, novigrad, moscow);
	}
	else if (choice == 2)
	{
		handleAdventures(darkForest);
	}
	else
	{
		std::cout << "Такого варианта нет!" << std::endl;
	}
}

void handleCityChoice(Town& nilfgaard, Town& novigrad, Town& moscow)
{
	std::cout << "Какой город хочешь посетить?\n1. Нильфгаард\n2. Новиград\n3. Москва\n";
	char choice;
	std::cin >> choice;

	if (choice == 1)
	{
		std::cout << "Отправляемся в Нильфгаард!" << std::endl;
		Sleep(2000);
		std::cout << "..." << std::endl;
		Sleep(2000);
		nilfgaard.Enter();
	}
	else if (choice == 2)
	{
		std::cout << "Отправляемся в Новиград!" << std::endl;
		Sleep(2000);
		std::cout << "..." << std::endl;
		Sleep(2000);
		novigrad.Enter();
	}
	else if (choice == 3)
	{
		std::cout << "Отправляемся в Москву!" << std::endl;
		Sleep(2000);
		std::cout << "..." << std::endl;
		Sleep(2000);
		moscow.Enter();
	}
	else
	{
		std::cout << "Такого варианта нет!" << std::endl;
	}
}

void handleAdventures(Forest& darkForest)
{
	std::cout << "Отправляемся в Тёмный лес!" << std::endl;
	Sleep(2000);
	std::cout << "..." << std::endl;
	Sleep(2000);
	darkForest.Enter();
}

void handleStatsAndInventory(Player& player)
{
	std::cout << "Выбирай:\n1. Характеристики героя\n2. Инвентарь\n";
	char choice;
	std::cin >> choice;

	if (choice == 1)
	{
		Sleep(500);
		player.ShowStats();
	}
	else if (choice == 2)
	{
		Sleep(500);
		player.ShowInventory();
	}
	else
	{
		std::cout << "Такого варианта нет!" << std::endl;
	}
}

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

void printCentered(const std::string& text)
{
	int consoleWidth = 150;
	int textLength = text.length();
	int padding = (consoleWidth - textLength) / 2;

	std::cout << std::string(padding, ' ') << text << std::endl;
}