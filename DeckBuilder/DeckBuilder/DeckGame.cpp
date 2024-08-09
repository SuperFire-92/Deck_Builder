#include "DeckGame.h"
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

DeckGame::DeckGame()
{
	startGame();
}

void DeckGame::startGame()
{
	int startingAmount = 4;
	playerHealth = 10;
	enemyHealth = 10;
	deck1.clear();
	deck2.clear();
	for (int i = 0; i < startingAmount; i++)
	{
		deck1.push_back(Card());
		deck1.at(deck1.size() - 1) = *getPresetCard();
	}
	for (int i = 0; i < startingAmount; i++)
	{
		deck2.push_back(Card());
		deck2.at(deck2.size() - 1) = *getPresetCard();
	}
}

/// <summary>Returns a random card from the preset cards</summary>
/// <returns>A Card</returns>
Card* DeckGame::getPresetCard()
{
	return getPresetCard(rand() % numOfPresets + 1);
}

/// <summary>Returns the card found in the preset cards at the given position</summary>
/// <param name="card">The position the requested card is in.</param>
/// <returns>A Card</returns>
Card* DeckGame::getPresetCard(int card)
{
	fstream file;
	string line;
	file.open("CardPresets.txt");
	if (file)
	{
		//cout << "yup";
		int i = 0;
		while (getline(file, line))
		{
			if (i == card)
			{
				string name = line.substr(0, line.find(','));
				line = line.substr(line.find(',') + 1, line.length() - 1);
				int damage = stoi(line.substr(0, line.find(',')));
				line = line.substr(line.find(',') + 1, line.length() - 1);
				int health = stoi(line.substr(0, line.find(',')));
				line = line.substr(line.find(',') + 1, line.length() - 1);
				int type = stoi(line);
				Card* card = new Card(damage, health, name, type);
				return card;
			}
			i++;
		}
	}
	else
	{
		//cout << "nope";
	}
	return new Card();
}

void DeckGame::displayGameNewTurn()
{
	system("CLS");
}

void DeckGame::displayGame()
{
	int cardLength = 12;
	cout << setfill('=') << setw((cardLength + 2) * 3 + 2) << "" << endl;
	cout << "Player 2 Health: " << enemyHealth << endl;
	cout << "Player 2 Cards: " << deck2.size() << endl;
	cout << endl;
	cout << setfill('=') << setw((cardLength + 2)) << "" << " " << setfill('=') << setw((cardLength + 2)) << "" << " " << setfill('=') << setw((cardLength + 2)) << "" << setfill(' ') << endl;
	cout << "|" << setw(cardLength) << left << (enemySide[0] == NULL ? "" : enemySide[0]->getName()) << "| ";
	cout << "|" << setw(cardLength) << left << (enemySide[1] == NULL ? "" : enemySide[1]->getName()) << "| ";
	cout << "|" << setw(cardLength) << left << (enemySide[2] == NULL ? "" : enemySide[2]->getName()) << "|" << endl;
	cout << "|" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "|" << endl;
	cout << "|" << setw(cardLength) << left << (enemySide[0] == NULL ? "" : "D: " + to_string(enemySide[0]->getDamage())) << "| ";
	cout << "|" << setw(cardLength) << left << (enemySide[1] == NULL ? "" : "D: " + to_string(enemySide[1]->getDamage())) << "| ";
	cout << "|" << setw(cardLength) << left << (enemySide[2] == NULL ? "" : "D: " + to_string(enemySide[2]->getDamage())) << "|" << endl;
	cout << "|" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "|" << endl;
	cout << "|" << setw(cardLength) << left << (enemySide[0] == NULL ? "" : "H: " + to_string(enemySide[0]->getHealth())) << "| ";
	cout << "|" << setw(cardLength) << left << (enemySide[1] == NULL ? "" : "H: " + to_string(enemySide[1]->getHealth())) << "| ";
	cout << "|" << setw(cardLength) << left << (enemySide[2] == NULL ? "" : "H: " + to_string(enemySide[2]->getHealth())) << "|" << endl;
	cout << "|" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "|" << endl;
	cout << setfill('=') << setw((cardLength + 2)) << "" << " " << setfill('=') << setw((cardLength + 2)) << "" << " " << setfill('=') << setw((cardLength + 2)) << "" << setfill(' ') << endl;
	cout << endl;
	cout << setfill('=') << setw((cardLength + 2)) << "" << " " << setfill('=') << setw((cardLength + 2)) << "" << " " << setfill('=') << setw((cardLength + 2)) << "" << setfill(' ') << endl;
	cout << "|" << setw(cardLength) << left << (playerSide[0] == NULL ? "" : playerSide[0]->getName()) << "| ";
	cout << "|" << setw(cardLength) << left << (playerSide[1] == NULL ? "" : playerSide[1]->getName()) << "| ";
	cout << "|" << setw(cardLength) << left << (playerSide[2] == NULL ? "" : playerSide[2]->getName()) << "|" << endl;
	cout << "|" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "|" << endl;
	cout << "|" << setw(cardLength) << left << (playerSide[0] == NULL ? "" : "D: " + to_string(playerSide[0]->getDamage())) << "| ";
	cout << "|" << setw(cardLength) << left << (playerSide[1] == NULL ? "" : "D: " + to_string(playerSide[1]->getDamage())) << "| ";
	cout << "|" << setw(cardLength) << left << (playerSide[2] == NULL ? "" : "D: " + to_string(playerSide[2]->getDamage())) << "|" << endl;
	cout << "|" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "|" << endl;
	cout << "|" << setw(cardLength) << left << (playerSide[0] == NULL ? "" : "H: " + to_string(playerSide[0]->getHealth())) << "| ";
	cout << "|" << setw(cardLength) << left << (playerSide[1] == NULL ? "" : "H: " + to_string(playerSide[1]->getHealth())) << "| ";
	cout << "|" << setw(cardLength) << left << (playerSide[2] == NULL ? "" : "H: " + to_string(playerSide[2]->getHealth())) << "|" << endl;
	cout << "|" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "| |" << setw(cardLength) << left << "" << "|" << endl;
	cout << setfill('=') << setw((cardLength + 2)) << "" << " " << setfill('=') << setw((cardLength + 2)) << "" << " " << setfill('=') << setw((cardLength + 2)) << "" << setfill(' ') << endl;
	cout << endl;
	cout << "Player 1 Cards:" << endl;
	for (int i = 0; i < deck1.size(); i++)
	{
		cout  << "| " << "#" << setw(2) << i << " " << deck1.at(i).getName() << " D: " << deck1.at(i).getDamage() << " H : " << deck1.at(i).getHealth() << " | ";
		if (i % 4 == 3)
			cout << endl;
	}
	cout << "Player 1 Health: " << playerHealth << endl;
	cout << setfill('=') << setw((cardLength + 2) * 3 + 2) << "" << endl;
}

bool DeckGame::isGameRunning()
{
	return gameRunning;
}
void DeckGame::setGameRunning(bool t)
{
	gameRunning = t;
}

/// <summary>
/// Uses a card and places it at the requested position
/// </summary>
/// <param name="c">Card</param>
/// <param name="p">Position</param>
/// <returns></returns>
bool DeckGame::placeCard(int c, int p)
{
	Card* card = new Card(deck1.at(c).getDamage(), deck1.at(c).getHealth(), deck1.at(c).getName(), deck1.at(c).getType());
	deck1.erase(deck1.begin() + c);
	playerSide[p] = card;
	return true;
}

void DeckGame::enemyPlay()
{
	//We want the enemy to place cards smartly-ish. My current plan is just place cards to counter the player, and place to attack if possible.
	for (int i = 0; i < 3; i++)
	{
		//If the deck is empty, don't play
		if (deck2.size() == 0)
		{
			break;
		}
		//If the spot has a card, don't play on that spot
		if (enemySide[i] != NULL)
		{
			continue;
		}
		//We check for defense
		if (playerSide[i] != NULL)
		{

			//Choose highest defense card
			int highestDefenseIndex = 0;
			for (int j = 0; j < deck2.size(); j++)
			{
				if (deck2.at(j).getHealth() > deck2.at(highestDefenseIndex).getHealth())
				{
					highestDefenseIndex = j;
				}
			}
			//Play the highest defense card
			placeCardEnemy(highestDefenseIndex, i);
		}
		//Then offense
		else if (playerSide[i] == NULL)
		{
			//Choose highest offense card
			int highestOffenseIndex = 0;
			for (int j = 0; j < deck2.size(); j++)
			{
				if (deck2.at(j).getDamage() > deck2.at(highestOffenseIndex).getDamage())
				{
					highestOffenseIndex = j;
				}
			}
			//Play the highest defense card
			placeCardEnemy(highestOffenseIndex, i);
		}
	}
}

void DeckGame::placeCardEnemy(int c, int p)
{
	Card* card = new Card(deck2.at(c).getDamage(), deck2.at(c).getHealth(), deck2.at(c).getName(), deck2.at(c).getType());
	deck2.erase(deck2.begin() + c);
	enemySide[p] = card;
}

void DeckGame::playerAttack()
{
	for (int i = 0; i < boardSize; i++)
	{
		if (playerSide[i] != NULL)
		{
			//If the card was placed this turn, skip the card
			if (playerSide[i]->isEepy())
			{
				playerSide[i]->setEepy(false);
				continue;
			}
			//Attack the enemy card directly across
			if (enemySide[i] != NULL)
			{
				if (!enemySide[i]->takeDamage(playerSide[i]->getDamage()))
				{
					delete enemySide[i];
				}
			}
			//If there is no enemy card, attack the enemy directly
			else
			{
				enemyHealth -= playerSide[i]->getDamage();
			}
		}
		else
		{
			continue;
		}
	}
}