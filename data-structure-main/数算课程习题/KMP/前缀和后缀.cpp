/*
描述
编写一个程序，当给定字符串s1和s2时，求最长的s1前缀字符串，使得它同时是s2的后缀。

输入
（多组数据）
输入包含两行。第一行包含s1，第二行包含s2。
字符串均为小写字母构成
输出
输出由一行组成，首先是一个字符串，该字符串是s1的前缀和s2的后缀，空格后跟该字符串的长度。如果最长的字符串是空字符串，则输出应直接为0.
s1和s2的长度最多为50000。
样例输入
clinton 
homer 
riemann 
marjorie
样例输出
0
rie 3
*/

#include<iostream>
#include<string.h>
using namespace std;


const int N = 5e4 + 10;
int lens1, lens2, Next[N];
char s1[N], s2[N];

void GetNext()
{
    int i, j;
    Next[0] = -1;
    i = 0;
    j = -1;
    while (i < lens1)
    {
        if (j == -1 || s1[i] == s1[j])
            Next[++i] = ++j;
        else
            j = Next[j];
    }
}

void Kmp()
{
    int i, j;
    i = 0;j = 0;
    while (i < lens2)
    {
        if (j == -1 || s1[j] == s2[i])
        {
            i++;
            j++;
        }
        else
            j = Next[j];
    }
    if (!j)
        cout << 0 << endl;
    else
    {
        char s3[N] = "\0";
        strncpy(s3, s1, j);
        cout << s3 << " " << j<< endl;
    }
}

int main()
{
    while (~scanf("%s %s", s1, s2))
    {
        lens1 = strlen(s1);
        lens2 = strlen(s2);
        GetNext();
        Kmp();
    }
    return 0;
}
