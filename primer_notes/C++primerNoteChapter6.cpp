#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

//函数重载
void print(const string &);
void print(int);
void print(double);
int main() {
	/*



	//重复读入数据直到到达文件末尾
	int s;
	while (cin >> s && s != 1);



	//抛出异常
	//through表达式
	if (1 != 1)
		throw runtime_error("Data must be");


	//try语句块
	int a, int b;
	while (cin >> a >> b)
		try {
		//if fail to add
	}
	catch (runtime_error err) {
		cout << err.what() << "\nTry Again Eenter y or n" << endl;
		char c;
		cin >> c;
		}


	//cerr关键字
	if (1 == 1) {
		cout << "success" << endl;
		return 0;
	}
	else {
		cerr << "fail" << endl;
		return -1;
	}


	//initialized list 传入可变参数
	int sum(initializer_list<int> a)
	{
	int sum = 0;
	for (auto c : a)
	sum += c;
	return sum;
	}
	//C++11规定函数可以返回花括号包围的值的列表

	//
	void current(vector<int> a) 
	{
		if (!a.empty()) {
			auto b = a.end() - 1;
			cout << *b << endl;
			a.pop_back();
			current(a);
	}
	return;
	}
	//返回数组指针的函数声明
	int(*func(int i))[10];
	auto fun(int i) -> int(*)[10];
	auto funfun(int i)->string(*)[10];

	//使用内联函数以降低函数调用开销
	//优化规模较小, 流程直接, 频繁调用的函数
	inline const string &shorterString(const string &s1, const string &s2)
	{
		return s1.size() <= s2.size() ? s1 : s2;
	}

	//默认函数参数 的常用形式
	string screen(int a, int b, int c = 100);
	//变化值在前, 默认值在后

	
	//constexpr函数
	//返回类型和实参都是字面值 隐式定义为inline内联函数
	constexpr int initial() { return 42 ;}
	foo = initial(); //foo被定义为实参
	*/
	//把内联函数和constexpr函数放在头文件中
	
	
	//调试帮助 预处理宏
	//assert(expr)
	//当expr为假时输出信息并停止程序的执行
	
	//NDEBUG预处理变量
	//定义NDEBUG不会执行运行时检查
	//定义NDEBUG不会执行#ifdef和#endif之间的语句
	//#define NDEBUG
	

	system("pause");
}


