#ifndef CAR_HPP
# define CAR_HPP

class Car
{
public:
	Car();
	Car(int speed);
	virtual ~Car();

	virtual void boom(void);

	int getSpeed(void);
	void setSpeed(int speed);

	static int carCount;

private:
	int _speed;
};

#endif