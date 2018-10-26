#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<string>
#include<numeric>
using namespace std;
int main() {
	//Pr 10.1 10.2
	/*
	vector<int> a;
	list<string> b;
	int input1;
	string input2;
	while (cin >> input1)
		a.push_back(input1);
	cout << count(a.begin(), a.end(), 10) << endl;
	while (cin >> input2)
		b.push_back(input2);
	cout << count(b.begin(), b.end(), "haha") << endl;
	system("pause");
	return 0;
	*/
	//Pra 10.3
	/*
	vector<int> a(10, 2);
	cout << accumulate(a.cbegin(), a.cend(), 0) << endl;
	*/
	//Pra 10.6
	/*
	vector<int> a(10, 42);
	for (int b : a)
		cout << b << " ";
	cout << endl;
	fill_n(a.begin(), a.size(), (int)0);
	for (int b : a)
		cout << b << " ";
	cout << endl;
	*/
	//Pra 10.9
	/*
	vector<string> a;
	string input;
	while (cin >> input)
		a.push_back(input);
	sort(a.begin(), a.end());
	auto unique_a = unique(a.begin(), a.end());
	a.erase(unique_a, a.end());
	for (auto c : a)
		cout << c << " " << endl;
	system("pause");
	*/
	//Pra 10.13
	/*
	bool isFive(const string &s1);
	string a;
	vector<string> b;
	vector<string>::iterator bound;
	while (cin >> a)
		b.push_back(a);
	bound = partition(b.begin(), b.end(), isFive);
	for (auto d = b.begin(); d != bound; ++d)
		cout << *d << " ";
	cout << endl;
	for (auto d = bound; d != b.end(); ++d)
		cout << *d << " ";
	cout << endl;
	system("pause");
	*/
	//Pra 10.14.15.16
	/*
	auto add = [](int lhs, int rhs) { return lhs + rhs; };
	int i = 42;
	auto add = [i](int num) { return i + num; };
	*/
	//Pra 10.20.21
	/*
	vector<int> a = { 1, 23, 23, 13, 12, 31, 323, 4,45 };
	cout << count_if(a.cbegin(), a.cend(), [](const int& b) {return b < 5; }) << endl;
	system("pause");
	int a = 10;
	auto Lam = [a]() mutable -> bool{while (a != 0) a--; return a == 0 ? true : false; };
	*/
	//Pra 
	
}
//Pra 10.16
/*
void elimpDups(vector<string> &words) {
	//alphabetically sort the words
	//remove duplicates
	sort(words.begin(), words.end());
	auto bound = unique(words.begin(), words.end());
	words.erase(bound, words.end());
}
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;//add 's' while ctr > 1
}
void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimpDups(words);
	//sort words by size, maintain alphabetical order for words of the same size
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });
	//get an iterator to the first element whose size() is >= sz
	auto wc = find_if(words.begin(), words.end(), [sz](const string& a) {return a.size() >= sz; });
	//compute the number of of elements with size >= sz
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "words", "s") << "of length" << sz << " or longer" << endl;
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}
*/
//Pra 10.13
/*
bool isFive(const string &s1) {
	return s1.size() >= 5;
}
*/