#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int i = 0;
	float f = 0.0;
	long m = 0;
	double d = 0.0;//int,unsigned int, long int=4 float 4 double 8 long double 16 char bool 1
	//1 byte=8 bit
	cout << sizeof(int) << endl;
	cout << &i << endl;
	//cmath
	cout << cos(3) << endl;
	//指针
	int* p = NULL;//指针就是地址，地址藏的东西类型为int NULL将p初始化为0
	i = 4;
	p = &i;
	cout << *p << endl;
	//几个关系运算符
	//字符以ASCII码的形式存放，把char按照一个字节的整型来处理 x='A'与x=65一样
}