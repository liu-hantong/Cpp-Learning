#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
#include<memory>
#include"MyPoker.h"
#include"PokerAnalysis.h"
using namespace std;

const bool USE_SUITS = false;

const int N_CARD_VALUES = 15;
const string CARD_VALUES[] = {
    "3", "4", "5", "6",
    "7", "8", "9", "10",
    "J", "Q", "K", "A", "2",
    "joker", "JOKER"
};
const int N_CARD_SUITS = 4;
const string CARD_SUITS[] = {
   "Spade", "Heart", "Diamond", "Club"
};


int my_random (int i) {
    return std::rand()%i;
}

vector<string> get_new_deck() {
    vector<string> deck;
    for (int i = 0; i < N_CARD_VALUES-2; ++i) {
        for (int j = 0; j < N_CARD_SUITS; ++j) {
           string card = CARD_VALUES[i];
           if (USE_SUITS) card = CARD_SUITS[j] + "_" + card;
           deck.push_back(card);
        }
    }
    deck.push_back(CARD_VALUES[13]);
    deck.push_back(CARD_VALUES[14]);
    return deck;
}

void sort_the_pokers(shared_ptr<vector<string>> PokersNeedTobeSorted);                                                        //sort the pokers by poker order
vector<string> OriginOut(vector<string> PokersNneedToOut);                                                                    //select pokers to out
void Out_Display_Result(string Name, shared_ptr<vector<string>>, vector<string> OutPokers, vector<string>& GreatestPokers);   //out proper pokers and print results
vector<vector<string>> MinPokers;
void Prepare_For_The_MinPokers(); //prepare for the min pokers to be compared during the match


int main(int argc, char* argv[]) {
	unsigned int random_seed;
	cin >> random_seed;
	srand(random_seed);

	vector<string> deck = get_new_deck();
	random_shuffle(deck.begin(), deck.end(), my_random);
	//generate the random cards
	cout << "Current Lap" << endl;

	//The pokers needed to be used during the Play
	vector<string> CurrentGreatestPoker;
	vector<string> Lord_Pokers(deck.begin(), deck.begin() + 20);
	vector<string> Farmer1_Pokers(deck.begin() + 20, deck.begin() + 37);
	vector<string> Farmer2_Pokers(deck.begin() + 37, deck.end());

	//Make three Pointers Edition of each player
	auto LordPtr = make_shared<vector<string>> (Lord_Pokers);
	auto Farmer1Ptr = make_shared<vector<string>> (Farmer1_Pokers);
	auto Farmer2Ptr = make_shared<vector<string>> (Farmer2_Pokers);


	//sort the poker from large to small
	sort_the_pokers(LordPtr);
	sort_the_pokers(Farmer1Ptr);
	sort_the_pokers(Farmer2Ptr);

	reverse(LordPtr->begin(), LordPtr->end());
	reverse(Farmer1Ptr->begin(), Farmer1Ptr->end());
	reverse(Farmer2Ptr->begin(), Farmer2Ptr->end());
	
	
	int PlayerNow = 0; //Mark the player who is going to choose a poker
	int OriginPlay = 1;//Mark whether you should out new pokers in a lap
	int PassTime = 0;  //Mark whether you should Origin Out, if 2

	//mark the pokers by the owners' number
	map<int, shared_ptr<vector<string>>> NumberToPlayer;
	NumberToPlayer.insert(make_pair(0, LordPtr));
	NumberToPlayer.insert(make_pair(1, Farmer1Ptr));
	NumberToPlayer.insert(make_pair(2, Farmer2Ptr));

	//mark the name of the owners of the players
	map<int, string> NumberToPlayerName;
	NumberToPlayerName.insert(make_pair(0, "Lord"));
	NumberToPlayerName.insert(make_pair(1, "Farmer No.1"));
	NumberToPlayerName.insert(make_pair(2, "Farmer No.2"));

	Prepare_For_The_MinPokers();

	//print the current pokers
	cout << "Lord: ";
	for (auto a = LordPtr->begin(); a < LordPtr->end(); ++a)
		cout << *a << " ";
	cout << endl;
	cout << "Farmer1: ";
	for (auto a = Farmer1Ptr->begin(); a < Farmer1Ptr->end(); ++a)
		cout << *a << " ";
	cout << endl;
	cout << "Farmer2: ";
	for (auto a = Farmer2Ptr->begin(); a < Farmer2Ptr->end(); ++a)
		cout << *a << " ";
	cout << endl;

	//Start the game
	while (!LordPtr->empty() && !Farmer1Ptr->empty() && !Farmer2Ptr->empty())
	{
		cout << endl;
		//make a loop between 0 and 2, one lap
		if (PlayerNow == 3) PlayerNow = 0;
		
		//if you should origin play
		if (PassTime == 2)
		{
			PassTime = 0;
			OriginPlay = true;
		}

		if (OriginPlay)
		{
			//your first time to out the pokers or you are the richest player
			OriginPlay = 0;
			vector<string> MyOut = OriginOut(*NumberToPlayer[PlayerNow]);

			Out_Display_Result(NumberToPlayerName[PlayerNow], NumberToPlayer[PlayerNow], MyOut, CurrentGreatestPoker);
			
			
			//DeleteThePokers(NumberToPlayer[PlayerNow], MyOut);
			//CurrentGreatestPoker = MyOut;
			//DisplayTheSituationOfPlayer(NumberToPlayerName[PlayerNow],*NumberToPlayer[PlayerNow], MyOut);
			
		}

		
		else if(!OriginPlay)
		{
			//if should follow the poker of the previous player
			PokerAnalysis CurrentBiggest(CurrentGreatestPoker, CurrentGreatestPoker.size());
			MyPoker CurrentPlayer(*NumberToPlayer[PlayerNow], NumberToPlayer[PlayerNow]->size(), CurrentBiggest);

			if (!CurrentPlayer.MyOut.empty())
			{
				//have pokers that are bigger the biggest, out and clear the pass time
				PassTime = 0;
				Out_Display_Result(NumberToPlayerName[PlayerNow], NumberToPlayer[PlayerNow], CurrentPlayer.MyOut, CurrentGreatestPoker);
			}
			else
			{
				//do not have, add Pass Time
				++PassTime;
				cout << NumberToPlayerName[PlayerNow] << " pass" << endl;
			}
		}
		//transfer to the next player
		++PlayerNow;
	}

	if (Farmer1Ptr->empty() || Farmer2Ptr->empty())
		cout << "Farmers Win!!!!!!!" << endl;
	else
		cout << "Lord Win!!!!!!!!!!" << endl;
	getchar(); getchar();
    return 0;
	
}

void Prepare_For_The_MinPokers()
{
	MinPokers.resize(30);
	MinPokers[0] = { "1" };
	MinPokers[1] = { "1", "1" };
	MinPokers[2] = { "1" , "1", "1"};
	MinPokers[3] = { "3", "1", "1", "1" };
	MinPokers[4] = { "3", "3", "1", "1", "1" };
	MinPokers[5] = { "6", "5", "4", "3", "1" };
	MinPokers[6] = { "7", "6", "5", "4", "3" , "1"};
	MinPokers[7] = { "4", "4", "3", "3", "1", "1" };
	MinPokers[8] = { "3", "3", "3", "1" "1", "1" };
	MinPokers[9] = { "8", "7", "6", "5", "4", "3", "1" };
	MinPokers[10] = { "9", "8", "7", "6", "5", "4", "3", "1"};
	MinPokers[11] = { "4", "3", "3", "3", "1" "1", "1", "5" };	
	MinPokers[12] = { "5", "5",  "4", "4", "3", "3", "1", "1" };
	MinPokers[13] = { "10", "9", "8", "7", "6", "5", "4", "3", "1" };
	MinPokers[14] = { "J", "10", "9", "8", "7", "6", "5", "4", "3", "1" };
	MinPokers[15] = { "4", "4", "3", "3", "3", "1" "1", "1", "5", "5" };
	MinPokers[16] = { "6", "6", "5", "5",  "4", "4", "3", "3", "1", "1" };
	MinPokers[17] = { "Q",  "J", "10", "9", "8", "7", "6", "5", "4", "3", "1" };
	MinPokers[18] = { "K", "Q",  "J", "10", "9", "8", "7", "6", "5", "4", "3", "1" };
	MinPokers[19] = { "7", "7", "6", "6", "5", "5",  "4", "4", "3", "3", "1", "1" };
	MinPokers[20] = { "A", "K", "Q",  "J", "10", "9", "8", "7", "6", "5", "4", "3", "1" };
}

void sort_the_pokers(shared_ptr<vector<string>> PokersNeedTobeSorted)
{
	//sort the pokers depend on Card Values
	vector<vector<string>> PokersOrders;
	PokersOrders.resize(16);

	vector<string> ReasonedOrders;
	for (int i = 0; i < 15; ++i)
		ReasonedOrders.push_back(CARD_VALUES[i]);
	for (auto i = (*PokersNeedTobeSorted).begin(); i < (*PokersNeedTobeSorted).end(); ++i)
	{
		//find the correspond position in the PokersOrders and insert it into the new vector
		int position = find(ReasonedOrders.begin(), ReasonedOrders.end(), *i) - ReasonedOrders.begin();
		PokersOrders[position].push_back(*i);
	}
	(*PokersNeedTobeSorted).clear();
	for (int i = 0; i < 15; ++i)
	{
		for (auto KindBegin = PokersOrders[i].begin(); KindBegin < PokersOrders[i].end(); ++KindBegin)
		{
			(*PokersNeedTobeSorted).push_back(*KindBegin);
		}
	}
}

vector<string> OriginOut(vector<string> PokersNneedToOut)
{
	int i = 1;
	//select random pokers to out
	for (; i < 21; ++i)
	{
		reverse(MinPokers[i].begin(), MinPokers[i].end());
		PokerAnalysis currentMin(MinPokers[i], MinPokers[i].size());
		MyPoker CurrentOrigin(PokersNneedToOut, PokersNneedToOut.size(), currentMin);
		if (!CurrentOrigin.MyOut.empty())
			return CurrentOrigin.MyOut;
	}
	//if doesn't find proper pokers, return the single poker
	vector<string> result;
	result.push_back(PokersNneedToOut[PokersNneedToOut.size() - 1]);
	return result;	
}

void Out_Display_Result(string Name, shared_ptr<vector<string>> CurrentPlayer, vector<string> OutPokers, vector<string>& GreatestPokers)
{
	//delete the Out pokers in CurrentPlayer
	for (int i = 0; i < (int)OutPokers.size(); ++i)
	{
		//delete OutPokers[i]
		auto DeletePosition = find(CurrentPlayer->begin(), CurrentPlayer->end(), OutPokers[i]);
		CurrentPlayer->erase(DeletePosition, DeletePosition + 1);
	}

	//print the out pokers
	cout << Name << " out: ";
	for (auto b = OutPokers.begin(); b < OutPokers.end(); ++b)
		cout << *b << " ";
	cout << endl;

	//print the remain pokers
	cout << Name << " remain: ";
	for (auto b = CurrentPlayer->begin(); b < CurrentPlayer->end(); ++b)
		cout << *b << " ";
	cout << endl;

	//assign the Greatest pokers
	GreatestPokers = OutPokers;
}