/*
总时间限制: 1000ms 内存限制: 65536kB
描述
约瑟夫问题：有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。

输入
每行是用空格分开的两个整数，第一个是 n, 第二个是 m ( 0 < m,n <=300)。最后一行是：

0 0

输出
对于每行输入数据（最后一行除外)，输出数据也是一行，即最后猴王的编号
样例输入
6 2
12 4
8 3
0 0
样例输出
5
1
7
*/

#include<iostream>
using namespace std;
int main() {
	int n, m = 0;
	cin >> n >> m;
	while (n != 0 && m != 0) {
		int monkey[301] = { 0 };
		int num = n;
		int res = 1;
		for (int i = 1;i <= n;i++)
			monkey[i] = i;
		for (int i = 1;i < n;i++) {
			res = ((res + m-1-1) % num)+1;
				for (int j = res;j < num;j++)
					monkey[j] = monkey[j + 1];
			num--;
		}
		cout << monkey[1] << endl;
		cin >> n >> m;
	}
}
