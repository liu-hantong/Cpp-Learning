#include "BikeSystem.h"


void BikeSystem::add(Bike *New_Bike)
{
	bikes.push_back(New_Bike);
	size += 1;
}

bool BikeSystem::unlock_bike(int index)
{
	if (bikes[index]->unlock())
		return true;
	return false;
}

bool BikeSystem::lock(int index)
{
	if (bikes[index]->lock())
		return true;
	return false;
}

bool BikeSystem::ride_record(int index, int distance_x, int distance_y)
{
	if (bikes[index]->move_to(distance_x, distance_y))
		return true;
	return false;
}

int distance_from_here(Bike *available, int start_x, int start_y)
{
	return abs(available->x - start_x) + abs(available->y - start_y);
}

int BikeSystem::search(const char* user_name, int start_x, int start_y, int acceptable_comfort_rating)
{
	bool flag = 0;   //mark the corresponding bike
	int current_bike;//mark the corresponding bike index than is satisfactory
	for (int i = 0; i != bikes.size(); ++i)
		if (bikes[i]->comfort >= acceptable_comfort_rating && bikes[i]->occupied == false)
		{
			if (!flag)
			{
				current_bike = i;
				flag = true;
				continue;
			}
			if (distance_from_here(bikes[i], start_x, start_y) < distance_from_here(bikes[current_bike], start_x, start_y))
			{
				current_bike = i;
				continue;
			}
			if (distance_from_here(bikes[i], start_x, start_y) == distance_from_here(bikes[current_bike], start_x, start_y)
				&& bikes[i]->comfort > bikes[current_bike]->comfort)
			{
				current_bike = i;
				continue;
			}
			if (distance_from_here(bikes[i], start_x, start_y) == distance_from_here(bikes[current_bike], start_x, start_y)
				&& bikes[i]->comfort == bikes[current_bike]->comfort)
				continue;
		}
	if (flag)
	{
		std::cout << user_name << " selected " << bikes[current_bike]->serial << std::endl;
		return current_bike;
	}
	else
	{
		std::cout << user_name << " found no bikes available" << std::endl;
		return -1;
	}
}
