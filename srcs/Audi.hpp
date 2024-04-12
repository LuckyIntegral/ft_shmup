#ifndef AUDI_HPP
# define AUDI_HPP

# include "Car.hpp"

class Audi : public Car
{
public:
	Audi(int speed);
	~Audi();

	void boom(void);
	void pitStop(void);
};

#endif