#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include"PokerAnalysis.h"
using namespace std;
class MyPoker
{
private:
	int MyNumber, EnemyNumber;
	int EnemyNature;			//mark the nature of the enemy you should confront
	const vector<string> PokerSeries = { "3", "4", "5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER" };
	vector<string> MyCards;
	vector<string> EnemyCards;
	vector<string> MyOut;       //mark the cards I am going to hand out
public:
	MyPoker(vector<string> MyCards, int MyNumber, PokerAnalysis Enemy);

	//simply compare the two Pokers��1 if bigger, 0 if equal, -1 if smaller
	int PokerCompare(string Poker1, string Poker2);
	
	//determine whether the values inside a vector is all equal
	bool IfAllEquall(vector<string>);
	
	//Get X pokers out
	vector<string> GetXPokersOut(vector<string>, int position, int X);
	
	//the following functions are correspond to different natures
	void Strategy_1();         
	void Strategy_2();
	void Strategy_3();
	void Strategy_4();
	void Strategy_5();
	void Strategy_6();
	void Strategy_7();
	void Strategy_8();
	void Strategy_9();
	void Strategy_10();
	void Strategy_11();
	void Strategy_12();
	void Strategy_13();
	void Strategy_14();
	void Strategy_Bomb();
};

MyPoker::MyPoker(vector<string> MyCards, int MyNumber, PokerAnalysis Enemy)
{

	//assign the initial value of these vals
	this->MyCards = MyCards;
	this->MyNumber = MyNumber;
	this->EnemyCards = Enemy.Cards;
	this->EnemyNumber = Enemy.CardsNumber;
	this->MyOut.clear();
	EnemyNature = Enemy.CardsNature;
	
	//reverse the vector, make sure that the smallest card is at the beginning
	reverse(this->MyCards.begin(), this->MyCards.end());

	//use different strategy depending on different nature
	switch (EnemyNature)
	{
	case 1: Strategy_1(); break;
	case 2: Strategy_2(); break;
	case 3: Strategy_3(); break;
	case 4: Strategy_4(); break;
	case 5: Strategy_5(); break;
	case 6: Strategy_6(); break;
	case 7: Strategy_7(); break;
	case 8: Strategy_8(); break;
	case 9: Strategy_9(); break;
	case 10: Strategy_10(); break;
	case 11:Strategy_11(); break;
	case 12: Strategy_12(); break;
	case 13: Strategy_13(); break;
	case 14: Strategy_14(); break;
	
	//case 15 is bomb issue
	case 15: Strategy_Bomb(); break;

	//no poker combination can be superior than case Lord Bomb
	//so do nothing and let MyOut be empty
	case 16: ; break;
	default:
		break;
	}
}

bool MyPoker::IfAllEquall(vector<string> Object)
{	
	return 
		find_if(Object.begin() + 1,
			Object.end(),
			bind1st(not_equal_to<int>(), Object.front())) == Object.end();

}

vector<string> MyPoker::GetXPokersOut(vector<string> Pokers, int position, int X)
{
	vector<string> result;
	for (int flag = position; flag < position + X; ++flag)
		result.push_back(Pokers[flag]);
	return result;
}


int MyPoker::PokerCompare(string Poker1, string Poker2)
{
	//compare 2 pokers
	auto Poker1Position = find(PokerSeries.begin(), PokerSeries.end(), Poker1);
	auto Poker2Position = find(PokerSeries.begin(), PokerSeries.end(), Poker2);
	if (Poker1Position == Poker2Position)
		return 0;
	else
	{
		if (Poker1Position > Poker2Position)
			return 1;
		else
			return -1;
	}
}

void MyPoker::Strategy_1()
{
	//compare
	int flag;
	for (int flag = 0; flag < MyNumber; ++flag)
	{
		if (PokerCompare(MyCards[flag], EnemyCards[0]) == 1)
		{
			MyOut[0] = MyCards[flag];
			break;
		}
	}
	if (flag == MyNumber)
		return Strategy_Bomb();
}

void MyPoker::Strategy_2()
{
	int flag;
	vector<string> result;
	
	//find proper double
	for (flag = 0; flag < MyNumber - 1; ++flag)
	{
		result = GetXPokersOut(MyCards, flag, 2);
		if (IfAllEquall(result) && PokerCompare(result[0], EnemyCards[0]) > 0)
			MyOut = result;
	}

	//find bomb
	if (flag == MyNumber - 1)
		return Strategy_Bomb();

}

void MyPoker::Strategy_3()
{
	int flag;
	vector<string> result;

	//find proper treble
	for (flag = 0; flag < MyNumber - 2; ++flag)
	{
		result = GetXPokersOut(MyCards, flag, 3);
		if (IfAllEquall(result) && PokerCompare(result[0], EnemyCards[0]) > 0)
			MyOut = result;
	}

	//find bomb
	if (flag == MyNumber - 1)
		return Strategy_Bomb();
}

void MyPoker::Strategy_4()
{
	//confront 3iwth1
	int flag;
	vector<string> result;

	//find proper treble
	for (flag = 0; flag < MyNumber - 2; ++flag)
	{
		result = GetXPokersOut(MyCards, flag, 3);
		if (IfAllEquall(result) && PokerCompare(result[0], EnemyCards[0]) > 0)
		{
			//whether the 3 pokers are at the begining of my cards
			//to combine the pokers into 3 with 1
			if (flag == 0)
				result.push_back(MyCards[3]);
			else
				result.push_back(MyCards[0]);
			MyOut = result;
			break;
		}
	}

	//find bomb to confront
	if (flag == MyNumber - 2)
		return Strategy_Bomb();
}

void MyPoker::Strategy_5()
{
	int flag;
	vector<string> result;

	//find proper treble
	for (flag = 0; flag < MyNumber - 2; ++flag)
	{
		result = GetXPokersOut(MyCards, flag, 3);
		if (IfAllEquall(result) && PokerCompare(result[0], EnemyCards[0]) > 0)
		{
			//find treble
			//and the result depends on whether I have double or not
			//remove the 3 cards first
			auto CardsErased = MyCards;
			CardsErased.erase(MyCards.begin() + flag, MyCards.begin() + flag + 2);
			//and find double in CardsErased
			vector<string> ResultWing;
			for (int flag2 = 0; flag2 < MyNumber - 1; ++flag2)
			{
				ResultWing = GetXPokersOut(CardsErased, flag, 2);
				if (result[0] == result[1])
				{
					//combine the two results to create 3with2
					MyOut.reserve(result.size() + ResultWing.size()); 
					MyOut.insert(MyOut.end(), result.begin(), result.end());
					MyOut.insert(MyOut.end(), ResultWing.begin(), ResultWing.end());
					break;
				}
				ResultWing.clear();
			}
			//if already find the result, break
			if (MyOut.size() == 5)
				break;
		}
	}

	//do not find proper, bomb!
	if (flag == MyNumber - 2)
		return Strategy_Bomb();
}


void MyPoker::Strategy_6()
{
	int flag;
	vector<string> result;

	//find proper 6 pokers
	for (flag = 0; flag < MyNumber - 5; ++flag)
	{
		result = GetXPokersOut(MyCards, flag, 6);
		//determine whether it's continual double
		if (PokerCompare(result[0], EnemyCards[0]) <= 0 || result[0] != result[1])
			continue;
		auto Part1 = find(PokerSeries.begin(), PokerSeries.end(), result[0]);
		if (*(Part1 + 1) != result[2] || result[2] != result[3])
			continue;
		auto Part2 = find(PokerSeries.begin(), PokerSeries.end(), result[2]);
		if (*(Part2 + 1) != result[4] || result[4] != result[5])
			continue;
		MyOut = result;
		break;
	}

	if (flag == MyNumber - 5)
		return Strategy_Bomb();
}

void MyPoker::Strategy_7()
{

}

void MyPoker::Strategy_8()
{

}

void MyPoker::Strategy_9()
{

}

void MyPoker::Strategy_10()
{

}

void MyPoker::Strategy_11()
{

}

void MyPoker::Strategy_12()
{

}

void MyPoker::Strategy_13()
{

}

void MyPoker::Strategy_14()
{

}

void MyPoker::Strategy_Bomb()
{
	//find a bomb to overcome the bomb of the enemy
	vector<string> Bomb;
	int flag, BombStart;
	for (flag = 0; flag < MyNumber - 3; ++flag)
	{
		//find a normal bomb
		Bomb.clear();
		Bomb = GetXPokersOut(flag, 4);
		bool equal = IfAllEquall(Bomb);
		if (EnemyNature != 15 && equal)
		{
			//if the enemy is not a bomb, any bomb can be handout
			MyOut = Bomb;
			break;
		}
		else if(EnemyNature == 15 && equal)
			//if the enemy is a bomb, so comparing is necessary
			if (Bomb[0] > EnemyCards[0])
				MyOut = Bomb;
	}
	Bomb.clear();
	if (MyOut.empty())
	{
		//if doesn't find a proper normal bomb, you should find a lord bomb
		if (MyCards[MyNumber - 2] == "joker" && MyCards[MyNumber - 1] == "JOKER")
		{
			MyOut.push_back("JOKER");
			MyOut.push_back("joker");
		}
	}
}
