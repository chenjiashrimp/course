/*
总时间限制: 1000ms 内存限制: 65536kB
描述
已知一个已经从小到大排序的数组，这个数组的一个平台（Plateau）就是连续的一串值相同的元素，并且这一串元素不能再延伸。例如，在 1，2，2，3，3，3，4，5，5，6中1，2-2，3-3-3，4，5-5，6都是平台。试编写一个程序，接收一个数组，把这个数组最长的平台找出 来。在上面的例子中3-3-3就是最长的平台。

输入
第一行有一个整数n(n <= 1000)，为数组元素的个数。第二行有n个整数，整数之间以一个空格分开。
输出
输出最长平台的长度。
样例输入
10
1 2 2 3 3 3 4 5 5 6
样例输出
3
*/

#include<iostream>
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	int a[1001] = { 0 };
	int length_max = 1;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	int length = 1;
	for (int i = 2;i <= n;i++) {
		if (a[i] != a[i - 1]) {
			if (length > length_max)
				length_max = length;
			length = 1;
		}
		else
			length++;
	}
	if (length > length_max)
		length_max = length;
	cout << length_max;
	return 0;
}
