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
	//ָ��
	int* p = NULL;//ָ����ǵ�ַ����ַ�صĶ�������Ϊint NULL��p��ʼ��Ϊ0
	i = 4;
	p = &i;
	cout << *p << endl;
	//������ϵ�����
	//�ַ���ASCII�����ʽ��ţ���char����һ���ֽڵ����������� x='A'��x=65һ��
}