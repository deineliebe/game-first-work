#include "UnitAtributes.h"

//Functions for health
void Health::setHealth(int number)
{
	_health = number;
}

int Health::getHealth()
{
	return _health;
}

void Health::reduceHealth(int number)
{
	_health -= number;
}

void Health::increaseHealth(int number)
{
	_health += number;
}

//Functions for armor
void Armor::setArmor(int number)
{
	_armor = number;
}

int Armor::getArmor()
{
	return _armor;
}

void Armor::reduceArmor(int number)
{
	_armor -= number;
}

void Armor::increaseArmor(int number)
{
	_armor += number;
}

//Functions for attack
void Attack::setAttack(int number)
{
	_attack = number;
}

int Attack::getAttack()
{
	return _attack;
}

void Attack::reduceAttack(int number)
{
	_attack -= number;
}

void Attack::increaseAttack(int number)
{
	_attack += number;
}

//Functions for point
int Point::getX()
{
	return _x;
}

int Point::getY()
{
	return _y;
}

void Point::setPoint(int x, int y)
{
	_x = x;
	_y = y;
}