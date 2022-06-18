/*
描述
给两个字符串A、B, 从A中找出第一次出现B的位置。

输入
第一行输入一个整数t，表示测试数据的个数

对于每组测试数据，输入两个字符串S T，S和T中间用一个空格隔开，每组数据占一行。

S,T的长度均不超过20000
输出
对于每组测试数据，输出A中找出第一次出现B的位置，如果A不包含B，输出-1
样例输入
3
AAAAbAA Ab
AAABBB BB
XXXXXX YY
样例输出
3
3
-1
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
const int MAX = 20000;
int a[MAX] = { 0 };
int KMP(char* t, char* p) {
	int i = 0, j = 0;
	int lent = strlen(t);
	int lenp = strlen(p);
	while (i < lent && j < lenp) {
		if (j == -1 || t[i] == p[j]) {
			i++;
			j++;
		}
		else
			j = a[j];
	}
	if (j == lenp)
		return i - j;
	else
		return -1;
}
void getNext(char* p, int* next) {
	next[0] = -1;
	int i = 0, j = -1;
	int lenp = strlen(p);
	while (i < lenp) {
		if (j == -1 || p[i] == p[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else j = next[j];
	}
}
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	while (n--) {
		char t[20001] = "\0";
		char p[20001] = "\0";
		scanf("%s%s",t,p);
		getNext(p, a);
		cout << KMP(t, p) << endl;
	}
}
