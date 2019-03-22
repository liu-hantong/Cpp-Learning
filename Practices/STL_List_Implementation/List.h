#pragma once
template <class T>
struct _List_node {
	_List_node<T>* prev;//precursor node
	_List_node<T>* next;//successor node
	T data;//data
};

template<class T>
struct _List_iterator {
	//iterator for List
	_List_node<T>* _p_node;
	_List_iterator(_List_node<T>* x) : _p_node(x) {};//constructor
	_List_iterator() = default;//default constructor
	template <typename T> friend bool operator==(const _List_iterator&, const _List_iterator&);//reload ==
	template <typename T> friend bool operator!=(const _List_iterator&, const _List_iterator&);//reload !=
	_List_iterator operator++();//reload ++
	_List_iterator operator++(int);//reload ++
	_List_iterator operator--();//reload --
	_List_iterator operator--(int);//reload --
	T operator*();//reload --
};

template <class T>
bool operator==(const _List_iterator<T>& L1, const _List_iterator<T>& L2) {
	return L1._p_node == L2._p_node;
}

template <class T>
bool operator!=(const _List_iterator<T>& L1, const _List_iterator<T>& L2) {
	return L1._p_node != L2._p_node;
}

template<class T>
_List_iterator<T> _List_iterator<T>::operator++() {
	this->_p_node = this->_p_node->next;
	return *this;
}

template<class T>
_List_iterator<T> _List_iterator<T>::operator++(int) {
	_List_iterator<T> current(this->_p_node);
	_p_node = _p_node->next;
	return current;
}

template<class T>
_List_iterator<T> _List_iterator<T>::operator--() {
	--this->_p_node;
	return *this;
}

template<class T>
_List_iterator<T> _List_iterator<T>::operator--(int) {
	_List_iterator<T> current(this->_p_node);
	--this->_p_node;
	return current;
}

template<class T>
T _List_iterator<T>::operator*() {
	return this->_p_node->data;
}

template <class T>
class List {
public:
	typedef _List_node<T> link_type;
	typedef _List_iterator<T> iterator;
	List();//initialize List, apply for entry node space
	~List() = default;//recycle all node spaces, including entry node
	bool empty();//whether empty, true if it is, false if it isn't
	iterator begin();//return the iterator of first element
	iterator end();//return the position after the last element
	iterator insert(iterator it, T e);//insert an element before it, return the iterator pointed to the insert element
	iterator erase(iterator it);//delete the element that it points to, return the the next iterator
private:
	link_type *node;//list entry
};

template <class T>
List<T>::List() { 
	//allocate space for new node, and the entry node points to itself
	node = new _List_node<T>; 
	node->next = node, node->prev = node;
	node->data = 0;
}

template <class T>
typename List<T>::iterator List<T>::begin() {
	iterator res(node->next);
	return res;
}

template <class T>
typename List<T>::iterator List<T>::end() {
	iterator res(node);
	return res;
}

template <class T>
bool List<T>::empty() {
	return node = node->next;
}

template <class T>
typename List<T>::iterator List<T>::insert(List<T>::iterator it, T e) {
	link_type *temp = new _List_node<T>;
	temp->data = e;
	//ajust the pointer to insert the new node
	temp->next = it._p_node;
	temp->prev = it._p_node->prev;

	it._p_node->prev->next = temp;
	it._p_node->prev = temp;

	return temp;
}

template <class T>
typename List<T>::iterator List<T>::erase(List<T>::iterator it) {
	iterator current = it;
	iterator res = it._p_node->next;
	//to adjust the direction of pre and next iterator
	it._p_node->prev->next = it._p_node->next;
	it._p_node->next->prev = it._p_node->prev;
	delete current._p_node;
	return res;
}