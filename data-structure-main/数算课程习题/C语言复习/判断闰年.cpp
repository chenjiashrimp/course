/*描述
判断某年是否是闰年。
输入
输入只有一行，包含一个整数a(0 < a < 3000)
输出
一行，如果公元a年是闰年输出Y，否则输出N
样例输入
2006
样例输出
N
*/

#include <stdio.h>

int main() {
    int y;
    scanf("%d", &y);
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
        printf("Y\n");
    else
        printf("N\n");
}
