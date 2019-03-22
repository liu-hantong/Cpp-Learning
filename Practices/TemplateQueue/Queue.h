#pragma once
#include<iostream>
#include<string>
using namespace std;
template <typename T>
class Queue {
public:
	struct Node {
		T data;
		Node *next;
	};
	struct Que {
		Node *head;
		Node *tail;
		int size;
	};
	Que *Q;
public:
	Queue(); //constructor with parameters
	~Queue() = default;//destructor, delete all the elements and recycle the space
	void push(T e);//Element E is inserted into the queue and inserted at the end of the queue.
	T pop();//pop the head element
	T back();//return the last element of the queue
	T front();//return the first element of the queue
	bool isEmpty();//if the queue is empty, return true, otherwise, false 
	size_t size();//return the length of the queue
	void show();//display the queue elements, seperate the elements by space, add '\n'.
};