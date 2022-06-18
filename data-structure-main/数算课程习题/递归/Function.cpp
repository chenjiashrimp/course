/*
描述
对于一个递归函数w(a,b,c)

如果a<=0 or b<=0 or c<=0就返回值1.
如果a>20 or b>20 or c>20就返回w(20,20,20)
如果a<b并且b<c 就返回w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)
其它别的情况就返回w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)

这是个简单的递归函数，但实现起来可能会有些问题。当a,b,c均为15时，调用的次数将非常的多。你要想个办法才行.

输入
会有若干行，每个数均为不超过50的整数。
并以-1，-1，-1结束.
输出
输出若干行，见样例
样例输入
1 1 1
2 2 2
-1 -1 -1
样例输出
w(1, 1, 1) = 2
w(2, 2, 2) = 4
*/

#include <cstdio>
#include <iostream>
using namespace std;
const int max_n = 21;
int f[max_n][max_n][max_n];
bool visited[max_n][max_n][max_n];
int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (visited[a][b][c])
        return f[a][b][c];
    visited[a][b][c] = true;
    if (a < b && b < c)  f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else  f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return f[a][b][c];
}
int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}
