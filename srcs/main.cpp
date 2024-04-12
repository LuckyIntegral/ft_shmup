
#include <iostream>
#include <vector>
#include <map>
#include "Audi.hpp"
#include "Car.hpp"

using namespace std;

// void increment(int &a, bool increment = false)
// {
// 	if (increment)
// 		a++;
// 	else
// 		a--;
// }

int main(void)
{
	// map
	// map<string, int> ages = {
	// 	{"Mike", 40},
	// 	{"Raj", 20}
	// };

	// ages["Vicky"] = 30;
	// ages["Vicky"] = 25;

	// for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	// {
	// 	pair<string, int> age = *it;
	// 	cout << age.first << ": " << age.second << endl;
	// }


	// reference
	// int a = 10;

	// cout << "a: " << a << endl;
	// increment(a, true);
	// cout << "a: " << a << endl;
	// increment(a);
	// cout << "a: " << a << endl;
	// increment(a, true);
	// cout << "a: " << a << endl;

	// heap memory
	// Car *bmw = new Car(10);
	// bmw->boom();
	// delete bmw;

	// stack memory
	// Car bmw(10);
	// bmw.boom();
	// cout << "Speed: " << bmw.getSpeed() << endl;
	// bmw.setSpeed(20);
	// cout << "Speed: " << bmw.getSpeed() << endl;

	// cout << "Car count: " << Car::carCount << endl;

	// {
	// 	Car audi(30);
	// }
	// {
	// 	Car audi(30);
	// }
	// cout << "Car count: " << Car::carCount << endl;

	// directrly create an Audi object
	// Audi audi(30);
	// audi.boom();
	// audi.pitStop();
	// cout << "Speed: " << audi.getSpeed() << endl;

	// polymorphism
	// Car *audi = new Audi(30);

	// audi->boom();
	// // audi.pitStop(); wont work, bc it is a child function
	// cout << "Speed: " << audi->getSpeed() << endl;

	// delete audi;

	cout << "Hello, World!" << endl;

	return 0;
}