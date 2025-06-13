#pragma once
#include "Player.h"
#include "Town.h"
#include "Forest.h"

// Функции меню
void showMainMenu();
void handleWorldExploration(Player& player, Town& nilfgaard, Town& novigrad, Town& moscow, Forest& darkForest);
void handleTownChoice(Player& player, Town& nilfgaard, Town& novigrad, Town& moscow);
void handleTownAction(char choice, Player& player, Town& town, bool& isInTheTown);
void showMap(const std::string& currenLocation);
void handleShop(char choice, Player& player, Town& town);
void handlePurchase(Player& player, Town& town);
void handleAdventures(Player& player, Forest& darkForest);
void handleAdventureAction(char choice, Player& player, Forest& darkForest, bool& isInTheLocation);
void handleStatsAndInventory(Player& player);

// Утилиты
void clearConsole();
void printCentered(const std::string& text);