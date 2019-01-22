#include<iostream>
#include"Bike.h"
#include"HelloBike.h"
#include"OfoBike.h"
int main()
{
	Bike* tempBike = new OfoBike("ofo10", 40, 15, 4);
	tempBike->unlock();
	tempBike->unlock();
	std::cout << tempBike->lock() << std::endl;
	std::cout << tempBike->lock() << std::endl;

	Bike* tempBke = new OfoBike("ofobike09", 15, 55, 3);
	tempBke->unlock();
	tempBke->move_to(90, 85);
	std::cout << tempBke->lock() << std::endl;

	system("pause");
}