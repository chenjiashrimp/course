/*
描述
国际象棋的棋盘是由8×8共64个方格构成，棋子放在方格里面。如果两个皇后棋子在同一行、同一列，或者在某个正方形的对角线上，那么这两个皇后就会互相攻击。请在棋盘上摆放8个皇后，使得它们都不会互相攻击。这是经典的8皇后问题。

现在要解决N皇后问题：将N个皇后摆放在一个N行N列的国际象棋棋盘上，要求任何两个皇后不能互相攻击。输入皇后数N(1<=N<=9),输出所有的摆法。无解输出"NO ANSWER"。行列号都从0开始算。

输入
一个整数N，表示要把N个皇后摆放在一个N行N列的国际象棋棋盘上
输出
所有的摆放放案。每个方案一行，依次是第0行皇后位置、第1行皇后位置......第N-1行皇后位置。
多种方案输出顺序如下：优先输出第0行皇后列号小的方案。如果两个方案第0行皇后列号一致，那么优先输出第1行皇后列号小的方案......以此类推
样例输入
4
样例输出
1 3 0 2 
2 0 3 1 
*/

#include<iostream>
using namespace std;
const int Normalize = 10;
int Num = 0;
int Q[15] = { 0 };
bool C[30] = { 0 }, R[30] = { 0 }, L[30] = { 0 };//分别是判断列、两个对角线是否安全
void Try(int i, int n) {//其实有点像双循环，，只是第一层循环变成了多次调用函数
	for (int j = 1;j <= n;j++) {//一列一列尝试
		if (C[j] && L[i - j + Normalize] && R[i + j]) {
			Q[i] = j;
			C[j] = false;
			L[i - j + Normalize] = false;
			R[i + j] = false;//对角线的一个性质，i+j为定值，可用来描述对角线
			if (i < n)
				Try(i + 1, n);
			else {
				Num++;
				for (int i = 1;i <= n;i++) {
					if (i == 1)
						cout << Q[i] - 1;
					else
						cout << " " << Q[i] - 1;
				}
				cout << endl;
			}
			C[j] = true;//回溯法，尝试其他方案
			L[i - j + Normalize] = true;
			R[i + j] = true;
		}
	}
}
int main() {
	int n = 0;
	cin >> n;
	for (int i = 1;i <= 29;i++)
		C[i] = true;//初始化，一开始都为0要变为true
	for (int i = 1;i <= 29;i++)
		L[i] = R[i] = true;
	Try(1, n);
	if (Num == 0)
		cout << "NO ANSWER";
	return 0;
}
