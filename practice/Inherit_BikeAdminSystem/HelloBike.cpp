#include "HelloBike.h"

int HelloBike::compute_cost()
{
	//How to calculate?
	return 0;
}

HelloBike::HelloBike(const char* id, const char* eclock_id, int location_x, int location_y, int comfort_rating)
{
	serial = id;
	eLockCode = eclock_id;
	x = location_x;
	y = location_y;
	comfort = comfort_rating;
}

bool HelloBike::unlock()
{
	if (!occupied)
	{
		std::cout << "unlock " << serial << " " << eLockCode << std::endl;
		occupied = true;
		return true;
	}
	else
	{
		std::cout << "fail to unlock " << serial << " " << eLockCode << std::endl;
		return false;
	}
}

int HelloBike::lock()
{
	if (occupied)
	{
		occupied = false;
		std::cout << "lock " << serial << " " << eLockCode << std::endl;
		return compute_cost();
	}
	else
	{
		std::cout << serial << " " << eLockCode << " has been locked" << std::endl;
		return -1;
	}
}