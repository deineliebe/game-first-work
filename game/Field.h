#include <iostream>
#include <stdio.h>

class Field
{
private:
    int _height;
    int _width;
    char** _matrix;
    //Variables to control number of units: it shows number of them which user can to add
    int _units;
    int _maxUnits;
public:
    Field(int height, int width);
    Field(const Field& anotherField);
    const Field& operator=(const Field&& anotherField);
    void showField();
    void showEmptyPoints();
    bool ifElement(int x, int y);
    void addElement(int x, int y, char symbol);
    void removeElement(int x, int y);
    void replaceElement(int x, int y, int newX, int newY, char symbol);
    int changePosition(int x, int y, char symbol);
    int getUnitsNumber();
    int getMaxUnitsNumber();
    void showUnitsStatistic();
    ~Field();
};
