#pragma once
#include<iostream>
using namespace std;
struct stackNode
{
	char data; //data of the stack
	stackNode *next; //point to the next data
};
class Stack
{
private:
	stackNode * top; //top of stack
public:
	Stack();//constructor without parameters, top is initialized as NULL
	~Stack();//destructor, clear the data in the stack
	void push(char data); //push operation
	char pop(); //pop operation
	char stackTop(); // get top element of the stack
	bool isEmpty(); //determines whether the stack is empty
	void show(); //display the elements in this stack, don't output anything when the stack is empty.
};

