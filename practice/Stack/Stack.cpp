#include "Stack.h"

Stack::Stack() : top(NULL) {}

void Stack::push(char data) {
	stackNode *current = new stackNode;
	current->data = data;
	current->next = top;
	top = current;
}

char Stack::pop() {
	stackNode *current = top;
	top = top->next;
	char Top = current->data;
	delete(current);
	return Top;
}

char Stack::stackTop() {
	if (top) 
		return top->data;
}

bool Stack::isEmpty() { if (top == NULL) return true; else return false; }

void Stack::show() {
	if (!top) return;
	else {
		stackNode *current = top;
		while (current) {
			cout << current->data << endl;
			current = current->next;
		}
	}
}

Stack::~Stack() = default;
/*{
	stackNode *current = top;
	while (current) {
		stackNode *Delete = current;
		current = current->next;
		delete(Delete);
	}
	top = NULL;
}
*/
