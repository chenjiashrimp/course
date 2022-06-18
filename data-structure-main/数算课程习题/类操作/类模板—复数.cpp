/*
总时间限制: 1000ms 内存限制: 65536kB
描述
为了进行对复数的加法与乘法计算并进行输出，我们建立了复数类complex, 成员变量包括实部a和虚部b。

当a,b属于不同类型（int,double,long long...）时，我们希望能基于这同一个复数类模板进行相同的计算操作。

输入
第一行为一个整数n，表示测试组数
对于每组数据 第一行输入数据类型（只包括int,double)
第二行输入 参与运算的两个复数的实部与虚部，以及运算符。
输出
输出计算出的复数
样例输入
2
int
1 2 + 3 4
double
1.5 -1.0 * 2.5 0.5
样例输出
4+6i
4.25-1.75i
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

template <typename A_Type> class complex
{
public:
	A_Type a;
	A_Type b;

	complex() {}
	complex(A_Type x, A_Type y)
	{
		a = x;
		b = y;
	}

	complex <A_Type>  multiply(A_Type x, A_Type y)
	{

		complex <A_Type> res;
		res.a = a * x - b * y;
		res.b = b * x + a * y;
		return res;
	}

	complex <A_Type> add(A_Type x, A_Type y)
	{
		complex <A_Type> res;
		res.a = a + x;
		res.b = b + y;

		return res;
	}



	void print()
	{
		if (b == 0)
			cout << a << endl;
		else if
			(a == 0) cout << b << 'i' << endl;
		else if (b > 0)
			cout << a << '+' << b << 'i' << endl;
		else if (b < 0)
			cout << a << '-' << (-b) << 'i' << endl;
	}

};



int main()
{
	int n;
	char type[10], symbol;


	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s ", type);

		if (0 == strcmp(type, "int"))
		{
			int r1, i1, r2, i2;
			cin >> r1 >> i1 >> symbol >> r2 >> i2;

			complex<int> result;
			complex<int> a(r1, i1);
			if (symbol == '+')
				result = a.add(r2, i2);
			else if (symbol == '*')
				result = a.multiply(r2, i2);
			result.print();



		}
		// double
		else if (0 == strcmp(type, "double"))
		{
			double r1, i1, r2, i2;
			cin >> r1 >> i1 >> symbol >> r2 >> i2;
			complex<double> result;
			complex<double> a(r1, i1);
			if (symbol == '+')
				result = a.add(r2, i2);
			else if (symbol == '*')
				result = a.multiply(r2, i2);
			result.print();
		}

	}


}
