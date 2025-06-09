#pragma once
#include "Player.h"
#include "Town.h"
#include "Forest.h"

// Функции меню
void showMainMenu();
void handleWorldExploration(Town& nilfgaard, Town& novigrad, Town& moscow, Forest& darkForest);
void handleCityChoice(Town& nilfgaard, Town& novigrad, Town& moscow);
void handleAdventures(Forest& darkForest);
void handleStatsAndInventory(Player& player);

// Утилиты
void clearConsole();
void printCentered(const std::string& text);