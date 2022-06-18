/*
描述
给定一个N行M列的01矩阵，请你找出其中一个全由1组成的正方形，并且边长越大越好。

输入
第一行包含两个整数N和M。(1 <= N, M <= 1000)
以下N行每行包含M个0或1，代表01矩阵。
输出
一个整数代表答案
样例输入
5 5
11011
11111
11110
01111
11101
样例输出
3
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int max_n = 1001;
char a[max_n][max_n];
int f[max_n][max_n];
int n, m;
int main() {
    cin.sync_with_stdio(false);  //speed up reading
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == '1') {
                f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
                res = max(res, f[i][j]);
            }
    cout << res << endl;
    return 0;
}
