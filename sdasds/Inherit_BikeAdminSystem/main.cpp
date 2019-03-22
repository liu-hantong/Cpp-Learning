#include<iostream>
#include"Bike.h"
#include"HelloBike.h"
#include"OfoBike.h"
#include"BikeSystem.h"
int main()
{
	//test
	Bike* tempBike = new OfoBike("ofo10", 40, 15, 4);
	tempBike->unlock();
	tempBike->unlock();
	std::cout << tempBike->lock() << std::endl;
	std::cout << tempBike->lock() << std::endl;

	Bike* tempBke = new OfoBike("ofobike09", 15, 55, 3);
	tempBke->unlock();
	tempBke->move_to(90, 85);
	std::cout << tempBke->lock() << std::endl;

	BikeSystem bike_system;
	bike_system.add(new OfoBike("ofo05", 30, 60, 9));
	bike_system.add(new HelloBike("hellobike01", "hellobike_elock", 30, 60, 9));
	bike_system.add(new OfoBike("ofo01", 100, 100, 5));
	bike_system.add(new OfoBike("ofo02", 90, 0, 6));
	bike_system.add(new OfoBike("ofo03", 30, 70, 7));
	bike_system.add(new OfoBike("ofo04", 70, 0, 8));

	int idx1 = bike_system.search("xiaoming", 50, 50, 5);
	int idx2 = bike_system.search("xiaohong", 50, 50, 9);

	bike_system.unlock_bike(idx1);
	bike_system.unlock_bike(idx2);
	bike_system.ride_record(idx1, 100, 100);
	bike_system.ride_record(idx1, 100, 80);
	bike_system.lock(idx1);

	system("pause");
}