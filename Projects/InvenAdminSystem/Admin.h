#pragma once
#include"include.h"
using namespace std;
class Admin {
private:
	int option;           //管理员界面操作选项
	int total_inventory;  //仓库中的商品数量
	string current;
	string file;
	string admin_lace;    //管理员界面花边
	string commodity_lace;//商品处理界面花边
	string inventory[100];//仓库清单
	fstream info_out;     //仓库文件流
	void search();        //查询商品
	void add();           //增加商品    
	bool exist(string  A[], string B, int &exist_position);
	void deelete(string in, string current);
	void add_delete_modify(int operation);
	void admin_interface();
	void display_list();
public:
	Admin();
};
Admin::Admin() {
	//主管理函数
	commodity_lace = "*******************************************";
	file = "";
	current = "";
	while (1) {
		admin_interface();
		cout << "输入操作:";
		cin >> option;
		switch (option)
		{
		case 0: break;
		case 1: search(); //查询商品信息
		case 2: case 3: case 4: add_delete_modify(option); break;   //增加删除修改商品 
		case 5: display_list();
		default:
			break;
		}
		if (!option) break;
	}
}
void Admin::search() {
	//查询商品信息
	ifstream info;
	info.open(inventory_path, ios::in);
	if (!info) cout << "ERROR" << endl;
	while (!info.eof())
	{
		getline(info, current);
		if (!current.empty())
			file.append(current + "\n");
	}
	cout << commodity_lace << endl;  cout << file; cout << commodity_lace << endl;
	file = "";
	current = "";
	info.close();
	cout << "按任意键返回上一级菜单" << endl;
	getchar(); getchar();
}

void Admin::add_delete_modify(int operation) {
	//增加商品
	admin_interface();
	info_out.open(inventory_path, ios::out | ios::app | ios::in);
	int i = 0; //用以标志清单编号
	while (!info_out.eof())
	{
		getline(info_out, current);
		if (!current.empty())
			inventory[i++] = current;
	}
	current = "";
	total_inventory = i - 1;
	info_out.close();
	switch (operation)
	{
	case 2: add(); break;
	case 3: {
		//删除商品, 即修改商品数量为-1
		string in;
		cout << "名称:";
		cin >> in;
		current.append("0\t" + in);
		cout << "品牌:";
		cin >> in;
		current.append("\t" + in + "\t");
		deelete("-1", current);
		break;
	}
	case 4: {
		//改变商品数量, 即修改商品数量为in
		string in;
		cout << "名称:";
		cin >> in;
		current.append("0\t" + in);
		cout << "品牌:";
		cin >> in;
		current.append("\t" + in + "\t");
		cout << "数量:";
		cin >> in;
		deelete(in, current);
		break; }
	default:
		break;
	};
}

bool Admin::exist(string all[], string key, int &exist_position) {
	//判断key所表示的商品是否在清单all中, 如存在则返回其位置
	string key_name = "";
	string key_brand = "";
	char key_char[2]; key_char[1] = '\0';
	int mark = 0;
	for (int i = 0; i < key.length(); i++) {
		//将key中的名称和品牌转化为字符串
		if (mark == 3) break;
		if (key[i] == '\t') {
			mark++; continue;
		}
		if (mark == 1) {
			key_char[0] = key[i];
			key_name.append(key_char);
		}
		else if (mark == 2) {
			key_char[0] = key[i];
			key_brand.append(key_char);
		}
	}
	for (int i = 1; i <= total_inventory; i++)
	{
		mark = 0;
		string inventory_name = "";
		string inventory_brand = "";
		for (int commodity_position = 0; mark != 3; commodity_position++)
		{
			//将inventory中的名称和商标转化为两个字符串
			if (all[i][commodity_position] == '\t') { mark++; continue; }
			if (mark == 1) {
				key_char[0] = all[i][commodity_position];
				inventory_name.append(key_char);
			}
			else if (mark == 2) {
				key_char[0] = all[i][commodity_position];
				inventory_brand.append(key_char);
			}
		}
		//将key与inventory已有的name与brand进行比较
		if (inventory_name == key_name && key_brand == inventory_brand)
		{
			exist_position = i;
			return existed;
		}
	}
	return non_existed;
}

void Admin::add() {
	//添加商品条目
	//记录商品编号
	int number_newcommodity = total_inventory;
	string string_number_newcommodity = "";
	stringstream Stringstream;
	Stringstream << number_newcommodity;
	Stringstream >> string_number_newcommodity;
	char zero[2] = { '0', '\0' };
	while (string_number_newcommodity.length() != 4)
		string_number_newcommodity = zero + string_number_newcommodity;
	current.append("\nF" + string_number_newcommodity + '\t');
	//记录新商品元素
	string in = "";
	cout << "名称:"; cin >> in;
	current.append(in + '\t');
	cout << "品牌:"; cin >> in;
	current.append(in + '\t');
	int exist_position;
	if (exist(inventory, current, exist_position)) {
		//若商品已存在, 则修改商品数量
		cout << "该商品已存在, 请输入更改后的数量:";
		cin >> in;
		//更改文件中的数量值
		deelete(in, current);
	}
	else {
		//商品不存在
		cout << "价格:"; cin >> in;
		current.append(in + '\t');
		cout << "数量:"; cin >> in;
		current.append(in);
		info_out.open(inventory_path, ios::out | ios::in | ios::app);
		info_out << current;
	}
	info_out.close();
}

void Admin::deelete(string in, string current) {
	//将current中所记录的商品数量在仓库中修改为in
	int exist_position;
	exist(inventory, current, exist_position);
	int mark = 0, i = 0;
	for (; mark != 4; i++)
		if (inventory[exist_position][i] == '\t') mark++;
	inventory[exist_position].replace(i, inventory[exist_position].length() - 1, in);
	info_out.open(inventory_path, ios::out | ios::in);
	for (int i = 0; i <= total_inventory; i++)
		info_out << inventory[i] << endl << endl;
	info_out.close();
	admin_interface();
}
void Admin::admin_interface() {
	//显示管理者界面
	admin_lace = "===============================================================================";
	system("cls");
	cout << admin_lace << endl;
	cout << "0.注销登陆   1.查询商品   2.增加商品   3.删除商品   4.修改商品数量   5.收货清单" << endl;
	cout << admin_lace << endl;
}

void Admin::display_list() {
	//展示售出清单
	string list[10][6];
	char _list[2]; //用于current中的字符转移
	_list[1] = '\0';
	int list_index = 0;
	ifstream info_out;
	info_out.open(list_path, ios::in);
	while (!info_out.eof()) {
		getline(info_out, current);
		if (!current.empty()) {
			//将current中的内容分段存在list中
			int i = 0; // 标志元素顺序
			for (int cur = 0; current[cur] != '\0'; cur++) {
				if (current[cur] == '\t') {
					i++;
				}
				else {
					_list[0] = current[cur];
					list[list_index][i].append(_list);
				}
			}
			list_index++;
		}
	}
	//使用选择排序根据商品号排序
	string exchange;
	for (int i = list_index - 1; i > 1; i--)
		for (int m = 1; m < i; m++) {
			if (list[m][0][4] >= list[m + 1][0][4]) {
				//交换两个信息行
				for (int exchange_mark = 0; exchange_mark <= 5; exchange_mark++) {
					exchange = list[m][exchange_mark];
					list[m][exchange_mark] = list[m + 1][exchange_mark];
					list[m + 1][exchange_mark] = exchange;
				}
			}
		}
	//再根据商品号和价格进行组合
	bool flag[100] = { 0 };//标志已经被叠加的商品行
	for (int i = 1; i < list_index - 1; i++) {
		if (!flag[i]) {
			for (int m = i + 1; m <= list_index - 1; m++) {
				if (!flag[m]) {
					if (list[i][0] == list[m][0] && list[i][3] == list[m][3]) {
						//将商品量叠加
						flag[m] = 1;
						int New_Number = atoi(list[i][4].c_str()) + atoi(list[m][4].c_str());
						char middle[10];
						_itoa_s(New_Number, middle, 10);
						string Middle(&middle[0], &middle[strlen(middle)]);
						list[i][4] = Middle;
					}
				}
			}
		}
	}
	//打印
	cout << "**********************************************" << endl;
	for (int i = 0; i <= list_index - 1; i++) {
		if (!flag[i]) {
			for (int m = 0; m <= 5; m++)
				cout << list[i][m] << '\t';
			cout << endl;
		}
	}
	cout << "**********************************************" << endl;
	cout << "按任意键返回上一级菜单" << endl;
	getchar(); getchar();

}