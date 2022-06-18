/*
描述
将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
正整数n 的这种表示称为正整数n 的划分。正整数n 的不同的划分个数称为正整数n 的划分数

输入
一个整数N(0 < N <= 30)。
输出
输出N的划分数。
样例输入
5
样例输出
7
提示
5, 4+1, 3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1+1
*/

#include <cstdio>
#include <iostream>
const int max_n = 31;
typedef long long ll;
ll f[max_n];
using namespace std;
int main() {
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            f[j] +=f[j-i];
    cout << f[n] << endl;
    return 0;
}

