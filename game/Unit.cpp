#include "Unit.h"

Mage::Mage(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(5);
	_armor.setArmor(7);
	_attack.setAttack(8);
	_symbol = 'M';
}

Illusionist::Illusionist(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(6);
	_armor.setArmor(6);
	_attack.setAttack(8);
	_symbol = 'I';
}

Cleric::Cleric(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(8);
	_armor.setArmor(7);
	_attack.setAttack(5);
	_symbol = 'C';
}

Druid::Druid(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(6);
	_armor.setArmor(7);
	_attack.setAttack(7);
	_symbol = 'D';
}

Fighter::Fighter(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(8);
	_armor.setArmor(2);
	_attack.setAttack(10);
	_symbol = 'F';
}

Ranger::Ranger(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(6);
	_armor.setArmor(5);
	_attack.setAttack(7);
	_symbol = 'R';
}

//Fabric function
Unit* Unit::createUnit(int id, int x, int y)
{
	Unit* newUnit = NULL;
	switch (id)
	{
	case Mage_ID:
		newUnit = new Mage(x, y);
		break;
	case Illusionist_ID:
		newUnit = new Illusionist(x, y);
		break;
	case Cleric_ID:
		newUnit = new Cleric(x, y);
		break;
	case Druid_ID:
		newUnit = new Druid(x, y);
		break;
	case Fighter_ID:
		newUnit = new Fighter(x, y);
		break;
	case Ranger_ID:
		newUnit = new Ranger(x, y);
		break;
	}
	return newUnit;
}

int Unit::getSymbol()
{
	return _symbol;
}

void Unit::getInformation()
{
	std::cout << ". Class: ";
	switch (_symbol)
	{
	case 'M':
		std::cout << "Mage";
		break;
	case 'I':
		std::cout << "Illusionist";
		break;
	case 'C':
		std::cout << "Cleric";
		break;
	case 'D':
		std::cout << "Druid";
		break;
	case 'F':
		std::cout << "Fighter";
		break;
	case 'R':
		std::cout << "Ranger";
		break;
	}
	std::cout << ". Coordinates: (" << getX() << ", " << getY() << "). ";
	std::cout << "Health: " << _health.getHealth() << ". Armor: " << _armor.getArmor() << ". Atack: " << _attack.getAttack() << '\n';
}

int Unit::getX()
{
	return _point.getX();
}

int Unit::getY()
{
	return _point.getY();
}

void Unit::changeCoordinates(int x, int y)
{
	_point.setPoint(x, y);
}

void Unit::moveUnit(int number)
{
	if (number == 1) changeCoordinates(getX(), getY() - 1);
	else if (number == 2) changeCoordinates(getX() + 1, getY());
	else if (number == 3) changeCoordinates(getX(), getY() + 1);
	else if (number == 4) changeCoordinates(getX() - 1, getY());
}