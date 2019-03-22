#pragma once
#include "Bike.h"
class Bike;
class OfoBike : public Bike
{
	const int speed = 21;
public:
	OfoBike(const char *id, int location_x, int location_y, int comfort_rating);
	bool unlock();
	int lock();
	int compute_cost();
};

