#pragma once
#include"Bike.h"
#include"HelloBike.h"
#include"OfoBike.h"
#include<vector>
class BikeSystem
{
	std::vector<Bike*> bikes;
	int size;
	const int capacity = 100;
public:
	BikeSystem() : bikes(0), size(0) {};
	void add(Bike *New_Bike);
	bool unlock_bike(int index);
	bool lock(int index);
	bool ride_record(int index, int distance_x, int distance_y);
	int search(const char* user_name, int start_x, int start_y, int acceptable_comfort_rating);
};


