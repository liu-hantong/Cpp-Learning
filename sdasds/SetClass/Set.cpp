#include"Set.h"
int existed(const int elements[100], int length, int key) {
	//check if key exists in elements
	for (int i = 0; i < length; ++i)
		if (elements[i] == key)
			return i;
	return -1;
}

int notExisted(const int elements[100], int length, int key) {
	//check if key do not exist in elements
	for (int i = 0; i < length; ++i)
		if (elements[i] == key)
			return false;
	return true;
}

Set::Set(): length(0){  }

Set::Set(const Set &set) {
	for (int i = 0; i < set.length; ++i)
		this->elems[i] = set.elems[i];
	this->length = set.length; 
}

Set::Set(int elements[], int Length) {
	length = 0;
	for(int i = 0; i < Length; ++i)
		if (existed(elems, length, elements[i]) == -1) {
		this->elems[length++] = elements[i];
	}
}

Set::~Set() = default;

void Set::add(int element) { elems[length++] = element; }

bool Set::erase(int element) { 
	int pos = existed(this->elems, this->length, element);
	if (pos == -1) return false;
	for (int i = pos + 1; i < this->length; i++)
		elems[i - 1] = elems[i];
	this->length--;
	return true;
}

bool Set::contains(int element) {
	for (int i = 0; i < length; i++)
		if (element == elems[i])
			return true;
	return false;
}

int Set::size() { return length; }

std::ostream& operator<<(std::ostream &os, const Set &rset){
	if (rset.length == 0) {
		os << "Empty";
		return os;
	}                     
	int current[100];
	for (int i = 0; i < rset.length; ++i)
		current[i] = rset.elems[i];
	//use bubble sort to display the elements
	for (int i = 0; i < rset.length - 1; i++)
		for (int j = 0; j < rset.length - 1 - i; j++)
			if (current[j] > current[j + 1])
			{
				int temp = current[j];
				current[j] = current[j + 1];
				current[j + 1] = temp;
			}
	for(int i = 0; i < rset.length; ++i)
		os << current[i] << " ";                   
	return os;
}  

Set operator+(const Set &lset, const Set &rset) {
	Set res;
	res = lset | rset; 
	return res;
}

Set& Set::operator+=(const Set &rset) {
	*this = *this + rset;
	return *this;
}

Set operator-(const Set &lset, const Set &rset) {
	Set res;
	for (int i = 0; i < lset.length; i++)
		res.elems[i] = lset.elems[i];
	res.length = lset.length;
	for (int i = 0; i < rset.length; ++i) {
		int pos = existed(res.elems, res.length, rset.elems[i]);
		if (pos != -1) {
			//delete elems[pos]
			for (int i = pos + 1; i < res.length; ++i) {
				res.elems[i - 1] = res.elems[i];
			}
			res.length--;
		}
	}
	return res;
}

Set& Set::operator-=(const Set &rset) {
	*this = *this - rset;
	return *this;
}

Set operator&(const Set &lset, const Set &rset) {
	Set res;
	res.length = 0;
	for (int i = 0; i < lset.length; i++) {
		int pos = existed(rset.elems, rset.length, lset.elems[i]);
		if (pos != -1)
			res.elems[res.length++] = rset.elems[pos];
	}
	return res;
}

Set operator|(const Set &lset, const Set &rset) {
	Set res;
	res.length = lset.length;
	for (int i = 0; i < lset.length; ++i)
		res.elems[i] = lset.elems[i];
	for (int i = 0; i < rset.length; i++) {
		if (notExisted(res.elems, res.length, rset.elems[i]))
			res.elems[res.length++] = rset.elems[i];
	}
	return res;
}

bool operator==(const Set &lset, const Set &rset) {
	if (lset.length == rset.length) {
		int flag = 1;
		for (int i = 0; i < lset.length; ++i)
			if (existed(rset.elems, rset.length, lset.elems[i]) == -1)
				flag = 0;
		if (flag)
			return true;
	}
	return false;
}

bool operator!=(const Set &lset, const Set &rset) {
	return !(lset == rset);
}

bool operator>(const Set &lset, const Set &rset) {
	if (rset != lset) {
		//the basic condition
		for (int i = 0; i < rset.length; ++i)
			if (existed(lset.elems, lset.length, rset.elems[i]) == -1)
				return false;
	}
	return true;
}

bool operator>=(const Set &lset, const Set &rset) {
	for (int i = 0; i < rset.length; ++i)
		if (existed(lset.elems, lset.length, rset.elems[i]) == -1)
			return false;
	return true;
}

bool operator<(const Set &lset, const Set &rset) {
	return rset > lset;
}

bool operator<=(const Set &lset, const Set &rset) {
	return rset >= lset;
}


int main() {
	using namespace std;
	//test 1
	int elements[] = { -1, 2, 0, 3, -5, 3 }; 
	int length = sizeof(elements) / sizeof(int); 
	Set set(elements, length); 
	std::cout << set.size() << endl; 
	std::cout << set.contains(5) << endl;
	std::cout << set << endl;
	set.add(6);
	std::cout << set << endl; 
	std::cout << set.erase(0) << endl; 
	std::cout << set << endl;
	std::cout << set.erase(1) << endl; 
	std::cout << set << endl;
	//test 2
	//set1 contains -2,-1,0,1,2 
	//set2 contains 1,2,3,4,5 
	
	int e1[5] = { -2, -1, 0, 1, 2 };
	Set set1(e1, 5);
	int e2[5] = { 1, 2, 3, 4, 5 };
	Set set2(e2, 5);

	std::cout << set1 + set2<< endl;
	std::cout << set1-set2 << endl; 
	std::cout << (set1|set2) << endl;
	std::cout << (set1&set2) << endl;
	set1 += set2; 
	std::cout << set1 << endl;
	set1 -= set2; 
	std::cout << set1 << endl;
	
	//test3
	//set1 contains -2,-1,0,1,2
	//set2 contains 0,1,2
	//set3 is empty 
	int S1[] = { -2, -1, 0, 1, 2 };
	int S2[] = { 0, 1, 2 };
	Set Set1(S1, 5);
	Set Set2(S2, 3);
	Set Set3;
	std::cout << (Set1 == Set2) << endl; 
	std::cout << (Set1 != Set2) << endl; 
	std::cout << (Set1>Set2) << endl; 
	std::cout << (Set1 >= Set2) << endl; 
	std::cout << (Set1<Set2) << endl;
	std::cout << (Set1 <= Set2) << endl;
	std::cout << (Set1 > Set3) << endl;
	system("pause");
}