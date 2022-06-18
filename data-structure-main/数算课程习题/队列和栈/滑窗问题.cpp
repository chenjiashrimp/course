/*
描述
给定一个大小为n的数组。有一个K大小的滑动窗口，它从数组的最左边移动到最右边。你只能在窗口中看到K个数字。每次滑动窗口向右移动一个位置。你的任务是确定滑动窗口中每个位置的最大值和最小值。



输入
输入由两行组成。第一行包含两个整数n和k(n不超过10000，k小于n),它们是数组和滑动窗口的长度。第二行有n个整数，为数组的值（均在int范围内）。
输出
输出中有两行。第一行分别给出窗口中每个位置从左到右的最小值。第二行给出最大值。
样例输入
8 3
1 3 -1 -3 5 3 6 7
样例输出
-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/

#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1000000 + 10;
int n, k, maxh, minh, maxt, mint;
int maxq[MAXN], minq[MAXN], num[MAXN];
int maxans[MAXN], minans[MAXN];

int main()
{

    while (scanf("%d%d", &n, &k) != EOF)
    {
        int maxhead = 0, minhead = 0, maxtail = 0, mintail = 0;
        for (int i = 0;i < n;i++)
        {
            //删除下标超出范围的队首元素 
            if (maxhead < maxtail && maxq[maxhead] <= i - k) maxhead++;
            if (minhead < mintail && minq[minhead] <= i - k) minhead++;


            scanf("%d", &num[i]);

            /*删除队尾元素*/
            while (maxhead < maxtail && num[maxq[maxtail - 1]] <= num[i]) maxtail--;maxtail++;
            maxq[maxtail - 1] = i;
            while (minhead < mintail && num[minq[mintail - 1]] >= num[i]) mintail--;mintail++;
            minq[mintail - 1] = i;
            maxans[i] = num[maxq[maxhead]];
            minans[i] = num[minq[minhead]];
        }
        for (int i = k - 1;i < n;i++) cout << minans[i] << ' ';cout << endl;
        for (int i = k - 1;i < n;i++) cout << maxans[i] << ' ';cout << endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
