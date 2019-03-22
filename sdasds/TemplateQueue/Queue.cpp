#include"Queue.h"
template <typename T>
Queue<T>::Queue() {
	Q = new Que;
	Q->head = Q->tail = NULL;
	Q->size = 0;
}

template <typename T>
void Queue<T>::push(T e) {
	//push a element into a queue
	Node *insert = new Node;
	insert->data = e;
	insert->next = Q->tail;
	if (Q->size == 0) {
		Q->head = Q->tail = insert;
		Q->head->next = NULL;
	}
	else
		Q->tail = insert;
	Q->size++;
}

template <typename T>
T Queue<T>::pop() {
	Node *out = new Node;
	out = Q->tail;
	if (Q->size == 0) {
		cout << "No element to be popped" << endl;
		system("pause");
		exit(1);
	}
	if (Q->size == 1) {
		//If there is only one element
		T Pop = out->data;
		delete Q->head;
		delete Q->tail;
		Q->head = Q->tail = NULL;
		Q->size = 0;
		return Pop;
	}
	if (Q->size == 2) {
		//if there are two elements
		T Pop = out->next->data;
		delete Q->head;
		Q->head = Q->tail;
		Q->size--;
		return Pop;
	}
	while (out->next->next)
		//if the size is over 2 elements
		out = out->next;
	T Pop = out->next->data;
	out->next = NULL;
	Q->head = out;
	Q->size--;
	if (Q->size == 1) Q->head = Q->tail;
	return Pop;
}
template <typename T>
T Queue<T>::back() {
	if (!Q->tail) {
		cout << "There are no elements to return" << endl;
		system("pause");
		exit(1);
	}
	return Q->tail->data;
}

template <typename T>
T Queue<T>::front() {
	if (!Q->head) {
		cout << "There are no elements to return" << endl;
		system("pause");
		exit(1);
	}
	return Q->head->data;
}

template <typename T>
bool Queue<T>::isEmpty() {
	if (!Q->size)
		return true;
	else
		return false;
}

template <typename T>
size_t Queue<T>::size() {
	return Q->size;
}

template <typename T>
void Queue<T>::show() {
	if (Q->size == 0) {
		cout << "There are no elements to display" << endl;
		return;
	}
	else {
		Node *cur = Q->tail;
		while (cur) {
			cout << cur->data << endl;
			cur = cur->next;
		}
	}
}




/*test main function*/
int main() {
	Queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.pop();
	q1.show();
	Queue<string> q2;
	q2.push("test");
	q2.push("queue");
	q2.push("template");
	cout << q2.front() << endl;
	q2.pop();
	q2.show();
	system("pause");
}