#include <iostream>
#include <stdio.h>
#include <vector>
#include "Field.h"
#include "Unit.h"

int addElement(Field &gameField, std::vector<Unit*> &units, int width, int height, int& lengthOfUnits)
{
	int x, y, number;
	if (!(gameField.getMaxUnitsNumber() - gameField.getUnitsNumber()))
	{
		std::cout << "Too many units! On field there's can be only " << gameField.getMaxUnitsNumber() << '\n';
		return 1;
	}
	//Function to give user a possibility to see places which are free to adding element
	gameField.showEmptyPoints();
	std::cout << "x: ";
	std::cin >> x;
	if (!std::cin)
	{
		std::cout << "Wrong x. You must write a number";
		//Function return 0 if there's an exception needed
		return 0;
	}
	std::cout << "y: ";
	std::cin >> y;
	if (!std::cin) 
	{
		std::cout << "Wrong y. You must write a number";
		return 0;
	}
	if ((x < 0) or (x > width - 1))
	{
		std::cout << "Wrong x: it must be between 0 and " << width - 1 << '\n';
		//Function return 1 if programm don't make what it need (there's an error), but it can't crush programm
		return 1;
	}
	else if ((y < 0) or (y > height - 1))
	{
		std::cout << "Wrong y: it must be between 0 and " << height - 1 << '\n';
		return 1;
	}
	else if (gameField.ifElement(x, y) == 0)
	{
		std::cout << "You must choose another point: this was taken by an object\n";
		return 1;
	}
	else
	{
		std::cout << "Write class of unit:\n";
		std::cout << "1. Mage\n";
		std::cout << "2. Illusionist\n";
		std::cout << "3. Cleric\n";
		std::cout << "4. Druid\n";
		std::cout << "5. Fighter\n";
		std::cout << "6. Ranger\n";
		std::cin >> number;
		if (!std::cin)
		{
			std::cout << "Wrong class. You must write a number";
			return 0;
		}
		if ((number > 0) and (number < 7))
		{
			//Adding element to vector of units
			units.push_back(Unit::createUnit(number, x, y));
			lengthOfUnits++;
			//Adding a symbol of element in matrix of field
			gameField.addElement(x, y, units[lengthOfUnits - 1]->getSymbol());
			gameField.showUnitsStatistic();
			//Function return 2 if programm correctly made an operation
			return 2;
		}
		else std::cout << "Wrong number. It must be between 1 and 6\n";
		return 1;
	}
}

int deleteElement(Field &gameField, std::vector<Unit*> &units, int& lengthOfUnits)
{
	int number, x, y;
	std::cout << "Write number of unit:\n";
	//Output an information of all units
	for (int i = 0; i < lengthOfUnits; i++)
	{
		std::cout << i + 1;
		units[i]->getInformation();
	}
	std::cin >> number;
	if (!std::cin)
	{
		std::cout << "Wrong unit. You must write a number";
		return 0;
	}
	if ((number > 0) and (number <= lengthOfUnits))
	{
		//Here we got coordinates on which there is unit now
		x = units[number - 1]->getX();
		y = units[number - 1]->getY();
		//Then we make this element of field empty
		gameField.removeElement(x, y);
		//And delete unit
		units.erase(units.begin() + number - 1);
		lengthOfUnits--;
		gameField.showUnitsStatistic();
		return 2;
	}
	else
	{
		std::cout << "Wrong number. It must be between 1 and " << lengthOfUnits << '\n';
		return 1;
	}
}

int replaceUnit(Field &gameField, std::vector<Unit*> &units, int& lengthOfUnits)
{
	int number, x, y;
	std::cout << "Write number of unit:\n";
	for (int i = 0; i < lengthOfUnits; i++)
	{
		std::cout << i + 1;
		units[i]->getInformation();
	}
	std::cin >> number;
	if (!std::cin)
	{
		std::cout << "Wrong unit. You must write a number";
		return 0;
	}
	if ((number > 0) and (number <= lengthOfUnits))
	{
		x = units[number - 1]->getX();
		y = units[number - 1]->getY();
		units[number - 1]->moveUnit(gameField.changePosition(x, y, units[number - 1]->getSymbol()));
	}
	else std::cout << "Wrong number. It must be between 1 and " << lengthOfUnits << '\n';
}

int main()
{
	try
	{
		//Variable for choosing one of main options
		int choice = -1;
		std::vector<Unit*> units;
		//Variables for choosing size of field
		int width, height;
		//Variables to count number of units;
		int lengthOfUnits = 0;
		std::cout << "Enter height of field: ";
		std::cin >> height;
		if (!std::cin) throw "Wrong height. It must be integer";
		if (height < 3) throw "Wrong height. It must be a number more than 3";
		std::cout << "Enter width of field: ";
		std::cin >> width;
		if (!std::cin) throw "Wrong width. It must be integer";
		if (width < 3) throw "Wrong height. It must be a number more than 3";
		Field gameField(height, width);
		gameField.showField();
		while (choice)
		{
			std::cout << '\n';
			std::cout << "Write a number:\n";
			std::cout << "1. Add element\n";
			std::cout << "2. Delete element\n";
			std::cout << "3. Move unit\n";
			std::cout << "0. Exit\n";
			std::cin >> choice;
			if (!std::cin) throw "Wrong answer. You must write a number";
			switch (choice)
			{
			case 1:
			{
				if (!addElement(gameField, units, width, height, lengthOfUnits)) throw "Error";
				break;
			}
			case 2:
			{
				if (!deleteElement(gameField, units, lengthOfUnits)) throw "Error";
				break;
			}
			case 3:
			{
				if (!replaceUnit(gameField, units, lengthOfUnits)) throw "Error";
				break;
			}
			default:
			{
				if (choice) std::cout << "Wrong number\n";
				break;
			}
			}
			std::cout << '\n';
			gameField.showField();
		}
	}
	catch(const char* ex)
	{
		std::cout << ex;
	}
}