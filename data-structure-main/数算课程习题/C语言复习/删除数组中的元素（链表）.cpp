/*描述
给定N个整数，将这些整数中与M相等的删除
假定给出的整数序列为：1,3,3,0,-3,5,6,8,3,10,22,-1,3,5,11,20,100,3,9,3
应该将其放在一个链表中，链表长度为20
要删除的数是3，删除以后，链表中只剩14个元素：1 0 -3 5 6 8 10 22 -1 5 11 20 100 9

要求：必须使用链表，不允许使用数组,也不允许不删除元素直接输出
      程序中必须有链表的相关操作：建立链表，删除元素，输出删除后链表中元素，释放链表
      不符合要求的程序即使通过，也会算作0分

输入
输入包含3行：
第一行是一个整数n(1 <= n <= 200000)，代表数组中元素的个数。
第二行包含n个整数，代表数组中的n个元素。每个整数之间用空格分隔；每个整数的取值在32位有符号整数范围以内。
第三行是一个整数k，代表待删除元素的值（k的取值也在32位有符号整数范围内）。
输出
输出只有1行：
将数组内所有待删除元素删除以后，输出数组内的剩余元素的值，每个整数之间用空格分隔。
样例输入
20
1 3 3 0 -3 5 6 8 3 10 22 -1 3 5 11 20 100 3 9 3
3
*/


#include <stdio.h>
struct ListNode {
    int val;
    ListNode* next;
    // 构造函数，在new时调用
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

int n, k, target;

void print_list(ListNode*);

int main() {
    int i;
    // 建立一个虚拟节点作为链表头
    ListNode* dummy = new ListNode(-10000000);
    ListNode* p = dummy, * q;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        // 建立新节点
        p->next = new ListNode(k);
        p = p->next;
    }

    // 打印链表的所有元素
    //print_list(dummy->next);

    // 读入要删除的数
    scanf("%d", &target);
    p = dummy;
    while (p && p->next) {
        q = p->next;
        if (q->val == target) {
            p->next = q->next; // 删除q
            delete q;
        }
        else
            p = q;
    }

    // 打印链表的所有元素
    print_list(dummy->next);
}

void print_list(ListNode* p) {
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
