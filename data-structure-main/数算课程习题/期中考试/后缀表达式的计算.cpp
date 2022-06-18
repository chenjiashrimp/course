/*
描述
给定一个只含加法和乘法的后缀表达式，请计算出它的值。表达式长度<=1000，各结果不超过int范围。
输入
第一行包含一个整数T，代表一共有T组测试样例。
每组测试样例占1行，每相邻两项之间由一个空格隔开，最后一项后只有换行符，没有空格。输入保证合理。
输出
对于每组样例，输出一行（不包含引号）“Case t: ans”，其中t代表样例编号，由1开始，ans是运算的结果。
样例输入
2
1 2 + 3 * 4 +
1 1 + 1 1 + *
样例输出
Case 1: 13
Case 2: 4
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include<iostream>
int stack[10000];
int top = -1;

char read_string[10000];

int is_number(char c) { return c >= '0' && c <= '9'; }

void stack_push(int digit) { 
    stack[++top]=digit;
}

int stack_pop() { 
  if(top!=-1)
     return stack[top--];
}

int calc(int num1, int num2, char c) { /*****fill in the codes*************/
    switch(c){
    	case'*':return num1*num2;
    	case'/':return num1/num2;
    	case'+':return num1+num2;
    	case'-':return num1-num2;
	}
}

int main() {
    int num, len, i, j, digit, t;
    scanf("%d ", &num);
    for (t = 1; t <= num; t++) {
        top = -1;
        gets(read_string);
        len = strlen(read_string);

        for (i = 0; i < len; i++) {
            if (read_string[i] == ' ') continue;
            if (is_number(read_string[i])) {
                /*****fill in the codes*************/
                j = i;
                digit = 0;
                char str2[10]="\0";
                int k=0;
                while (j < len && is_number(read_string[j])) {
                	str2[k]=read_string[j];
                	k++;
                	j++;
                    /*****fill in the codes*************/
                }
                i = j - 1;
                digit=atof(str2);
                stack_push(digit);
                /*****fill in the codes*************/

            } else {
            	int num2=stack_pop();
            	int num1=stack_pop();
            	digit=calc(num1,num2,read_string[i]);
            	stack_push(digit);
                /*****fill in the codes*************/
            }
        }
        printf("Case %d: %d\n", t, stack_pop());
    }
}
