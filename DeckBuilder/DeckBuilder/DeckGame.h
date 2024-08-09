#pragma once
#include "Card.h"
#include <vector>
class DeckGame
{
public:
	DeckGame();
	void startGame();
	void displayGameNewTurn();
	void displayGame();
	bool isGameRunning();
	void setGameRunning(bool t);
	bool placeCard(int c, int p);
	void enemyPlay();
	void placeCardEnemy(int c, int p);
	void playerAttack();
	void enemyAttack();
private:
	bool gameRunning = true;
	const int boardSize = 3;
	const int numOfPresets = 3;
	int playerHealth;
	int enemyHealth;
	std::vector<Card> deck1;
	std::vector<Card> deck2;
	Card* playerSide[3] = { NULL, NULL, NULL };
	Card* enemySide[3]  = { NULL, NULL, NULL };
	Card* getPresetCard();
	Card* getPresetCard(int);
};

