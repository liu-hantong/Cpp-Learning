#include<iostream>
#include"PokerAnalysis.h"
#include"MyPoker.h"

void WhatsTheResult(vector<string> Out)
{
	//print out the result
	if (Out.empty())
		cout << "Yao Bu Qi";
	else
	{
		for (auto front = Out.begin(); front != Out.end(); ++front)
			cout << *front << " ";
	}
	cout << endl;
}

int main()
{
	int MyNumber, EnemyNumber;                    //mark the number of pokers
	std::string CurrentPoker;
	std::vector<std::string> MyPoker, EnemyPoker; //mark the pokers
	
	//collect my pokers to play
	for (int i = 0; i < MyNumber; ++i)            
	{
		std::cin >> CurrentPoker;
		MyPoker.push_back(CurrentPoker);
	}
	
	//collect enemy pokers to confront
	cin >> EnemyNumber;
	for (int i = 0; i < EnemyNumber; i++)         
	{
		std::cin >> CurrentPoker;
		EnemyPoker.push_back(CurrentPoker);
	}

	//determine the nature of pokers
	PokerAnalysis YouOutThese(EnemyPoker, EnemyNumber);   
	cout << YouOutThese.CardsNature << endl;
	
	//find a solution
	MyPoker IHaveThese(MyPoker, MyNumber, YouOutThese);   
	WhatsTheResult(IHaveThese.MyOut);
	
	system("pause");
}

