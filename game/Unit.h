#include <iostream>
#include <stdio.h>
#include "UnitAtributes.h"

enum Unit_ID
{
	Mage_ID = 1, Illusionist_ID, Cleric_ID, Druid_ID, Fighter_ID, Ranger_ID
};

class Unit
{
protected:
	Point _point;
	Health _health;
	Armor _armor;
	Attack _attack;
	char _symbol;
public:
	virtual ~Unit() {}
	static Unit* createUnit(int id, int x, int y);
	virtual int getSymbol();
	virtual void getInformation();
	virtual int getX();
	virtual int getY();
	virtual void changeCoordinates(int x, int y);
	virtual void moveUnit(int number);
};

//Some classes are empty now, but in future there'll be special function for every of them
class Wizard : public Unit
{

};

class Mage : public Wizard
{
public:
	Mage(int x, int y);
};

class Illusionist : public Wizard
{
public:
	Illusionist(int x, int y);
};

class Priest : public Unit
{

};

class Cleric : public Priest
{
public:
	Cleric(int x, int y);
};

class Druid : public Priest
{
public:
	Druid(int x, int y);
};

class Warrior : public Unit
{

};

class Fighter : public Warrior
{
public:
	Fighter(int x, int y);
};

class Ranger : public Warrior
{
public:
	Ranger(int x, int y);
};