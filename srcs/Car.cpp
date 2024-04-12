#include "Car.hpp"
#include <iostream>

int Car::carCount = 0;

Car::Car()
{
	std::cout << "Car created" << std::endl;
	carCount++;
	_speed = 0;
}

Car::Car(int speed)
{
	std::cout << "Car created" << std::endl;
	carCount++;
	_speed = speed;
}

Car::~Car()
{
	std::cout << "Car destroyed" << std::endl;
}

void Car::boom(void)
{
	std::cout << "Car BOOM!" << std::endl;
}

int Car::getSpeed(void)
{
	return _speed;
}

void Car::setSpeed(int speed)
{
	this->_speed = speed;
}