//=================================
//
//=================================

#include <iostream>
#include <vector>
#include "DeckGame.h"
#include <string>

using namespace std;

int main()
{
	srand(time(NULL));
	DeckGame game;
	string input;
	game.displayGame();
	while (game.isGameRunning())
	{
		system("CLS");
		game.displayGame();
		cout << "What would you like to do? 1 - Use Card, 2 - End Turn" << endl << "> ";
		getline(cin, input);
		if (input == "1")
		{
			cout << "Which card?" << endl << "> ";
			getline(cin, input);
			int card = stoi(input);
			cout << "Where would you like to place it? 0,1,2?" << endl << "> ";
			getline(cin, input);
			if (input == "1" || input == "2" || input == "0")
			{
				int position = stoi(input);
				game.placeCard(card, position);
			}
		}
		else if (input == "2")
		{

			game.enemyPlay();
		}
	}
}

