#include"PokerAnalysis.h"

PokerAnalysis::PokerAnalysis(vector<string> Cards, int number) : Cards(Cards), CardsNumber(number), CardsNature(0)
{
	switch (number)
	{
		//determine what nature are these pokers using the number of the current pokers
	case 1: CardsNature = 1; break;                                                  //single
	case 2: if (Cards[0] != Cards[1]) CardsNature = 16; else CardsNature = 2; break; //bomb or double
	case 3: CardsNature = 3; break;                                                  //treble
	case 4: if (Cards[2] != Cards[3]) CardsNature = 4; else CardsNature = 15; break; //3with1 or bomb
	case 5: if (Cards[0] == Cards[1]) CardsNature = 5; else CardsNature = 7; break;  //3with2 or continual single 
	case 6: Judge_6(); break;               //continual double or continual single or 4with2 or airplane with no wings
	case 7: CardsNature = 7; break;         //Continual Singles
	case 8: Judge_8(); break;               //continual single or 2 planes with 2 single wings or continual double
	case 9: if (Cards[0] != Cards[1]) CardsNature = 7; else CardsNature = 12; break; //continual single or 3planes with no wings
	case 10: Judge_10(); break;             //continual single or continual double or 2 planes with 2 double wings
	case 11: CardsNature = 7; break;         //continual single
	case 12: Judge_12(); break;				//continual single or 3 planes with 3 single cards or continual double
	case 13: CardsNature = 7; break;        //continual single 
	case 15: CardsNature = 14; break;		//3 planes with 3 double wings
	default:
		break;
	}
}

void PokerAnalysis::Judge_6()
{
	if (Cards[2] != Cards[3])
	{
		if (Cards[0] != Cards[1])
			CardsNature = 7;       //continual single
		else
			CardsNature = 9;       //plane without wings
	}
	else
	{
		if (Cards[1] != Cards[2])
			CardsNature = 6;       //continue double
		else
			CardsNature = 8;       //4with2
	}

}

void PokerAnalysis::Judge_8()
{
	if (Cards[2] != Cards[3])
		CardsNature = 7;           //continual single
	else
	{
		if (Cards[0] != Cards[1])
			CardsNature = 10;      //2 planes with 2 single wings
		else
			CardsNature = 6;       //continual double
	}
}

void PokerAnalysis::Judge_10()
{
	if (Cards[2] != Cards[3])
		CardsNature = 7;           //continual single
	else
	{
		if (Cards[3] != Cards[4])
			CardsNature = 6;       //continual double
		else
			CardsNature = 11;      //2 planes with 2 double wings
	}
}

void PokerAnalysis::Judge_12()
{
	if (Cards[1] != Cards[1])
		CardsNature = 7;           //continual single
	else
	{
		if (Cards[2] != Cards[3])
			CardsNature = 13;      //3 planes with 3 single cards
		else
			CardsNature = 6;       //continual double
	}

}
