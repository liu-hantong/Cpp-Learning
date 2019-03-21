#pragma once
#include<string>
#include<vector>
using namespace std;

/*
CardsNature is correspond to different group of cards
1: Single
2: Double
3: Treble
4: Trible with Single 5: Treble with Double
6: Continual Double   7: Continual Single
8: Four with Two
9:  2 Airplanes with zero
10: 2 Airplanes with 2 single wings
11: 2 Airplanes with 2 double wings
12: 3 Airplanes with zero
13: 3 Airplanes with 2 single wings
14: 3 Airplanes with 2 double wings
15: Normal Bomb
16: Lords Bomb
*/

class PokerAnalysis
{
	//This function works as a machine to determine what cards are these
public:
	vector<string> Cards;
	int CardsNumber;
	int CardsNature;
	PokerAnalysis(vector<string> Cards, int number);  //the main function to judge
	void Judge_6();								      //judge 6 cards
	void Judge_8();                                   //judge 8 cards
	void Judge_10();								  //judge 10 cards
	void Judge_12();								  //judge 12 cards
};