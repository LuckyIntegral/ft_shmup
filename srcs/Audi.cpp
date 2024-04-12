
#include "Audi.hpp"
#include <iostream>

Audi::Audi(int speed) : Car(speed)
{
	std::cout << "Audi created" << std::endl;
}

Audi::~Audi()
{
	std::cout << "Audi destroyed" << std::endl;
}

void Audi::boom(void)
{
	std::cout << "Audi BOOM!" << std::endl;
}

void Audi::pitStop(void)
{
	std::cout << "Audi pit stop" << std::endl;
}
