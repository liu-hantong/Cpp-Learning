#include<iostream>
#include"List.h"

int main() {
	//test 1
	using namespace std;
	List<int> l;
	List<int>::iterator it = l.begin();
	it = l.insert(it, 0); 
	it = l.insert(it, 1);
	it = l.insert(it, 2);
	++it;
	it = l.erase(it); 
	for (it = l.begin(); it != l.end(); it++) 
	{
		cout << *it << endl;
	}
	//test 2
	List<char> l2; 
	l2.insert(l2.end(), 'a');
	l2.insert(l2.end(), 'b');
	l2.insert(l2.end(), 'c');
	l2.insert(l2.end(), 'd'); 
	List<char>::iterator It = l2.erase(l2.begin());
	It = l2.erase(It); 
	for (; It != l2.end(); ++It) {
		cout << *It << endl; 
	}
	system("pause");
}