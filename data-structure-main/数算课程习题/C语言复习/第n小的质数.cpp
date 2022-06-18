/*描述
输入一个正整数n，求第n小的质数。

输入
一个不超过10000的正整数n。
输出
第n小的质数。
样例输入
10
样例输出
29
*/

#include <stdio.h>

int n;

int array[1050];

// 函数，判断k是否是质数。若是返回1，否则返回0。
// 注意优化函数，若从2到k-1循环，可能超时
int is_prime(int k) {
    bool x = true;
    if (k % 2 == 0 && k != 2)
        return 0;
    else {
        for (int i = 3;i * i <= k;i += 2) {
            if (k % i == 0 && i != k) {
                x = false;
                break;
            }
        }
    }
    if (x)
        return 1;
    else
        return 0;
}

int main() {
    int i;
    scanf("%d", &n);
    for (i = 2; ; i++) {
        if (is_prime(i)) {
            n--;
        }
        if (n == 0)
        {
            printf("%d\n", i);
            return 0;
        }
    }
}
