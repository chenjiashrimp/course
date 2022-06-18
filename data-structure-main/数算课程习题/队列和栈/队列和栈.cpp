/*
描述
队列和栈是两种重要的数据结构，它们具有push k和pop操作。push k是将数字k加入到队列或栈中，pop则是从队列和栈取一个数出来。队列和栈的区别在于取数的位置是不同的。

队列是先进先出的：把队列看成横向的一个通道，则push k是将k放到队列的最右边，而pop则是从队列的最左边取出一个数。

栈是后进先出的：把栈也看成横向的一个通道，则push k是将k放到栈的最右边，而pop也是从栈的最右边取出一个数。

假设队列和栈当前从左至右都含有1和2两个数，则执行push 5和pop操作示例图如下：

          push 5          pop

队列 1 2  ------->  1 2 5 ------>  2 5

          push 5          pop

栈   1 2  ------->  1 2 5 ------>  1 2

现在，假设队列和栈都是空的。给定一系列push k和pop操作之后，输出队列和栈中存的数字。若队列或栈已经空了，仍然接收到pop操作，则输出error。



输入
第一行为m，表示有m组测试输入，m<100。
每组第一行为n，表示下列有n行push k或pop操作。（n<150）
接下来n行，每行是push k或者pop，其中k是一个整数。
（输入保证同时在队列或栈中的数不会超过100个）
输出
对每组测试数据输出两行，正常情况下，第一行是队列中从左到右存的数字，第二行是栈中从左到右存的数字。若操作过程中队列或栈已空仍然收到pop，则输出error。输出应该共2*m行。
样例输入
2
4
push 1
push 3
pop
push 5
1
pop
样例输出
3 5
1 5
error
error
*/

#include <stdio.h>
#include <limits.h>
#include<iostream>
int myStack[10000];
int stack_top;
int myQueue[10000];
int queue_head, queue_tail;

int error_flag;
using namespace std;
void init() {
    stack_top = -1;
    queue_head = 0; queue_tail = 0;
    error_flag = 0;
}

void stack_push(int k) {
    myStack[++stack_top] = k;
}

void queue_push(int k) {
    myQueue[queue_tail++] = k;
}

int stack_pop() {
    if (stack_top < 0) {
        error_flag = 1;
        return INT_MIN;
    }
    else
        return myStack[stack_top--];
}

int queue_pop() {
    if (queue_tail == queue_head) {
        error_flag = 1;
        return INT_MIN;
    }
    else
        return myQueue[queue_head++];
}

void works() {
    int n, k, i;
        char read_string[10];

        init();
    scanf("%d", &n);
    while (n--) {
        cin >> read_string;
        if (read_string[1] == 'u') {
            scanf("%d", &k);
            stack_push(k);
            queue_push(k);
        }
        else {
            stack_pop();
            queue_pop();
        }
    }

    if (error_flag) {
        printf("error\nerror\n");
    }
    else {
        bool x = true;
        while (queue_head != queue_tail) {
            if (x) {
                printf("%d", myQueue[queue_head++]);
                x = false;
            }
            else
                printf(" %d", myQueue[queue_head++]);
        }
        printf("\n");
        x = true;
        for (i = 0;i <= stack_top;i++) {
            if (x) {
                printf("%d", myStack[i]);
                x = false;
            }
            else
                printf(" %d", myStack[i]);
        }
        printf("\n");
    }
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while (testcases--) {
        works();
    }
}
