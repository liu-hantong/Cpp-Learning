#include<iostream>
#include"PokerAnalysis.h"
#include"MyPoker.h"

void WhatsTheResult(vector<string> Out)
{
	reverse(Out.begin(), Out.end());
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
	std::vector<std::string> MyPokers, EnemyPoker; //mark the pokers
	cin >> MyNumber >> EnemyNumber;

	//collect my pokers to play
	for (int i = 0; i < MyNumber; ++i)            
	{
		std::cin >> CurrentPoker;
		MyPokers.push_back(CurrentPoker);
	}
	
	//collect enemy pokers to confront
	for (int i = 0; i < EnemyNumber; i++)         
	{
		std::cin >> CurrentPoker;
		EnemyPoker.push_back(CurrentPoker);
	}
	//reverse the pokers to follow order
	reverse(EnemyPoker.begin(), EnemyPoker.end());

	//determine the nature of pokers
	PokerAnalysis YouOutThese(EnemyPoker, EnemyNumber);   
	
	//find a solution
	MyPoker IHaveThese(MyPokers, MyNumber, YouOutThese);   
	WhatsTheResult(IHaveThese.MyOut);
	
	system("pause");
}

