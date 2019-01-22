#pragma once
#include "Bike.h"
class HelloBike : public Bike
{
	std::string eLockCode;
	const int speed = 25;
public:
	HelloBike(const char* id, const char* elock_id, int location_x, int location_y, int comfort_rating);
	bool unlock();
	int lock();
	int compute_cost();
};

