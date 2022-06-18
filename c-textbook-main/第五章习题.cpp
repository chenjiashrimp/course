#include<iostream>
#include<cmath>
using namespace std;
double sin(double, double);
double f(double, int);

int factor(int);

int coin(int);

int number(int, int, int);

int guess(int);

int blackhole(int);

//------------------qs1----------//
double sin(double x,double s) {
	double sum = 0.0;
	int i = 1;
	while (abs(sin(x) - sum) > s) {
		if ((i + 1) % 4 == 0)
			sum -= f(x, i);
		else
			sum += f(x, i);
		i += 2;
	}
	return sum;
}
double f(double x, int i) {
	double product = 1.0;
	for (int j = 1;j <= i;j++)
		product *= x / j;
	return product;
}

//------------------qs2--------/
int factor(int x) {
	for (int i = 1;i <= x;i++)
		if (x % i == 0)
			cout << i << endl;
	return 0;
}

//------------------qs3--------------//
int coin(int money) {
	int num = 1;
	for (int coin_1 = 10 * money;coin_1 >= 0;coin_1--)
		for (int coin_2 = (10 * money - coin_1) / 2;coin_2 >= 0;coin_2--) {
			int coin_5 = (10 * money - coin_1 - 2 * coin_2) / 5;//注意单位的切换
			if (coin_5 * 5 + coin_2 * 2 + coin_1 == 10 * money) {//检测前面的是否整除，因为/得到商，不知道余数
				cout << "方法" << num << "： " << "1角" << coin_1 << " " << "2角" << coin_2 << " " << "5角" << coin_5;
				cout << endl;
				num += 1;
			}
		}
	return 0;
}//注意：不同于python，这里/，若都为整数得到商，若含有至少一个小数则得到小数

//----------------qs4---------------//
int number(int x, int y, int z) {
	int digital[3] = { x,y,z };
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(j!=i)
				for(int k=0;k<3;k++)
					if (k != j && k != i) {
						cout << 100 * digital[i] + 10 * digital[j] + digital[k] << endl;
					}
	return 0;
}
//------------------qs5-----------------//
int guess(int x) {
	cout << x << endl;
	while (x != 1) {
		if (x % 2 == 0)
			x = x / 2;
		else
			x = 3 * x + 1;
		cout << x << endl;
	}
	return 0;
}

//----------------qs6---------------//
int max(int x, int y) {
	if (x >= y)
		return x;
	else
		return y;
}
int min(int x, int y) {
	if(x <= y)
		return x;
	else
		return y;
}
int blackhole(int x) {
	int sub_x = x;
	while (x!=0) {
		int num1 = x % 10;
		int num2 = (x / 10) % 10;
		int num3 = (x / 100) % 10;
		int num4 = x / 1000;
		int max_num = max(num1, max(num2, max(num3, num4)));
		int min_num = min(num1, min(num2, min(num3, num4)));
		int second, third = 0;
		int num[4] = { num1,num2,num3,num4 };
		for(int i=0;i<3;i++)
			for (int j = 0;j < 4-i;j++) {
				if (num[j] < num[j + 1]) {
					int temp = 0;
					temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
			}
		second = num[1];
		third = num[2];
		int Max = 1000 * max_num + 100 * second + 10 * third + min_num;
		if (num4 == 0) {
			if (num3 == 0)
				Max = Max / 100;
			else
				Max = Max / 10;
		}
		int Min = 1000 * min_num + 100 * third + 10 * second + max_num;
		sub_x = x;
		x = Max - Min;
		cout << x << endl;
	}
	return x;
}//有些错误

//----------------------qs7----------//

int main() {
	cout << sin(3, 0.001) <<" "<<sin(3)<< endl;
	factor(105);
	coin(1);
	number(7, 8, 9);
	guess(5);
	cout << endl;
	blackhole(1234);
	return 0;
}