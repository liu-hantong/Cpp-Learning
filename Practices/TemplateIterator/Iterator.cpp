#include"Iterator.h"

template <typename T>
Iterator<T> operator+(const Iterator<T>& left, const size_t& right) {
	Iterator<T> res(left.ptr);
	res.ptr += right;
	return res;
}

template <typename T>
Iterator<T> operator-(const Iterator<T>& left, const size_t& right) {
	Iterator<T> res(left.ptr);
	res.ptr -= right;
	return res;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
	this->ptr++;
	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--() {
	this->ptr--;
	return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
	Iterator<T> form(this->ptr);
	this->ptr++;
	return form;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int) {
	Iterator<T> form(this->ptr);
	this->ptr--;
	return form;
}

template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& right) {
	Iterator<T> cur(right.ptr);
	return cur;
}

template <typename T>
bool operator==(const Iterator<T>& left, const Iterator<T>& right) {
	return (left.ptr == right.ptr);
}

template <typename T>
bool operator!=(const Iterator<T>& left, const Iterator<T>& right) {
	return (left.ptr != right.ptr);
}

template <typename T>
T Iterator<T>::operator*() {
	return *(this->ptr);
}

//test main function
int main() {
	int int_array[4] = { 1, 2, 3, 4 };
	Iterator<int> i_begin(int_array);
	Iterator<int> i_end(int_array + 4);
	for (Iterator<int> i = i_begin; i != i_end; i++)
		cout << *i << endl;
	string string_array[2] = { "world", "hello " };
	Iterator<string> s_begin(string_array);
	Iterator<string> s_end(string_array + 2);
	for (Iterator<string> i = s_end - 1; i != s_begin; --i)
		cout << *i << endl; 
	system("pause");
}