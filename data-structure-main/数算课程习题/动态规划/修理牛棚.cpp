/*
描述
在一个月黑风高的暴风雨夜，Farmer John 的牛棚的屋顶、门被吹飞了 好在许多牛正在度假，所以牛棚没有住满。

牛棚一个紧挨着另一个被排成一行，牛就住在里面过夜。有些牛棚里有牛，有些没有。 所有的牛棚有相同的宽度。

自门遗失以后，Farmer John 必须尽快在牛棚之前竖立起新的木板。他的新木材供应商将会供应他任何他想要的长度，但是吝啬的供应商只能提供有限数目的木板。 Farmer John 想将他购买的木板总长度减到最少。

给出 m,s,cm,s,c，表示木板最大的数目、牛棚的总数、牛的总数；以及每头牛所在牛棚的编号，请算出拦住所有有牛的牛棚所需木板的最小总长度。

输入
一行三个整数 m,s,c，意义如题目描述。
接下来 c 行，每行包含一个整数，表示牛所占的牛棚的编号。
对于 100% 的数据，1≤m≤50，1≤c≤s≤200。
输出
输出一行一个整数，表示所需木板的最小总长度。
样例输入
4 50 18
3 
4 
6 
8 
14
15 
16 
17 
21
25 
26 
27 
30 
31 
40 
41 
42 
43
样例输出
25
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int max_cs = 201;
const int max_m = 51;
int m, s, c;
int cows[max_cs];
int f[max_m];  // i: the number of used planks;  f[i]: min cost
int main() {
    cin >> m >> s >> c;
    for (int i = 0; i < c; ++i)
        cin >> cows[i];
    sort(cows, cows + c, less<int>());
    int prev = -1;
    for (int i = 1; i <= m; ++i)
        f[i] = 1e9;

    f[1] = 1;
    for (int k = 1; k < c; ++k) {
        for (int i = m;i >= 2;i--) {
            f[i] = min(f[i - 1] + 1, f[i] + cows[k] - cows[k - 1]);
        }
        f[1] = cows[k] - cows[0] + 1;
    }
    int res = f[1];
    for (int i = 1; i <= m; ++i)
        res = min(res, f[i]);
    cout << res << endl;
    return 0;
}
