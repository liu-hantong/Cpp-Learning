#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include"PokerAnalysis.h"
using namespace std;

/*
Strategy_x is correspond to different kind of enemy pokers
1: Single
2: Double
3: Treble
4: Trible with Single 5: Treble with Double
6: Continual Double   7: Continual Single
8: Four with Two
9:  2 Airplanes with zero
10: 2 Airplanes with 2 single wings
11: 2 Airplanes with 2 double wings
12: Normal Bomb
13: Lords Bomb
*/


class MyPoker
{
private:
	int MyNumber, EnemyNumber;
	int EnemyNature;			//mark the nature of the enemy you should confront
	const vector<string> PokerSeries = { "3", "4", "5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER" };
	vector<string> MyCards;
	vector<string> EnemyCards;
public:
	vector<string> MyOut;       //mark the cards I am going to hand out

	MyPoker(vector<string> MyCards, int MyNumber, PokerAnalysis Enemy);

	//simply compare the two Pokers£¬1 if bigger, 0 if equal, -1 if smaller
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
	case 12: Strategy_Bomb(); break;
	case 13: Strategy_Bomb(); break;
	case 14: Strategy_Bomb(); break;
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
	return  std::adjacent_find(Object.begin(), Object.end(), std::not_equal_to<>()) == Object.end();
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
	int flag = 0;
	for (flag = 0; flag < MyNumber; ++flag)
	{
		if (PokerCompare(MyCards[flag], EnemyCards[0]) == 1)
		{
			MyOut.push_back(MyCards[flag]);
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
		{
			MyOut = result;
			break;
		}
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
			CardsErased.erase(CardsErased.begin() + flag, CardsErased.begin() + flag + 3);
			//and find double in CardsErased
			vector<string> ResultWing;
			for (int flag2 = 0; flag2 < MyNumber - 1; ++flag2)
			{
				ResultWing = GetXPokersOut(CardsErased, flag2, 2);
				if (ResultWing[0] == ResultWing[1])
				{
					//combine the two results to create 3with2
					MyOut.reserve(result.size() + ResultWing.size()); 
					MyOut.insert(MyOut.end(), result.begin(), result.end());
					MyOut.insert(MyOut.end(), ResultWing.begin(), ResultWing.end());
					break;
				}
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

	//find proper EnemyNumber pokers
	for (flag = 0; flag < MyNumber - (EnemyNumber - 1); ++flag)
	{
		result = GetXPokersOut(MyCards, flag, EnemyNumber);
		//determine whether it's continual double
		if (PokerCompare(result[0], EnemyCards[0]) <= 0 || result[0] != result[1])
			continue;
		/*
		auto Part1 = find(PokerSeries.begin(), PokerSeries.end(), result[0]);
		if (*(Part1 + 1) != result[2] || result[2] != result[3])
			continue;
		auto Part2 = find(PokerSeries.begin(), PokerSeries.end(), result[2]);
		if (*(Part2 + 1) != result[4] || result[4] != result[5])
			continue;
			*/
		//examine whether they are 2 equal and whether they are continual
		int  EqualExaminePosition = 0;
		for (; EqualExaminePosition < result.size() - 3; EqualExaminePosition += 2)
		{
			if (result[EqualExaminePosition] != result[EqualExaminePosition + 1])
				//if are not equal
				break;
			auto ShouldBe = *(find(PokerSeries.begin(), PokerSeries.end(), result[EqualExaminePosition]) + 1);
			if (ShouldBe != result[EqualExaminePosition + 2])
				//if are not continual
				break;
		}
		if ((EqualExaminePosition == (result.size() - 2)) && (result[result.size() - 2] == result[result.size() - 2]))
		{
			MyOut = result;
			break;
		}
	}
	//do not find proper cards
	if (flag == MyNumber - (EnemyNumber - 1))
		return Strategy_Bomb();
}

void MyPoker::Strategy_7()
{
	//find 7 pokers that is cumulative
	int flag;
	vector<string> result;

	for (flag = 0; flag < MyNumber - (EnemyNumber - 1); ++flag)
	{
		//get EnemyNumbers pokers out to determine
		result = GetXPokersOut(MyCards, flag, EnemyNumber);
		
		//determine whether the cards are continual single
		//take out EnemyNumber members of CardsSeries and compare it with the result
		
		for (int SeriesFlag = 0; SeriesFlag < (PokerSeries.size() - (EnemyNumber + 1)); ++SeriesFlag)
		{
			vector<string> CurrentSeries(&PokerSeries[SeriesFlag], &PokerSeries[SeriesFlag + EnemyNumber]);
			// whether currentseries are equal to result
			int i;
			for (i = 0; i < EnemyNumber; ++i)
				if (CurrentSeries[i] != result[i])
					break;
			if (i == EnemyNumber)
			{
				MyOut = result;
				break;
			}
		}
	}

	//if cannot find a proper continual single
	if (flag == MyNumber - (EnemyNumber - 1))
		return Strategy_Bomb();

}

void MyPoker::Strategy_8()
{
	int flag;
	vector<string> result;
	for (flag = 0; flag < MyNumber - 3; ++flag)
	{
		//get 4 pokers out
		result = GetXPokersOut(MyCards, flag, 4);
		//if the 4 cards aren't equal
		if (!IfAllEquall(result))
			continue;
		//if the 4 equal cards are bigger than the enemy
		if (PokerCompare(result[0], EnemyCards[0]) > 0)
		{
			vector<string> Remain = MyCards;
			Remain.erase(Remain.begin() + flag, Remain.begin() + flag + 4);
			result.push_back(Remain[0]);
			result.push_back(Remain[1]);
			MyOut = result;
			break;
		}
		else
			continue;
	}
	//don't find proper, use bomb
	if (flag == MyNumber - 3)
		return Strategy_Bomb();
}

void MyPoker::Strategy_9()
{
	//find 2 airplanes without wings
	//like 333 444
	int flag;
	vector<string> result;
	for (flag = 0; flag < MyNumber - 5; ++flag)
	{
		result = GetXPokersOut(MyCards, flag, 6);
		if (PokerCompare(result[0], EnemyCards[0]) <= 0)
			continue;
		if (*(find(PokerSeries.begin(), PokerSeries.end(), result[0]) + 1) != result[3])
			//if the numbers are not closed
			continue;
		else
		{
			//if the numbers are closed, determine whether the 3 are equal respectively
			vector<string> formerPart = result;
			vector<string> latterPart = result;
			formerPart.erase(formerPart.begin() + 3, formerPart.end());
			latterPart.erase(latterPart.begin(), latterPart.begin() + 3);
			if (IfAllEquall(formerPart) && IfAllEquall(latterPart))
			{
				MyOut = result;
				break;
			}
		}
	}
	//if doesn't find an airplane, bomb!
	if (flag == MyNumber - 5)
		return Strategy_Bomb();
}

void MyPoker::Strategy_10()
{
	//find two airplanes with two single wings
	//like 2 333 444 A
	int flag;
	vector<string> result;
	for (flag = 0; flag < MyNumber - 5; ++flag)
	{
		result = GetXPokersOut(MyCards, flag, 6);
		if (PokerCompare(result[0], EnemyCards[1]) <= 0)
			continue;
		if (*(find(PokerSeries.begin(), PokerSeries.end(), result[0]) + 1) != result[3])
			//if the numbers are not closed
			continue;
		else
		{
			//if the numbers are closed, determine whether the 3 are equal respectively
			vector<string> formerPart = result;
			vector<string> latterPart = result;
			formerPart.erase(formerPart.begin() + 3, formerPart.end());
			latterPart.erase(latterPart.begin(), latterPart.begin() + 3);
			
			if (IfAllEquall(formerPart) && IfAllEquall(latterPart))
			{
				//if found the 2 airplanes
				//erase the 2 airplanes
				vector<string> Remain = MyCards;
				Remain.erase(Remain.begin() + flag, Remain.begin() + flag + 6);
				string FirstWing = Remain[0];
				string SecondWing;
				//find the second wing
				for (int i = 1; i < Remain.size(); ++i)
				{
					if (Remain[i] != FirstWing)
					{
						SecondWing = Remain[i];
						break;
					}
				}
				if (SecondWing.empty())
					//doesn't find the second wing
					continue;
				else
				{
					//find the second wing
					MyOut = result;
					MyOut.push_back(FirstWing);
					MyOut.push_back(SecondWing);
					break;
				}
			}
		}

		//doesn't find a proper plane
		if (flag == MyNumber - 5)
			return Strategy_Bomb();
	}
}

void MyPoker::Strategy_11()
{
	//find two airplanes with two double wings
    //like 22 333 444 AA
	int flag;
	vector<string> result;
	for (flag = 0; flag < MyNumber - 5; ++flag)
	{
		result = GetXPokersOut(MyCards, flag, 6);
		if (PokerCompare(result[0], EnemyCards[2]) <= 0)
			continue;
		if (*(find(PokerSeries.begin(), PokerSeries.end(), result[0]) + 1) != result[3])
			//if the numbers are not closed
			continue;
		else
		{
			//if the numbers are closed, determine whether the 3 are equal respectively
			vector<string> formerPart = result;
			vector<string> latterPart = result;
			formerPart.erase(formerPart.begin() + 3, formerPart.end());
			latterPart.erase(latterPart.begin(), latterPart.begin() + 3);
			if (IfAllEquall(formerPart) && IfAllEquall(latterPart))
			{
				//if found the 2 airplanes
				//erase the 2 airplanes and find 2 double
				vector<string> Remain = MyCards;
				Remain.erase(Remain.begin() + flag, Remain.begin() + flag + 6);
				
				//find the first wing
				vector<string> FirstWing;
				int FirstWingFlag = 0;
				for (; FirstWingFlag < Remain.size() - 1; ++FirstWingFlag)
				{
					FirstWing = GetXPokersOut(Remain, FirstWingFlag, 2);
					if (FirstWing[0] == FirstWing[1])
						break;
				}
				if (FirstWingFlag == Remain.size() - 1)
					continue;
				//find the second wing
				vector<string> Remain2 = Remain;
				vector<string> SecondWing;
				Remain2.erase(Remain2.begin() + FirstWingFlag, Remain2.begin() + FirstWingFlag + 2);
				int SecondWingFlag = 0;
				for (; SecondWingFlag < Remain2.size() - 1; ++SecondWingFlag)
				{
					SecondWing = GetXPokersOut(Remain2, SecondWingFlag, 2);
					if (SecondWing[0] == SecondWing[1])
						break;
				}
				if (SecondWingFlag == Remain2.size() - 1)
					continue;
				MyOut = result;
				MyOut.push_back(FirstWing[0]);
				MyOut.push_back(FirstWing[1]);
				MyOut.push_back(SecondWing[0]);
				MyOut.push_back(SecondWing[1]);
				break;
			}
		}
	}

	//doesn't find a proper plane
	if (flag == MyNumber - 5)
		return Strategy_Bomb();
}

void MyPoker::Strategy_Bomb()
{
	//find a bomb to overcome the bomb of the enemy
	vector<string> Bomb;
	int flag;
	for (flag = 0; flag < MyNumber - 3; ++flag)
	{
		//find a normal bomb
		Bomb = GetXPokersOut(MyCards, flag, 4);
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
