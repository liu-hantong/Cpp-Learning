#include<iostream>
#include<vector>
#include<memory>

//e.g. 12.1
//This is a class that is an example of how shared_ptr works internal
//This class can be used to explain the technique of shared_ptr

class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> i1);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	std::string& front();
	std::string& back();
	const std::string& front () const;
	const std::string& back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	//if data[i] is not legal
	void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>(0)) {}
StrBlob::StrBlob(std::initializer_list<std::string> i1) : data(std::make_shared<std::vector<std::string>>(i1)) {}
void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw msg;

}
std::string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::front () const {
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}


std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}


