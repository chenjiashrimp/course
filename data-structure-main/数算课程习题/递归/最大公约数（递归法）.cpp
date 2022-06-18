/*
描述
输入两个整数，n和m，用递归的方法，计算两个数的最大公约数。务必用递归的方式来实现。



输入
n m
输出
x
样例输入
24 32
样例输出
8
*/

#include <cstdio>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == b)
        return a;
    else {
        if (a > b)
            return gcd(a - b, b);
        else
            return gcd(a, b - a);
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
