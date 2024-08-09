#include "Card.h"
using namespace std;

Card::Card()
{
	name = "NULL";
	attackDamage = 1;
	health = 1;
	type = 0;
	eepy = true;
}
Card::Card(int d, int h, string n, int t)
{
	name = n;
	attackDamage = d;
	health = h;
	type = t;
	eepy = true;
}

void Card::setDamage(int d)
{
	attackDamage = d;
}
void Card::setHealth(int h)
{
	health = h;
}
void Card::setName(string n)
{
	name = n;
}
void Card::setType(int t)
{
	type = t;
}
void Card::setEepy(bool e)
{
	eepy = e;
}

int Card::getDamage()
{
	return attackDamage;
}
int Card::getHealth()
{
	return health;
}
string Card::getName()
{
	return name;
}
int Card::getType()
{
	return type;
}
bool Card::isEepy()
{
	return eepy;
}

/// <summary>
/// Take damage, and return true if card alive, false if not
/// </summary>
/// <param name="d">= Damage</param>
/// <returns>isAlive</returns>
bool Card::takeDamage(int d)
{
	health = health - d;
	if (health <= 0)
	{
		return false;
	}
	return true;
}