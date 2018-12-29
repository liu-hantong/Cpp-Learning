
#Created by Liu Hantong on 2017/12/2

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<conio.h>
#define M 4//行数(每次增加的数)
#define N 4//列数#define TRUE 1
#define L 2//每次增加的数
using namespace std;
int Add_Number=1;//每次添加的数(已初始化)
int Add_Position;//每次添加数的位置
int A, B, C, D;//临时保存每一行(列)的数
//定义一个函数和用来打印4*4数组
void Print(int a[M][N])
{
	for (int n = 0; n <= 3; n++)
		for (int m = 0; m <= 3; m++)
		{
			cout << setw(6) << a[n][m]<<" ";
			if (m == 3) cout << endl<<endl;
		}		
}
//定义函数Sum_Mat()用于求屏幕上所有数之和 sum即为玩家即时得分
int Sum_Mat(int a[M][N])
{
	int sum = 0;
	for (int n = 0; n <= 3;n++)
		for (int m = 0; m <= 3; m++)
			sum += a[n][m];
	return sum;
}
//定义函数返回一个0-3的随机数
int My_Rand()
{
	srand(time(NULL));
	return rand() % 4;	
}
//接受到w(上键)时的操作
void My_Up(int a[M][N])
{
	system("cls");
	//逐列对矩阵进行变换
	//代价很大，CPU您辛苦了
	for (int n = 0; n <= 3; n++)
	{
		//先将多余的零删去，即 使数值顶格
		if (a[0][n] != 0 || a[1][n] != 0 || a[2][n] != 0 || a[3][n] != 0)
		{
			//将不为零的数保存在一个新的数组中
			int Temp[4] = { 0 };
			for (int i = 0,l=0;l<4;l++)
				if(a[l][n] != 0) Temp[i++] = a[l][n];
			//将数组中的数重新赋值给这一列(行)
			for (int p = 0; p < 4; p++)
				a[p][n] = Temp[p];
		}
		//再对相邻的数值相同的数进行相加
		A = a[0][n];
		B = a[1][n];
		C = a[2][n];
		D = a[3][n]; 
		while ((A == B&&A!=0) || (B == C&&B != 0) || (C == D&&C != 0))
		{
			//共分为四种情况计算叠加后的值
			if (A == B&&C != D)
			{
				a[0][n] = A + B;
				a[1][n] = C;
				a[2][n] = D;
				a[3][n] = 0;
			}
			if (B == C&&A != D)
			{
				a[1][n] = B + C;
				a[2][n] = D;
				a[3][n] = 0;
			}
			if (C == D&&A != B)
			{
				a[2][n] = C + D;
				a[3][n] = 0;
			}
			if (A == B&&C == D)
			{
				a[0][n] = A + B;
				a[1][n] = C + D;
				a[2][n] = 0, a[3][n] = 0;
			}
			A = a[0][n];
			B = a[1][n];
			C = a[2][n];
			D = a[3][n];
		}
	}
	//根据随机数返回值确定添加的数为2或4
	if (My_Rand() % 2 == 0) Add_Number = M;
	else Add_Number = L;
	//确定新增数的位置
	for (;;)
	{
		int i = My_Rand();
		if (a[3][i] == 0)
		{
			a[3][i] = Add_Number;
			break;
		}
	}
	Print(a);
	cout << endl << "总分 " << Sum_Mat(a) << endl;
}
//接受到s(下键)的操作
void My_Down(int a[M][N])
{
	system("cls");
	//逐列对矩阵进行变换
	//代价很大，CPU您辛苦了
	for (int n = 0; n <= 3; n++)
	{
		//先将多余的零删去，即 使数值顶格
		if (a[0][n] != 0 || a[1][n] != 0 || a[2][n] != 0 || a[3][n] != 0)
		{
			//先将这一列(行)的数保存在另一数组中
			int Temp[4] = { 0 };
			for (int i = 3, l = 3; l>=0; l--)
				if (a[l][n] != 0) Temp[i--] = a[l][n];
			//挑选其中不为零的数值赋回这一列(行)
			for (int p = 3; p >=0; p--)
				a[p][n] = Temp[p];
		}
		//再对相邻的数值相同的数进行相加
		A = a[3][n];
		B = a[2][n];
		C = a[1][n];
		D = a[0][n];
		while ((A == B&&A!=0)|| (B == C&&B!=0) || (C == D&&C!=0))
		{
			A = a[3][n];
			B = a[2][n];
			C = a[1][n];
			D = a[0][n];
			if (A == B&&C != D)
			{
				a[3][n] = A + B;
				a[2][n] = C;
				a[1][n] = D;
				a[0][n] = 0;
			}
			if (B == C&&A != D)
			{
				a[2][n] = B + C;
				a[1][n] = D;
				a[0][n] = 0;
			}
			if (C == D&&A != B)
			{
				a[1][n] = C+D;
				a[0][n] = 0;
			}
			if (A == B&&C == D)
			{
				a[3][n] = A + B;
				a[2][n] = C + D;
				a[1][n] = 0, a[0][n] = 0;
			}
		}
	}
	//根据随机数返回值确定添加的数为2或4
	if (My_Rand() % 2 == 0) Add_Number = M;
	else Add_Number = L;
	//确定新增数的位置
	for (;;)
	{
		int i = My_Rand();
		if (a[0][i] == 0)
		{
			a[0][i] = Add_Number;
			break;
		}
	}
	Print(a);
	cout <<endl<< "总分 " << Sum_Mat(a) << endl;

}
//接受到d(右键)的操作
void My_Right(int a[M][N])
{
	system("cls");
	//逐行对矩阵进行变换
	for (int n = 0; n <= 3; n++)
	{
		//先将多余的零删去，即 使数值顶格
		if (a[n][0] != 0 || a[n][1] != 0 || a[n][2] != 0 || a[n][3] != 0)
		{
			int Temp[4] = { 0 };
			for (int i = 3, l = 3; l >= 0; l--)
				if (a[n][l] != 0) Temp[i--] = a[n][l];
			for (int p = 3; p >= 0; p--)
				a[n][p] = Temp[p];
		}
		//再对相邻的数值相同的数进行相加
		A = a[n][3];
		B = a[n][2];
		C = a[n][1];
		D = a[n][0];
		while ((A == B&&A != 0) || (B == C&&B != 0) || (C == D&&C != 0))
		{
			A = a[n][3];
			B = a[n][2];
			C = a[n][1];
			D = a[n][0];
			if (A == B&&C != D)
			{
				a[n][3] = A + B;
				a[n][2] = C;
				a[n][1] = D;
				a[n][0] = 0;
			}
			if (B == C&&A != D)
			{
				a[n][2] = B + C;
				a[n][1] = D;
				a[n][0] = 0;
			}
			if (C == D&&A != B)
			{
				a[n][1] = C+D;
				a[n][0] = 0;
			}
			if (A == B&&C == D)
			{
				a[n][3] = A + B;
				a[n][2] = C + D;
				a[n][1] = 0, a[n][0] = 0;
			}
		}
	}
	//根据随机数返回值确定添加的数为2或4
	if (My_Rand() % 2 == 0) Add_Number = M;
	else Add_Number = L;
	//确定新增数的位置 依然用随机数
	for (;;)
	{
		int i = My_Rand();
		if (a[i][0] == 0)
		{
			a[i][0] = Add_Number;
			break;
		}
	}
	Print(a);
	cout << endl << "总分 " << Sum_Mat(a) << endl;
}
//接受到a(左键)时的操作
void My_Left(int a[M][N])
{
	system("cls");
	//逐行对矩阵进行变换
	for (int n = 0; n <= 3; n++)
	{
		//先将多余的零删去，即 使数值顶格
		if (a[n][0] != 0 || a[n][1] != 0 || a[n][2] != 0 || a[n][3] != 0)
		{
			int Temp[4] = { 0 };
			for (int i = 0, l = 0; l<4; l++)
				if (a[n][l] != 0) Temp[i++] = a[n][l];
			for (int p = 0; p < 4; p++)
				a[n][p] = Temp[p];
		}
		//再对相邻的数值相同的数进行相加
		A = a[n][0];
		B = a[n][1];
		C = a[n][2];
		D = a[n][3];
		while ((A == B&&A != 0) || (B == C&&B != 0) || (C == D&&C != 0))
		{
			A = a[n][0];
			B = a[n][1];
			C = a[n][2];
			D = a[n][3];
			if (A == B&&C != D)
			{
				a[n][0] = A + B;
				a[n][1] = C;
				a[n][2] = D;
				a[n][3] = 0;
			}
			if (B == C&&A != D)
			{
				a[n][1] = B + C;
				a[n][2] = D;
				a[n][3] = 0;
			}
			if (C == D&&A != B)
			{
				a[n][2] = C+D;
				a[n][3] = 0;
			}
			if (A == B&&C == D)
			{
				a[n][0] = A + B;
				a[n][1] = C + D;
				a[n][2] = 0, a[n][3] = 0;
			}
		}
	}
	//根据随机数返回值确定添加的数为2或4
	if (My_Rand() % 2 == 0) Add_Number = M;
	else Add_Number = L;
	//确定新增数的位置
	for (;;)
	{
		int i = My_Rand();
		if (a[i][3] == 0)
		{
			a[i][3] = Add_Number;
			break;
		}
	}
	Print(a);
	cout << endl << "总分 " << Sum_Mat(a) << endl;
}
int main()
{
	int a[4][4] = { 0 };
	//寻找两个2的初始位置
	int m1 = My_Rand(), n1 = My_Rand();
	int m2 = My_Rand(), n2 = My_Rand();
	//保证两个2不为同一位置
	while (m1 == m2&&n1 == n2)
	{
		m1 = My_Rand(), n1 = My_Rand();
		m2 = My_Rand(), n2 = My_Rand();
	}
	a[m1][n1] = 2, a[m2][n2] = 2;
	//将该矩阵初始化后输出
	Print(a);
	cout << endl << "总分 " << Sum_Mat(a) << endl;//输出初始总分
	//开始游戏
	while(TRUE)
	//连续执行 并没有设置其他系统
	{
		switch (_getche())
		{
		case 75: My_Left(a) ; break;
		case 80: My_Down(a); break;
		case 77: My_Right(a); break;
		case 72: My_Up(a); break;
		default: break;
		}
	}
	return 0;
}
