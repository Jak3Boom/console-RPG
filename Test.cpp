#include <iostream>
#include <windows.h>

#include "Player.h"
#include "Enemy.h"
#include "Town.h"
#include "Forest.h"
#include "GameLogic.h"

int main()
{
	// Предметы для городов
#pragma region Items
	std::vector<Item> nilfgaardItems = {
		Item("Меч из драконьего камня", "Оружие", 5, 500),
		Item("Ягоды", "Еда", 1, 100),
		Item("Кинжал из замка", "Оружие", 3, 300)
	};
	std::vector<Item> novigradItems = {
		Item("Походный нож", "Оружие", 2, 400),
		Item("Зелье здоровья", "Используемое", 5, 600),
		Item("Топор", "Оружие", 5, 700)
	};
	std::vector<Item> moscowItems = {
		Item("Меч из драконьего камня", "Оружие", 5, 500),
		Item("Ягоды", "Еда", 1, 100),
		Item("Кинжал из замка", "Оружие", 3, 300)
	};
#pragma endregion


	// Города (Nilfgaard, Novigrad, Moscow)
#pragma region Locations
	Town nilfgaard("Нильфгаард", "Город Золотых Башен", "Магазин Нильфгаарда", nilfgaardItems);
	Town novigrad("Новиград", "Город-государство, 'Столица мира Новиград'", "Магазин Новиграда", novigradItems);
	Town moscow("Москва", "Княжий град среди лесов", "Магазин Москвы", moscowItems);
	Forest darkForest("Мёртвый лес", "Злобная пучина местных земель...");
#pragma endregion

	std::string introduction = "Welcome to my first game!";
	std::string descriptionIntroduction = "The project is the property of Jak3Boom and was created as part of my C++ training.";

	// Приветствие и описание
	printCentered(introduction);
	std::cout << std::endl;
	//Sleep(2000);
	printCentered(descriptionIntroduction);
	//Sleep(3000);

#pragma region padding
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
#pragma endregion

	// Создание никнейма
	std::string playerNickname;

	std::cout << "Введите имя героя: ";
	std::cin >> playerNickname;

	clearConsole();

	// Создание игрока
	Player player(playerNickname);
	
	std::cout << "Герой успешно создан:" << std::endl;
	std::cout << "_______________________________________\n" << std::endl;
	player.ShowStats();
	std::cout << "_______________________________________" << std::endl;

#pragma region padding
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
#pragma endregion

	std::cout << "Приятной игры!" << std::endl;
	//Sleep(3000);
	clearConsole();

	// Начало игры
	bool gameRunning = true;
	while (gameRunning)
	{
		showMainMenu(); // Отображение главного меню: 1. Исследовать мир; 2. Открыть меню взаимодействия с персонажем; 3. Выйти из игры

		char playerChoice;
		std::cin >> playerChoice; // Получаем выбор игрока
		clearConsole();

		switch (playerChoice)
		{
		case '1': // Исследование мира (город, лес)
			handleWorldExploration(player, nilfgaard, novigrad, moscow, darkForest);
			break;
		case '2': // Информация о персонаже/инвентарь
			handleStatsAndInventory(player);
			break;
		case '3': //Выход из игры
			std::cout << "Спасибо за игру! Хорошего дня!" << std::endl;
			gameRunning = false;
			break;
		default:
			std::cout << "Такого варианта нет!" << std::endl;
			Sleep(1000);
			clearConsole();
			break;
		}
	}

	return 0;
}