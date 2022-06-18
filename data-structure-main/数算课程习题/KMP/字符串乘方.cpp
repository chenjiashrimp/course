/*
描述
给定两个字符串a和b,我们定义a*b为他们的连接。例如，如果a=”abc” 而b=”def”， 则a*b=”abcdef”。 如果我们将连接考虑成乘法，一个非负整数的乘方将用一种通常的方式定义：a^0=””(空字符串)，a^(n+1)=a*(a^n)。

输入
每一个测试样例是一行可打印的字符作为输入，用s表示。s的长度至少为1，且不会超过一百万。最后的测试样例后面将是一个点号作为一行。
输出
对于每一个s，你应该打印最大的n，使得存在一个a，让s=a^n
样例输入
abcd
aaaa
ababab
.
样例输出
1
4
3
提示
本问题输入量很大，请用scanf代替cin，从而避免超时。
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5;;
char str[MAXN];
int _next[MAXN];
 
void getNext(char *p)
{
    int j,k;
    j=0;
    k=-1;
    int len=strlen(p);
    _next[0]=-1;
    while(j<len)
    {
        if(k==-1||p[j]==p[k])
        {
            j++;
            k++;
            _next[j]=k;
        }
        else k=_next[k];
    }
}
int main()
{
    while(scanf("%s",&str),str[0]!='.')
	{
	    getNext(str);
        int len=strlen(str);//str字符串的个数 
        int t=len-_next[len];//最小循环节 
        if(len%t==0)//原串是否能被循环节整除
		printf("%d\n",len/t);
		else printf("1\n");
    }
    return 0;
}
