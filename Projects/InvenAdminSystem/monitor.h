#pragma once
#include"Admin.h"
#include"user.h"
using namespace std;
//设定管理员账号和密码
string AdminID = "Admin";
string AdminPassword = "admin";
string UserInfo_FilePath = "C:\\Users\\刘晗桐\\Desktop\\用户.txt";
string UserCart_FilePath = "C:\\Users\\刘晗桐\\Desktop\\";
class monitor {
private:
	int main_operation;    //主界面进行的操作
	string input_ID;       //用户临时输入的账号或密码
	string input_password;
public:
	monitor();                //创建一个主界面
    void Admin_check();
	void User_check();
	void User_register();     //注册新用户
	void register_interface();//登陆界面提示语
	void monitor_interface();
	bool user_ID_password_check();
};

monitor::monitor() {
	while (1) {
		monitor_interface();
		cout << "输入操作:"; cin >> main_operation;
		switch (main_operation) {
		case 1: User_check(); break;
		case 2: User_register(); break;
		case 3: Admin_check(); break;
		default: break;
		}
	}
}
void monitor::Admin_check() {
	monitor_interface();
	string input;
	cout << "输入管理员ID: ";
	cin >> input_ID;
	cout << "输入管理员密码: ";
	cin >> input_password;
	if (input_ID == AdminID && input_password == AdminPassword) {
		//进入管理员模式
		register_interface();
		Admin NewAdmin;
	}
}
void monitor::User_check() {
	monitor_interface();
	cout << "输入用户名: ";
	cin >> input_ID;
	cout << "输入管理员密码: ";
	cin >> input_password;
	if (user_ID_password_check()) {
		register_interface();
		user NewUser;
	}
	else {
		cout << "用户名或密码错误 按任意键返回" << endl;
		getchar(); getchar();
	}
}

void monitor::User_register() {
	monitor_interface();
	cout << "输入用户名: ";
	cin >> input_ID;
	cout << "输入管理员密码: ";
	cin >> input_password;
	if (!user_ID_password_check()) {
		//如果用户不存在
		ofstream UserInfo_File;
		UserInfo_File.open(UserInfo_FilePath, ios::app);
		string append = "\n" + input_ID + "\t" + input_password;
		UserInfo_File << append;
		//新建一个购物车文件
		ofstream UserCart_File;
		UserCart_File.open(UserCart_FilePath + input_ID + ".txt", ios::out);
		UserCart_File << "ID\t名称\t品牌\t价格\t数量";
		cout << "****************" << endl;
		cout << "注册成功并登陆成功  " << endl;
		cout << "****************" << endl;
		register_interface();
		user NewUser;
	}
	else {
		cout << "用户名已存在 按任意键返回" << endl;
		getchar(); getchar();
	}
}
bool  monitor::user_ID_password_check() {
	//判断用户名和密码的正确性
	ifstream UserInfo_File;
	string current;
	UserInfo_File.open(UserInfo_FilePath, ios::in);
	while (!UserInfo_File.eof()) {
		getline(UserInfo_File, current);
		if (current.substr(0, 5) == input_ID && current.substr(6, 13) == input_password)
			return true;
	}
	return false;
}

void monitor::monitor_interface() {
	system("cls");
	cout << "=======================================" << endl;
	cout << "1:用户登录   2:用户注册    3:管理员登陆 " << endl;
	cout << "=======================================" << endl;
}

void monitor::register_interface() {
	cout << "**************" << endl;
	cout << "   登陆成功 " << endl;
	cout << "**************" << endl;
}