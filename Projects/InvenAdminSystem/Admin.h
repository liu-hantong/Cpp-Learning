#pragma once
#include"include.h"
using namespace std;
class Admin {
private:
	int option;           //����Ա�������ѡ��
	int total_inventory;  //�ֿ��е���Ʒ����
	string current;
	string file;
	string admin_lace;    //����Ա���滨��
	string commodity_lace;//��Ʒ������滨��
	string inventory[100];//�ֿ��嵥
	fstream info_out;     //�ֿ��ļ���
	void search();        //��ѯ��Ʒ
	void add();           //������Ʒ    
	bool exist(string  A[], string B, int &exist_position);
	void deelete(string in, string current);
	void add_delete_modify(int operation);
	void admin_interface();
	void display_list();
public:
	Admin();
};
Admin::Admin() {
	//��������
	commodity_lace = "*******************************************";
	file = "";
	current = "";
	while (1) {
		admin_interface();
		cout << "�������:";
		cin >> option;
		switch (option)
		{
		case 0: break;
		case 1: search(); //��ѯ��Ʒ��Ϣ
		case 2: case 3: case 4: add_delete_modify(option); break;   //����ɾ���޸���Ʒ 
		case 5: display_list();
		default:
			break;
		}
		if (!option) break;
	}
}
void Admin::search() {
	//��ѯ��Ʒ��Ϣ
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
	cout << "�������������һ���˵�" << endl;
	getchar(); getchar();
}

void Admin::add_delete_modify(int operation) {
	//������Ʒ
	admin_interface();
	info_out.open(inventory_path, ios::out | ios::app | ios::in);
	int i = 0; //���Ա�־�嵥���
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
		//ɾ����Ʒ, ���޸���Ʒ����Ϊ-1
		string in;
		cout << "����:";
		cin >> in;
		current.append("0\t" + in);
		cout << "Ʒ��:";
		cin >> in;
		current.append("\t" + in + "\t");
		deelete("-1", current);
		break;
	}
	case 4: {
		//�ı���Ʒ����, ���޸���Ʒ����Ϊin
		string in;
		cout << "����:";
		cin >> in;
		current.append("0\t" + in);
		cout << "Ʒ��:";
		cin >> in;
		current.append("\t" + in + "\t");
		cout << "����:";
		cin >> in;
		deelete(in, current);
		break; }
	default:
		break;
	};
}

bool Admin::exist(string all[], string key, int &exist_position) {
	//�ж�key����ʾ����Ʒ�Ƿ����嵥all��, ������򷵻���λ��
	string key_name = "";
	string key_brand = "";
	char key_char[2]; key_char[1] = '\0';
	int mark = 0;
	for (int i = 0; i < key.length(); i++) {
		//��key�е����ƺ�Ʒ��ת��Ϊ�ַ���
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
			//��inventory�е����ƺ��̱�ת��Ϊ�����ַ���
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
		//��key��inventory���е�name��brand���бȽ�
		if (inventory_name == key_name && key_brand == inventory_brand)
		{
			exist_position = i;
			return existed;
		}
	}
	return non_existed;
}

void Admin::add() {
	//�����Ʒ��Ŀ
	//��¼��Ʒ���
	int number_newcommodity = total_inventory;
	string string_number_newcommodity = "";
	stringstream Stringstream;
	Stringstream << number_newcommodity;
	Stringstream >> string_number_newcommodity;
	char zero[2] = { '0', '\0' };
	while (string_number_newcommodity.length() != 4)
		string_number_newcommodity = zero + string_number_newcommodity;
	current.append("\nF" + string_number_newcommodity + '\t');
	//��¼����ƷԪ��
	string in = "";
	cout << "����:"; cin >> in;
	current.append(in + '\t');
	cout << "Ʒ��:"; cin >> in;
	current.append(in + '\t');
	int exist_position;
	if (exist(inventory, current, exist_position)) {
		//����Ʒ�Ѵ���, ���޸���Ʒ����
		cout << "����Ʒ�Ѵ���, ��������ĺ������:";
		cin >> in;
		//�����ļ��е�����ֵ
		deelete(in, current);
	}
	else {
		//��Ʒ������
		cout << "�۸�:"; cin >> in;
		current.append(in + '\t');
		cout << "����:"; cin >> in;
		current.append(in);
		info_out.open(inventory_path, ios::out | ios::in | ios::app);
		info_out << current;
	}
	info_out.close();
}

void Admin::deelete(string in, string current) {
	//��current������¼����Ʒ�����ڲֿ����޸�Ϊin
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
	//��ʾ�����߽���
	admin_lace = "===============================================================================";
	system("cls");
	cout << admin_lace << endl;
	cout << "0.ע����½   1.��ѯ��Ʒ   2.������Ʒ   3.ɾ����Ʒ   4.�޸���Ʒ����   5.�ջ��嵥" << endl;
	cout << admin_lace << endl;
}

void Admin::display_list() {
	//չʾ�۳��嵥
	string list[10][6];
	char _list[2]; //����current�е��ַ�ת��
	_list[1] = '\0';
	int list_index = 0;
	ifstream info_out;
	info_out.open(list_path, ios::in);
	while (!info_out.eof()) {
		getline(info_out, current);
		if (!current.empty()) {
			//��current�е����ݷֶδ���list��
			int i = 0; // ��־Ԫ��˳��
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
	//ʹ��ѡ�����������Ʒ������
	string exchange;
	for (int i = list_index - 1; i > 1; i--)
		for (int m = 1; m < i; m++) {
			if (list[m][0][4] >= list[m + 1][0][4]) {
				//����������Ϣ��
				for (int exchange_mark = 0; exchange_mark <= 5; exchange_mark++) {
					exchange = list[m][exchange_mark];
					list[m][exchange_mark] = list[m + 1][exchange_mark];
					list[m + 1][exchange_mark] = exchange;
				}
			}
		}
	//�ٸ�����Ʒ�źͼ۸�������
	bool flag[100] = { 0 };//��־�Ѿ������ӵ���Ʒ��
	for (int i = 1; i < list_index - 1; i++) {
		if (!flag[i]) {
			for (int m = i + 1; m <= list_index - 1; m++) {
				if (!flag[m]) {
					if (list[i][0] == list[m][0] && list[i][3] == list[m][3]) {
						//����Ʒ������
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
	//��ӡ
	cout << "**********************************************" << endl;
	for (int i = 0; i <= list_index - 1; i++) {
		if (!flag[i]) {
			for (int m = 0; m <= 5; m++)
				cout << list[i][m] << '\t';
			cout << endl;
		}
	}
	cout << "**********************************************" << endl;
	cout << "�������������һ���˵�" << endl;
	getchar(); getchar();

}