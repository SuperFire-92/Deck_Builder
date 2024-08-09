#pragma once
#include <iostream>
class Card
{
public:
	Card();
	Card(int d, int h, std::string n, int t);
	void setDamage(int d);
	void setHealth(int h);
	void setName(std::string n);
	void setType(int t);
	void setEepy(bool e);
	int getDamage();
	int getHealth();
	std::string getName();
	int getType();
	bool isEepy();

	bool takeDamage(int d);
private:
	int health;
	int attackDamage;
	std::string name;
	//Types: 0 - Basic
	int type;
	//whether the card will do anything this turn or not.
	bool eepy;
};

