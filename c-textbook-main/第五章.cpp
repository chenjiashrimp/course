#include<iostream>
#include<cmath>
using namespace std;

bool checkPrime(int);//提早函数声明,注意分号

int main() {
	int a = 0;
	cout << "请输入一个整数" << endl;
	cin >> a;
	if (checkPrime(a))
		cout << a << "是质数" << endl;
	else
		cout << a << "不是质数" << endl;
	return 0;
}
bool checkPrime(int af) {
	if (af != 2 && af % 2 == 0)
		return false;
	if (af == 2)
		return true;
	if (af == 1)
		return false;
	for (int i = 3;i <= sqrt(af);i += 2) {
		if (af % i == 0) 
			return false;//和python一样，return了循环就不会继续了，函数调用结束了
	}
	return true;
}
//return () or return
//无返回 return;
//函数调用，有返回值的，视其为表达式放在任何可以放的地方，没有返回值的，一般是实现一系列操作，作为独立语句出现而不是表达式
//形式参数，不调用没有内存单元，调用完内存单元释放，局部变量，作用域在其函数体；实在参数，具有确定值的表达式
//函数也可以调用函数



