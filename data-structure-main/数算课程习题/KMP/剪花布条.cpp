/*
描述
一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？

输入
输入中含有一些数据，分别是成对出现的花布条和小饰条，其布条都是用可见ASCII字符表示的，可见的ASCII字符有多少个，布条的花纹也有多少种花样。花纹条和小饰条不会超过1000个字符长。如果遇见#字符，则不再进行工作。
输出
输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就输出0，每个结果之间应换行。
样例输入
abcde a3
aaaaaa  aa
#
样例输出
0
3
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include  <cstdio>  
#include <cstring>  
using namespace std;
int nexta[1006];
char t[1006], s[1006];
void getnexta(char s[])
{
    memset(nexta, 0, sizeof(nexta));
    int n = strlen(s);
    int k = -1, j = 0;
    nexta[0] = -1;
    while (j < n)
    {

        if (k==-1||s[k]==s[j])
        {
            nexta[j+1] = k + 1;
            j++;
            k++;
        }
        else
        {
            k = nexta[k];
        }
    }

}
int kmp(char s[], char t[])//t模式串，s母串.此种为返回首次匹配的位置，不能匹配则返回-1.  
{
    getnexta(t);
    int ans = 0;
    int n = strlen(s), m = strlen(t);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (j==-1||s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nexta[j];
        }
        if (j == m)//根据题目要求改变  
        {
            ans++;
            j = 0;
        }
    }
    return ans;
}
int main()
{
    // freopen("in.txt","r",stdin);  
    while (1)
    {
        scanf("%s", s);
        if (strcmp(s, "#") == 0)
            break;
        scanf("%s", t);
        printf("%d\n", kmp(s, t));
    }
    return 0;
}
