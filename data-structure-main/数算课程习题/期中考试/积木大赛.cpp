/*
描述
春春幼儿园举办了一年一度的“积木大赛”。今年比赛的内容是搭建一座宽度为n的大厦，大厦可以看成由n块宽度为1的积木组成，第i块积木的最终高度需要是hi。

在搭建开始之前，没有任何积木（可以看成n块高度为0的积木）。接下来每次操作，小朋友们可以选择一段连续区间[L, R]，然后将第L块到第R块之间（含第L块和第R块）所有积木的高度分别增加1。

小M是个聪明的小朋友，她很快想出了建造大厦的最佳策略，使得建造所需的操作次数最少。但她不是一个勤于动手的孩子，所以想请你帮忙实现这个策略，并求出最少的操作次数。

输入
每组输入数据包含两行，第一行包含一个整数n，表示大厦的宽度。

第二行包含n个整数，第i个整数为hi。
输出
每组输出仅一行，即建造所需的最少操作数。
样例输入
5
2 3 4 1 2
样例输出
5
*/

#include <stdio.h>
#define MAXN 100004

int n;
int h[MAXN];
int ans = 0;  // final answer

void solve(int l, int r, int val = 0) {
    if (l > r) return;
    int minVal = h[r], minPos = r;
    for (int i = l; i < r; ++i) {
        if (minVal > h[i]) {
        	minVal=h[i];
        	minPos=i;
            /*****fill in the codes*************/
        }
    }
    ans += minVal;
    int x=0;
    for (int i = l; i <= r; ++i) {
    	h[i]-=minVal;
    	if(h[i]==0){
    	   solve(l,i-1);
		   l=i+1;	
		}
        /*****fill in the codes*************/
    }
    solve(l,r);
    // solve recursively
    /*****fill in the codes*************/
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
    solve(0, n - 1);
    printf("%d\n", ans);
    return 0;
}
