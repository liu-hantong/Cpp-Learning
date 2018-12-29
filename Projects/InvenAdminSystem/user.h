#pragma once
#include"include.h"
#include"Admin.h"

void tap_return() {
	cout << endl << "按任意键返回或继续" << endl;
	getchar(); getchar();
}

class user {
private:
	int option;//用户模式下输入的操作
	int inventory_index;
	int cart_index;
	char chartostring[2];
	string user_inventory[20][5]; //保存仓库信息
	string user_cart[20][5]; //保存用户购物车信息
	string inventory_cart_lace;
	string current;
	fstream inventory;
	fstream cart;
	void user_interface();
public:
	user(string user);
	void user_inventory_download();
	void user_cart_download();
	void user_check_inventory();//查看商品
	void user_Search();//商品搜索
	void user_Add(string user);//添加商品至购物车
	void user_Delete(string user);//删除购物车商品
	void user_check_cart();//查看购物车
	void user_pay(string user);//结账
	void array_to_file(string filepath, int index, string[20][5]);//更新库存或购物车文件
	void inputID_invalid(string input_ID);//输入的商品名无效
	void clear_array(string array[20][5], int index);//初始化数组
};
user::user(string user) {
	inventory_cart_lace = "**************************************";
	chartostring[1] = '\0';
	while (1) {
		//初始化
		for (int i = 0; i < inventory_index; i++)
			for (int m = 0; m < 5; m++) {
				user_inventory[i][m].clear();
				user_cart[i][m].clear();
			}
		inventory_index = 0;
		cart_index = 0;
		inventory.open(inventory_path, ios::in );
		cart.open(UserCart_FilePath + user + ".txt", ios::in );
		user_inventory_download();
		user_cart_download();
		user_interface();
		cout << "输入操作: ";
		cin >> option;
		switch (option)
		{
		case 1: break; //注销登陆
		case 2: user_check_inventory(); break; //查看商品
		case 3: user_Search(); break; //商品搜索
		case 4: user_Add(user); break; //添加商品至购物车
		case 5: user_Delete(user);  break; //删除购物车商品
		case 6: user_check_cart(); ; tap_return();  break; //查看购物车
		case 7: user_pay(user);  break; //结账
		default:
			break;
		}
		if (! ( option - 1 )) break;	
		inventory.close();
		cart.close();
	}
}

void user::user_inventory_download() {
	//将仓库文件内容保存于数组中
	while (!inventory.eof()) {
		getline(inventory, current);
		if (!current.empty()) {
			//将current中的内容分段存在user_inventory中
			int i = 0; // 标志元素顺序
			for (int cur = 0; current[cur] != '\0'; cur++) {
				if (current[cur] == '\t') {
					i++;
				}
				else {
					chartostring[0] = current[cur];
					user_inventory[inventory_index][i].append(chartostring);
				}
			}
			inventory_index++;
		}
	}	
}
void user::user_cart_download() {
	//将购物车文件内容保存于数组中
	while (!cart.eof()) {
		getline(cart, current);
		if (!current.empty()) {
			//将current中的内容分段存在user_inventory中
			int i = 0; // 标志元素顺序
			for (int cur = 0; current[cur] != '\0'; cur++) {
				if (current[cur] == '\t') {
					i++;
				}
				else {
					chartostring[0] = current[cur];
					user_cart[cart_index][i].append(chartostring);
				}
			}
			cart_index++;
		}
	}
}

void user::user_check_inventory() {
	//用户查看商品
	cout << endl << inventory_cart_lace << endl;
	for (int i = 0; i < inventory_index; i++) {
		if (user_inventory[i][4] != "0") {
			for (int m = 0; m < 5; m++)
				cout << user_inventory[i][m] << '\t';
			cout << endl;
		}
	}
	cout << inventory_cart_lace << endl;
	tap_return();
}

void user::user_Search() {
	//查找需要的商品信息
	cout << "输入商品名称: ";
	cin >> current;
	cout << endl << inventory_cart_lace << endl;
	for (int i = 0; i < inventory_index; i++) {
		if (i == 0 || user_inventory[i][1] == current) {
			for (int m = 0; m < 5; m++) {
				cout << user_inventory[i][m] << '\t';
			}
			cout << endl;
		}
	}
	cout << inventory_cart_lace << endl;
	tap_return();
}
void user::user_Add(string user) {
	//添加商品到购物车
	string input_ID;
	string input_Num;
	cout << "输入商品ID和数量: ";
	cin >> input_ID >> input_Num;
	int p;
	for (p = 1; p < inventory_index; p++) {
		if (user_inventory[p][0] == input_ID) {
			if (atoi(user_inventory[p][4].c_str()) < atoi(input_Num.c_str())) {
				cout << "库存数量不足, 无法添加" << endl;
				tap_return();
				break;
			}
			else {
				//库存数量充足, 可以添加
				int flag = 0;
				for (int cat = 1; cat < cart_index; cat++)
					if (user_cart[cat][0] == input_ID)
						flag = cat;
				if (!flag) {
					//如果购物车中原先没有
					for (int add_index = 0; add_index < 4; add_index++)
						user_cart[cart_index][add_index] = user_inventory[p][add_index];
					user_cart[cart_index][4] = input_Num;
					cart_index++;
				}
				else {
					//购物车中已经存在该商品 修改商品数量
					char new_number[10];
					_itoa_s(atoi(user_cart[flag][4].c_str()) + atoi(input_Num.c_str()), new_number, 10);
					user_cart[flag][4].clear(); user_cart[flag][4].append(new_number);
				}
				//将更改后的购物车重新写入文件
				array_to_file(UserCart_FilePath + user + ".txt", cart_index, user_cart);
				cout << endl << "***************" << endl;
				cout << "已经加入购物车!" << endl;
				cout << "***************" << endl;
				user_check_cart();
				tap_return();
				break;
			}
		}
	}
	if (p == inventory_index)
		inputID_invalid(input_ID);
}

void user::user_Delete(string user) {
	//删除购物车中的商品
	string input_ID;
	string input_Num;
	cout << "输入商品ID和数量: ";
	cin >> input_ID >> input_Num;
	int search_to_delete;
	for (search_to_delete = 1; search_to_delete < cart_index; search_to_delete++) {
		//寻找输入ID的下标
		if (user_cart[search_to_delete][0] == input_ID) {
			//字符串转数字
			int after_delete = atoi(user_cart[search_to_delete][4].c_str()) - atoi(input_Num.c_str());
			if (after_delete < 0) {
				cout << endl << "*************************" << endl;
				cout << "亲, 超出购物车中原有数量" << endl;
				cout << "*************************" << endl;
				tap_return();
				break;
			}
			else if (after_delete == 0)
				//数量清零, 删除商品
				user_cart[search_to_delete][0].clear();
			else {
				//数量大于零, 保持原样
				//数组转字符串
				char Current[10];
				_itoa_s(after_delete, Current, 10);
				user_cart[search_to_delete][4].clear(); user_cart[search_to_delete][4].append(Current);
			}
			//将删除后的数组写入购物车文件中
			array_to_file(UserCart_FilePath + user + ".txt", cart_index, user_cart);
			cout << endl << "**********" << endl;
			cout << "删除成功!" << endl;
			cout << "**********" << endl;
			user_check_cart();
			tap_return();
			break;
		}
	}
	if (search_to_delete == cart_index)
		inputID_invalid(input_ID);
}


void user::user_check_cart() {
	//用户查看购物车
	cout << endl << "购物车中有:" << endl;
	cout << inventory_cart_lace << endl;
	for (int i = 0; i < cart_index; i++) {
		if (!user_cart[i][0].empty()) {
			for (int m = 0; m < 5; m++)
				cout << user_cart[i][m] << '\t';
			cout << endl;
		}
	}
	cout << inventory_cart_lace << endl;
}

void user::user_interface() {
	//显示用户操作界面
	system("cls");
	cout << "**********************************************************************************************************" << endl;
	cout << "1.注销登陆    2.查看商品    3.商品搜索    4.添加商品至购物车    5.删除购物车商品    6.查看购物车    7.结账" << endl;
	cout << "**********************************************************************************************************" << endl;
}

void user::array_to_file(string filepath, int index, string array[20][5]) {
	//将array中的index个信息写入filepath中
	ofstream Cart(filepath, ios::out | ios::trunc);
	for (int i = 0; i < index; i++)
		if (!array[i][0].empty()) {
			for (int m = 0; m < 5; m++) {
				if (m == 4 && i == index - 1)
					Cart << array[i][m];
				else if (m == 4 && i != index - 1)
					Cart << array[i][m] << '\n';
				else
					Cart << array[i][m] << '\t';
			}
		}
	Cart.close();
}

void user::user_pay(string user) {
	//结账
	user_check_cart();
	//计算一共需要付款的价钱
	double sum = 0;
	for (int i = 1; i < cart_index; i++)
		sum += atof(user_cart[i][3].c_str()) * atoi(user_cart[i][4].c_str());
	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "一共需要付款" << sum << "! 确认付款请按1, 取消请按0: ";
	int pay_option = 0; cin >> pay_option;
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	if (pay_option == 1) {

		cout << endl << "**********" << endl;
		cout << "付款成功" << endl;
		cout << "**********" << endl;

		ofstream user_list(list_path, ios::app);
		ofstream inventory_file(inventory_path, ios::trunc | ios::out);
		for (int i = 1; i < cart_index; i++) {
			//写入已售清单
			user_list << endl;
			for (int m = 0; m < 5; m++)
				user_list << user_cart[i][m] << '\t';
			user_list << user;
			if (i != cart_index - 1)
				user_list << endl;
			//更改库存内容
			for (int inven = 1; inven < inventory_index; inven++) {
				if (user_inventory[inven][0] == user_cart[i][0]) {
					int new_num;
					new_num = atoi(user_inventory[inven][4].c_str()) - atoi(user_cart[i][4].c_str());
					if (new_num < 0) cout << "库存不足 请与商家联系" << endl;
					char New_Num[10];
					_itoa_s(new_num, New_Num, 10);
					user_inventory[inven][4].clear(); user_inventory[inven][4].append(New_Num);
				}
			}
		}
		array_to_file(inventory_path, inventory_index, user_inventory);//库存写入文件
		array_to_file(UserCart_FilePath + user + ".txt", 1, user_cart);//最后清空购物车
		tap_return();
	}
	else
		tap_return();
}

void user::inputID_invalid(string input_ID) {
	cout << endl << "********************************" << endl;
	cout << "亲, 不存在编号为" << "\"" << input_ID << "\"的商品哦" << endl;
	cout << "********************************" << endl;
	tap_return();
}