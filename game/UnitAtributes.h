#include <iostream>
#include <stdio.h>

class Health
{
private:
	int _health;
public:
	void setHealth(int number);
	int getHealth();
	void reduceHealth(int number);
	void increaseHealth(int number);
};

class Armor
{
private:
	int _armor;
public:
	void setArmor(int number);
	int getArmor();
	void reduceArmor(int number);
	void increaseArmor(int number);
};

class Attack
{
private:
	int _attack;
public:
	void setAttack(int number);
	int getAttack();
	void reduceAttack(int number);
	void increaseAttack(int number);
};

class Point
{
private:
	int _x;
	int _y;
public:
	void setPoint(int x, int y);
	int getX();
	int getY();
};