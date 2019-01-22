#include "OfoBike.h"

OfoBike::OfoBike(const char* id, int location_x, int location_y, int comfort_rating)
{
	serial = id;
	x = location_x;
	y = location_y;
	comfort = comfort_rating;
}

bool OfoBike::unlock()
{
	if (occupied)
	{
		//如果解锁失败
		std::cout << "fail to unlock " << serial << std::endl;
		return false;
	}
	else
	{
		//解锁成功
		std::cout << "unlock " << serial << std::endl;
		occupied = true;
		return true;
	}
}

int OfoBike::lock()
{
	if (!occupied)
	{
		std::cout << serial << " has been locked" << std::endl;
		return -1;
	}
	else
	{
		occupied = false;
		std::cout << "lock " << serial << std::endl;
		return compute_cost();
	}
}

int OfoBike::compute_cost()
{
	//how to compute?
	return 0;
}

