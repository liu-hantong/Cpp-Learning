#include<string>
#include<math.h>
#include<iostream>
#pragma once
class Bike
{
public:
	std::string serial;
	bool occupied;
	int distance;
	int x, y;
	int comfort;
	int cost;
public:
	Bike() : occupied(false), distance(0) {};
	virtual bool unlock();//unlock the bike, occupied = true, ½âËø³É¹¦
	virtual int lock();   //lock the bike
	int move_to(int destination_x, int destination_y);//update the distance
	virtual int compute_cost() = 0; //compute the cost and return thte cost
};