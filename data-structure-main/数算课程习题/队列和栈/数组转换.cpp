/*
描述
有n个数字1,2,3…,n，由小至大依次放入栈。问是否存在一种出栈方式，使这n个数字出栈的顺序为a1,a2,…,an。

输入
第一行输入一个整数t，代表有t组测试数据
对于每组测试数据，第一行输入整数n，第二行输入n个数字：a1,a2, … , an
1<= n <= 1000
输出
每组测试数据输出一行。
如果出栈顺序a1,a2,…,an是合法的，输出yes，否则输出no。
样例输入
3
3
1 2 3
3
3 2 1
4
1 4 2 3
样例输出
yes
yes
no
*/

#include <stdio.h>
#include <limits.h>

int myStack[10000];
int stack_top;

void init() {
    stack_top = -1;
}

void stack_push(int k) {
    myStack[++stack_top] = k;
}

int stack_pop() {
    if (stack_top == -1) return 0;
    else return stack_top--;
}

void works() {
    int n, next_number, k, i;
    int is_valid = 1;
    init();
    scanf("%d", &n);
    // next_number表示下一个进栈的数
    next_number = 1;
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        while (k >= next_number) {
            stack_push(next_number);
            next_number++;
        }
        if (myStack[stack_pop()] > k) {
            is_valid = 0;
        }
    }
    if (is_valid)
        printf("yes\n");
    else
        printf("no\n");
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while (testcases--) {
        works();
    }
}
