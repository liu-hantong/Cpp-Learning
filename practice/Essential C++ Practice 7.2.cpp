#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef string elemType;
class Stack
{
public:
	~Stack() = default;
	virtual bool pop(elemType&) = 0;
	virtual bool push(const elemType&) = 0;
	virtual bool peek(int index, elemType&) = 0;

	virtual int top() const = 0;
	virtual int size() const = 0;

	virtual bool empty() const = 0;
	virtual bool  full() const = 0;
	virtual void print(ostream& = cout) const = 0;
};

ostream& operator<<(ostream &os, const Stack& rhs)
{
	rhs.print();
	return os;
}

class LIFO_Stack : public Stack
{
	//A typical class of Stack implementation
public:
	LIFO_Stack(int capacity = 0) : _top(0)
	{
		if (capacity)
			_stack.reserve(capacity);
	}

	int size() const { return _stack.size(); }
	bool empty() const { return !_top; }
	bool full() const { return size() >= _stack.max_size(); }
	int top() const { return _top; }
	void print(ostream &os = cout) const;

	bool pop(elemType &elem);
	bool push(const elemType &elem); 
	bool peek(int, elemType&) { return false; }

private:
	vector<elemType> _stack;
	int _top;
};

//in order to catch the exception anywhere inside the program
//we have to involve the ExceptionCatchClass inside the standard lib;
class StackException : public logic_error {
	//this class is used to control all the exceptions of a specific class
public:
	StackException(string what) : _what(what), logic_error(what) {}
	const char *what() const{ return _what.c_str(); }
protected:
	string _what;
};

class PopOnEmpty : public StackException{
public:
	PopOnEmpty() : StackException("Pop on empty Stack") {};
};

class PushOnFull : public StackException{
public:
	PushOnFull() : StackException("Puch on full Stack") {};
};


bool LIFO_Stack::pop(elemType& elem)
{
	//demon the exception
	if (empty()) throw PopOnEmpty();
	elem = _stack[--_top];
	_stack.pop_back();
	return true;
}

bool LIFO_Stack::push(const elemType& elem)
{
	if (!full())
	{
		_stack.push_back(elem);
		++_top;
		return true;
	}
	//to demon the exception
	throw PushOnFull();
}

void LIFO_Stack::print(ostream& os) const
{
	vector<elemType>::const_reverse_iterator rit = _stack.rbegin(), rend = _stack.rend();
	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";
	os << endl;
}


class Peekback_Stack : public Stack
{
	//A typical class of Stack implementation
public:
	Peekback_Stack(int capacity = 0) : _top(0)
	{
		if (capacity)
			_stack.reserve(capacity);
	}

	int size() const { return _stack.size(); }
	bool empty() const { return !_top; }
	bool full() const { return size() >= _stack.max_size(); }
	int top() const { return _top; }
	void print(ostream &os = cout) const;

	bool pop(elemType &elem);
	bool push(const elemType &elem);
	bool peek(int, elemType&);

private:
	vector<elemType> _stack;
	int _top;
};

bool Peekback_Stack::pop(elemType& elem)
{
	if (empty()) return false;
	elem = _stack[--_top];
	_stack.pop_back();
	return true;
}

bool Peekback_Stack::push(const elemType& elem)
{
	if (full()) return false;
	_stack.push_back(elem);
	++_top;
	return true;
}

void Peekback_Stack::print(ostream& os) const
{
	vector<elemType>::const_reverse_iterator rit = _stack.rbegin(), rend = _stack.rend();
	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";
	os << endl;
}

bool Peekback_Stack::peek(int index, elemType& elem){
	if (empty()) return false;
	if (index < 0 || index >= size()) return false;
	
	elem = _stack[index];
	return true;
}

//A simple program to demonstrate the functions of the Stacks above

void peek(Stack &st, int index)
{
	cout << endl;
	string t;
	if (st.peek(index, t))
		cout << "peek: " << t;
	else
		cout << "Peek failed!";
	cout << endl;
} 

int main()
{
	LIFO_Stack st;
	string str;
	while (cin >> str && st.size() <= 3)
		st.push(str);
    //test Peekback_Stack
	Peekback_Stack pst;
	while (!st.empty())
	{
		string t;
		if (st.pop(t))
			pst.push(t);
	}
	cout << "About to call peek() with Peekback_Stack" << endl;
	peek(pst, pst.top() - 1);
	cout << pst;
	
	//Test the exception test
	try{
		LIFO_Stack st2;
		st2.pop(str);
	}
	catch (const PopOnEmpty &pof)
	{
		cerr << pof.what() << endl;
	}
	system("pause");
}
