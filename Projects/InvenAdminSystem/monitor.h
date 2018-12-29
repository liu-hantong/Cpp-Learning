#pragma once
#include"Admin.h"
#include"user.h"
using namespace std;
//�趨����Ա�˺ź�����
string AdminID = "Admin";
string AdminPassword = "admin";
string UserInfo_FilePath = "C:\\Users\\����ͩ\\Desktop\\�û�.txt";
string UserCart_FilePath = "C:\\Users\\����ͩ\\Desktop\\";
class monitor {
private:
	int main_operation;    //��������еĲ���
	string input_ID;       //�û���ʱ������˺Ż�����
	string input_password;
public:
	monitor();                //����һ��������
    void Admin_check();
	void User_check();
	void User_register();     //ע�����û�
	void register_interface();//��½������ʾ��
	void monitor_interface();
	bool user_ID_password_check();
};

monitor::monitor() {
	while (1) {
		monitor_interface();
		cout << "�������:"; cin >> main_operation;
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
	cout << "�������ԱID: ";
	cin >> input_ID;
	cout << "�������Ա����: ";
	cin >> input_password;
	if (input_ID == AdminID && input_password == AdminPassword) {
		//�������Աģʽ
		register_interface();
		Admin NewAdmin;
	}
}
void monitor::User_check() {
	monitor_interface();
	cout << "�����û���: ";
	cin >> input_ID;
	cout << "�������Ա����: ";
	cin >> input_password;
	if (user_ID_password_check()) {
		register_interface();
		user NewUser;
	}
	else {
		cout << "�û������������ �����������" << endl;
		getchar(); getchar();
	}
}

void monitor::User_register() {
	monitor_interface();
	cout << "�����û���: ";
	cin >> input_ID;
	cout << "�������Ա����: ";
	cin >> input_password;
	if (!user_ID_password_check()) {
		//����û�������
		ofstream UserInfo_File;
		UserInfo_File.open(UserInfo_FilePath, ios::app);
		string append = "\n" + input_ID + "\t" + input_password;
		UserInfo_File << append;
		//�½�һ�����ﳵ�ļ�
		ofstream UserCart_File;
		UserCart_File.open(UserCart_FilePath + input_ID + ".txt", ios::out);
		UserCart_File << "ID\t����\tƷ��\t�۸�\t����";
		cout << "****************" << endl;
		cout << "ע��ɹ�����½�ɹ�  " << endl;
		cout << "****************" << endl;
		register_interface();
		user NewUser;
	}
	else {
		cout << "�û����Ѵ��� �����������" << endl;
		getchar(); getchar();
	}
}
bool  monitor::user_ID_password_check() {
	//�ж��û������������ȷ��
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
	cout << "1:�û���¼   2:�û�ע��    3:����Ա��½ " << endl;
	cout << "=======================================" << endl;
}

void monitor::register_interface() {
	cout << "**************" << endl;
	cout << "   ��½�ɹ� " << endl;
	cout << "**************" << endl;
}