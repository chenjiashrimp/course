#include<iostream>
using namespace std;
int main() {
	char thisman = 'A';
	for (int k = 0;k < 4;k += 1) {//之前没有声明要定义
		int sum = 0;//sum定义在里面
		thisman = 'A' + k;
		sum = (thisman != 'A') + (thisman == 'C') + (thisman == 'D') + (thisman != 'D');
		if (sum == 1)
			break;
	}
	cout << thisman << endl;
	return 0;
}
//cin>>
//if(){} else if(){}else
//if()
int main() {
	char thisman = 'A';
	int g = 0;
	for (int k = 0;k < 4;k++) {
		int sum = 0;
		if (k != 0)sum += 1;
		if (k == 2)sum += 0;
		if (k == 3)sum += 1;
		if (k != 3)sum += 1;//相当于人为判断好了
		if (sum == 3) { cout << char('A' + k) << endl;g = 1; }
	}
	if (g != 1) cout << "can't find" << endl;
}
int main() {
	char thisman = 'A';
	int g = 0;
	for (int k = 0;k < 4;k++) {
		if ((k != 0) + (k == 2) + (k == 3) + (k != 3) == 3) {
			cout << char('A' + k) << endl;
			g = 1;
		}
	}
}

int main() {
	//逻辑运算符 && || ！
	// a||b ab至少一人做案
	// !(a&&d)ad不可能同时作案
	//(a&&e)||(a&&f)||(e&&f)三个人中至少有两个作案（当然也包括了三个人同时作案）
	//(b&&c)||(!b&&!c) bc同时作案或者同时不作案
	//(c&&!d)||(!c&&d)cd有且仅有一人做案
	//d||(!d&&!e)如果d没有做案，e也不可能作案
	for (int A = 0;A <= 1;A++) {
		for (int B = 0;B <= 1;B++) {
			for (int C = 0;C <= 1;C++) {
				for (int D = 0;D <= 1;D++) {
					for (int E = 0;E <= 1;E++) {
						for (int F = 0;F <= 1;F++) {
							//因为作案者不止一个，所以用多重循环枚举，因为只有一层，所以前面的大括号也可以省略
							//把每个人说的话转化为编程语言，就是上述注释所写的
							
							cout<<(A==0?"不是":"是")//(ex? ex:ex)
						}
					}
				}
			}
		}
	}
}
int main() {
	//不需要六重循环的方法，n 0-63 n以二进制存储只要知道n就能确定abcdef
	//每一位可以代表一个人，关键是如何把这位的信息提取出来，可以利用位运算符
	int a, b, c, d, e, f = 0;
	for (int i = 0;i < 64;i++) {
		//先表示出abcdef
		a = (i & 32) >> 5;
		b = (i & 16) >> 4;
		c = (i & 8) >> 3;
		d = (i & 4) >> 2;
		e = (i & 2) >> 1;
		f = (i & 1);
		//接着同上，把说的话转变成编程语言
	}
}
//直到型循环和当循环
int main() {
	double e = 1.0, c;
	long k = 1;
	do {
		c = 1.0;
		for (int i = 1;i <= k;i++) {
			c = c / i;
		}
		k++;
		e += c;
	}while(c>1e-10)//直到型，至少循环一次
}