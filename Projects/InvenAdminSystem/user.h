#pragma once
#include"include.h"
#include"Admin.h"

void tap_return() {
	cout << endl << "����������ػ����" << endl;
	getchar(); getchar();
}

class user {
private:
	int option;//�û�ģʽ������Ĳ���
	int inventory_index;
	int cart_index;
	char chartostring[2];
	string user_inventory[20][5]; //����ֿ���Ϣ
	string user_cart[20][5]; //�����û����ﳵ��Ϣ
	string inventory_cart_lace;
	string current;
	fstream inventory;
	fstream cart;
	void user_interface();
public:
	user(string user);
	void user_inventory_download();
	void user_cart_download();
	void user_check_inventory();//�鿴��Ʒ
	void user_Search();//��Ʒ����
	void user_Add(string user);//�����Ʒ�����ﳵ
	void user_Delete(string user);//ɾ�����ﳵ��Ʒ
	void user_check_cart();//�鿴���ﳵ
	void user_pay(string user);//����
	void array_to_file(string filepath, int index, string[20][5]);//���¿����ﳵ�ļ�
	void inputID_invalid(string input_ID);//�������Ʒ����Ч
	void clear_array(string array[20][5], int index);//��ʼ������
};
user::user(string user) {
	inventory_cart_lace = "**************************************";
	chartostring[1] = '\0';
	while (1) {
		//��ʼ��
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
		cout << "�������: ";
		cin >> option;
		switch (option)
		{
		case 1: break; //ע����½
		case 2: user_check_inventory(); break; //�鿴��Ʒ
		case 3: user_Search(); break; //��Ʒ����
		case 4: user_Add(user); break; //�����Ʒ�����ﳵ
		case 5: user_Delete(user);  break; //ɾ�����ﳵ��Ʒ
		case 6: user_check_cart(); ; tap_return();  break; //�鿴���ﳵ
		case 7: user_pay(user);  break; //����
		default:
			break;
		}
		if (! ( option - 1 )) break;	
		inventory.close();
		cart.close();
	}
}

void user::user_inventory_download() {
	//���ֿ��ļ����ݱ�����������
	while (!inventory.eof()) {
		getline(inventory, current);
		if (!current.empty()) {
			//��current�е����ݷֶδ���user_inventory��
			int i = 0; // ��־Ԫ��˳��
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
	//�����ﳵ�ļ����ݱ�����������
	while (!cart.eof()) {
		getline(cart, current);
		if (!current.empty()) {
			//��current�е����ݷֶδ���user_inventory��
			int i = 0; // ��־Ԫ��˳��
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
	//�û��鿴��Ʒ
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
	//������Ҫ����Ʒ��Ϣ
	cout << "������Ʒ����: ";
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
	//�����Ʒ�����ﳵ
	string input_ID;
	string input_Num;
	cout << "������ƷID������: ";
	cin >> input_ID >> input_Num;
	int p;
	for (p = 1; p < inventory_index; p++) {
		if (user_inventory[p][0] == input_ID) {
			if (atoi(user_inventory[p][4].c_str()) < atoi(input_Num.c_str())) {
				cout << "�����������, �޷����" << endl;
				tap_return();
				break;
			}
			else {
				//�����������, �������
				int flag = 0;
				for (int cat = 1; cat < cart_index; cat++)
					if (user_cart[cat][0] == input_ID)
						flag = cat;
				if (!flag) {
					//������ﳵ��ԭ��û��
					for (int add_index = 0; add_index < 4; add_index++)
						user_cart[cart_index][add_index] = user_inventory[p][add_index];
					user_cart[cart_index][4] = input_Num;
					cart_index++;
				}
				else {
					//���ﳵ���Ѿ����ڸ���Ʒ �޸���Ʒ����
					char new_number[10];
					_itoa_s(atoi(user_cart[flag][4].c_str()) + atoi(input_Num.c_str()), new_number, 10);
					user_cart[flag][4].clear(); user_cart[flag][4].append(new_number);
				}
				//�����ĺ�Ĺ��ﳵ����д���ļ�
				array_to_file(UserCart_FilePath + user + ".txt", cart_index, user_cart);
				cout << endl << "***************" << endl;
				cout << "�Ѿ����빺�ﳵ!" << endl;
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
	//ɾ�����ﳵ�е���Ʒ
	string input_ID;
	string input_Num;
	cout << "������ƷID������: ";
	cin >> input_ID >> input_Num;
	int search_to_delete;
	for (search_to_delete = 1; search_to_delete < cart_index; search_to_delete++) {
		//Ѱ������ID���±�
		if (user_cart[search_to_delete][0] == input_ID) {
			//�ַ���ת����
			int after_delete = atoi(user_cart[search_to_delete][4].c_str()) - atoi(input_Num.c_str());
			if (after_delete < 0) {
				cout << endl << "*************************" << endl;
				cout << "��, �������ﳵ��ԭ������" << endl;
				cout << "*************************" << endl;
				tap_return();
				break;
			}
			else if (after_delete == 0)
				//��������, ɾ����Ʒ
				user_cart[search_to_delete][0].clear();
			else {
				//����������, ����ԭ��
				//����ת�ַ���
				char Current[10];
				_itoa_s(after_delete, Current, 10);
				user_cart[search_to_delete][4].clear(); user_cart[search_to_delete][4].append(Current);
			}
			//��ɾ���������д�빺�ﳵ�ļ���
			array_to_file(UserCart_FilePath + user + ".txt", cart_index, user_cart);
			cout << endl << "**********" << endl;
			cout << "ɾ���ɹ�!" << endl;
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
	//�û��鿴���ﳵ
	cout << endl << "���ﳵ����:" << endl;
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
	//��ʾ�û���������
	system("cls");
	cout << "**********************************************************************************************************" << endl;
	cout << "1.ע����½    2.�鿴��Ʒ    3.��Ʒ����    4.�����Ʒ�����ﳵ    5.ɾ�����ﳵ��Ʒ    6.�鿴���ﳵ    7.����" << endl;
	cout << "**********************************************************************************************************" << endl;
}

void user::array_to_file(string filepath, int index, string array[20][5]) {
	//��array�е�index����Ϣд��filepath��
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
	//����
	user_check_cart();
	//����һ����Ҫ����ļ�Ǯ
	double sum = 0;
	for (int i = 1; i < cart_index; i++)
		sum += atof(user_cart[i][3].c_str()) * atoi(user_cart[i][4].c_str());
	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "һ����Ҫ����" << sum << "! ȷ�ϸ����밴1, ȡ���밴0: ";
	int pay_option = 0; cin >> pay_option;
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	if (pay_option == 1) {

		cout << endl << "**********" << endl;
		cout << "����ɹ�" << endl;
		cout << "**********" << endl;

		ofstream user_list(list_path, ios::app);
		ofstream inventory_file(inventory_path, ios::trunc | ios::out);
		for (int i = 1; i < cart_index; i++) {
			//д�������嵥
			user_list << endl;
			for (int m = 0; m < 5; m++)
				user_list << user_cart[i][m] << '\t';
			user_list << user;
			if (i != cart_index - 1)
				user_list << endl;
			//���Ŀ������
			for (int inven = 1; inven < inventory_index; inven++) {
				if (user_inventory[inven][0] == user_cart[i][0]) {
					int new_num;
					new_num = atoi(user_inventory[inven][4].c_str()) - atoi(user_cart[i][4].c_str());
					if (new_num < 0) cout << "��治�� �����̼���ϵ" << endl;
					char New_Num[10];
					_itoa_s(new_num, New_Num, 10);
					user_inventory[inven][4].clear(); user_inventory[inven][4].append(New_Num);
				}
			}
		}
		array_to_file(inventory_path, inventory_index, user_inventory);//���д���ļ�
		array_to_file(UserCart_FilePath + user + ".txt", 1, user_cart);//�����չ��ﳵ
		tap_return();
	}
	else
		tap_return();
}

void user::inputID_invalid(string input_ID) {
	cout << endl << "********************************" << endl;
	cout << "��, �����ڱ��Ϊ" << "\"" << input_ID << "\"����ƷŶ" << endl;
	cout << "********************************" << endl;
	tap_return();
}