/*
描述
算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。日常使用的算术表达式是采用中缀表示法，即二元运算符位于两个运算数中间。请设计程序将中缀表达式转换为后缀表达式。

输入
输入在一行中给出不含空格的中缀表达式，可包含+、-、*、\以及左右括号（），表达式不超过20个字符。
输出
在一行中输出转换后的后缀表达式，要求不同对象（运算数、运算符号）之间以空格分隔，但结尾不得有多余空格。
样例输入
2+3*(7-4)+8/4
样例输出
2 3 7 4 - * + 8 4 / +
提示
样例输入 ((2+3)*4-(8+2))/5
样例输出 2 3 + 4 * 8 2 + - 5 /

样例输入 1314+25.5*12
样例输出 1314 25.5 12 * +
*/

#include<stdio.h>
#include<iostream>
using namespace std;
//定义优先级
const int END = -1;
const int VALUE = 0;
const int PLUS_MINUS = 1;
const int MULTI_DIV = 2;
const int OPEN_PAREN = 3;
const int CLOSE_PAREN = 4;

//定义符号对象的优先级
int priority(const char c) {
    switch (c) {
    case '\0':return END;
    case '+':
    case '-':return PLUS_MINUS;
    case'*':
    case'/': return MULTI_DIV;
    case'(':return OPEN_PAREN;
    case')':return CLOSE_PAREN;
    default: return VALUE;
    }
}

//符号栈
char stack[30] = "\0";
int num = 0;

//栈函数
int empty() {
    return !num;
}

const char top() {
    return stack[num];
}

//返回栈顶元素并将其弹出
char pop() {
    return stack[num--];
}

//将元素压栈
void push(char c) {
    stack[++num] = c;
}

//中缀表达式
char midfix[30] = "\0";

int main() {
    //首次输出的指示器，用于判断是否加空格
    int flag = 0;

    //将操作数与符号划分开来
    char* p = NULL, * q = NULL;
    int postIndex = 0;
    int curPriority;
    cin >> midfix;
    p = q = midfix;
    while (1) {
        curPriority = priority(*p);
        //读取完毕
        if (curPriority == END) {
            while (!empty()) {
                putchar(' ');
                putchar(pop());
            }
            break;
        }
        //当前读入数值，直接输出
        if (curPriority == VALUE) {
            //使用指针q进行搜索，直到q指向下一个符号或字符串末尾为止
            for (q = p;priority(*q) == VALUE;q++);
                if (flag++)
                    putchar(' ');
            while (p != q)
                putchar(*p++);
        }//左括号，压栈
        else if (curPriority == OPEN_PAREN) {
            push('(');
            ++p;
        }//读入右括号，将符号栈内元素弹出，直到遇到左括号
        else if (curPriority == CLOSE_PAREN) {
            char c = 0;
            while (!empty()) {
                c = pop();
                if (c == '(')
                    break;
                putchar(' ');
                putchar(c);
            }
            ++p;
        }//读入四则运算符
        else {
            while (!empty() && priority(top()) >= curPriority&&top()!='(') {
                    putchar(' ');
                    putchar(pop());
                
            }
            push(*p++);
          
        }
    }
    putchar('\n');
    return 0;
}
