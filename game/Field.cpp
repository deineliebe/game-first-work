#include "Field.h"

//Constructor of creating field
Field::Field(int height, int width)
{
    _height = height;
    _width = width;
    _matrix = new char* [height];
    for (int i = 0; i < height; i++) _matrix[i] = new char[width];
    //Making a border of field (at first, only on the first and last lines
    for (int i = 0; i < width; i++)
    {
        _matrix[0][i] = 'X';
        _matrix[height - 1][i] = 'X';
    }
    //Making an array of empty elements with border (first and last elements)
    for (int i = 1; i < height - 1; i++)
    {
        _matrix[i][0] = 'X';
        for (int j = 1; j < width - 1; j++)
        {
            _matrix[i][j] = ' ';
        }
        _matrix[i][width - 1] = 'X';
    }
    //Value of number of units which can be on field
    _maxUnits = (((_height - 2) * (_width - 2)) / 4) + 1;
    _units = 0;
}

Field::Field(const Field& anotherField)
{
    _height = anotherField._height;
    _width = anotherField._width;
    _matrix = new char* [anotherField._height];
    for (int i = 0; i < anotherField._width; i++) _matrix[i] = new char[anotherField._width];
    for (int i = 0; i < anotherField._width; i++)
    {
        _matrix[0][i] = 'X';
        _matrix[anotherField._height - 1][i] = 'X';
    }
    for (int i = 1; i < anotherField._height - 1; i++)
    {
        _matrix[i][0] = 'X';
        for (int j = 1; j < anotherField._width - 1; j++)
        {
            _matrix[i][j] = anotherField._matrix[i][j];
        }
        _matrix[i][anotherField._width - 1] = 'X';
    }
    _maxUnits = anotherField._maxUnits;
    _units = anotherField._units;
}

const Field& Field::operator=(const Field&& anotherField)
{
    if (&anotherField == this) return *this;
    _height = anotherField._height;
    _width = anotherField._width;
    _matrix = new char* [anotherField._height];
    for (int i = 0; i < anotherField._width; i++) _matrix[i] = new char[anotherField._width];
    for (int i = 0; i < anotherField._width; i++)
    {
        _matrix[0][i] = 'X';
        _matrix[anotherField._height - 1][i] = 'X';
    }
    for (int i = 1; i < anotherField._height - 1; i++)
    {
        _matrix[i][0] = 'X';
        for (int j = 1; j < anotherField._width - 1; j++)
        {
            _matrix[i][j] = anotherField._matrix[i][j];
        }
        _matrix[i][anotherField._width - 1] = 'X';
    }
    _maxUnits = anotherField._maxUnits;
    _units = anotherField._units;
    return *this;
}

void Field::showField()
{
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            std::cout << _matrix[i][j];
        }
        std::cout << '\n';
    }
}

void Field::showEmptyPoints()
{
    std::cout << "Empty spaces:\n";
    for (int i = 1; i < _width - 1; i++)
    {
        std::cout << i << ": ";
        for (int j = 1; j < _height - 1; j++)
        {
            if (_matrix[j][i] == ' ') std::cout << j << ' ';
        }
        std::cout << '\n';
    }
}

bool Field::ifElement(int x, int y)
{
    if (_matrix[y][x] == ' ')
    {
        return 1;
    }
    return 0;
}

void Field::addElement(int x, int y, char symbol)
{
    if (ifElement(x, y))
    {
        _units++;
        _matrix[y][x] = symbol;
    }
}

void Field::removeElement(int x, int y)
{
    _units--;
    _matrix[y][x] = ' ';
}

void Field::replaceElement(int x, int y, int newX, int newY, char symbol)
{
    removeElement(x, y);
    addElement(newX, newY, symbol);
}

int Field::changePosition(int x, int y, char symbol)
{
    int number;
    std::cout << "Choose a number:\n";
    if (ifElement(x, y - 1)) std::cout << "1. Up\n";
    if (ifElement(x + 1, y)) std::cout << "2. Right\n";
    if (ifElement(x, y + 1)) std::cout << "3. Down\n";
    if (ifElement(x - 1, y)) std::cout << "4. Left\n";
    std::cin >> number;
    if (!std::cin) return 0;
    if (number == 1)
    {
        if (ifElement(x, y - 1))  
        {
            replaceElement(x, y, x, y - 1, symbol);
            return number;
        }
    }
    else if (number == 2)
    {
        if (ifElement(x + 1, y))
        {
            replaceElement(x, y, x + 1, y, symbol);
            return number;
        }
    }
    else if (number == 3)
    {
        if (ifElement(x, y + 1))
        {
            replaceElement(x, y, x, y + 1, symbol);
            return number;
        }
    }
    else if (number == 4)
    {
        if (ifElement(x, y + 1))
        {
            replaceElement(x, y, x - 1, y, symbol);
            return number;
        }
    }
    return 0;
}

int Field::getUnitsNumber()
{
    return _units;
}

int Field::getMaxUnitsNumber()
{
    return _maxUnits;
}

void Field::showUnitsStatistic()
{
    std::cout << "Number of units: " << _units << '/' << _maxUnits << '\n';
}

//Destructor
Field::~Field()
{
    _height = 0;
    _width = 0;
    _matrix = NULL;
}