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
	const vector<string> PokerSeries = { "1", "3", "4", "5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER" };
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