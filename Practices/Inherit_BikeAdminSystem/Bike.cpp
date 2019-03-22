#include "Bike.h"



bool Bike::unlock()
{
	if (!occupied)
	{
		occupied = true;
		return true;
	}
	return false;
}


int Bike::lock()
{
	if (occupied)
	{
		occupied = false;
		distance = 0;
		return true;
	}
	else
		return false;
}

int Bike::move_to(int destination_x, int destination_y)
{
	std::cout << "from " << x << ", " << y << " to " << destination_x << ", " << destination_y << std::endl;
	x = destination_x;
	y = destination_y;
	distance = abs(x - destination_x) + abs(y - destination_y);
	return destination_x;
}
