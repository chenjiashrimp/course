/*
描述
有 2^n(1<=n≤7) 个国家参加世界杯决赛圈且进入淘汰赛环节。我经知道各个国家的能力值，且都不相等。能力值高的国家和能力值低的国家踢比赛时高者获胜。1 号国家和 2 号国家踢一场比赛，胜者晋级。3 号国家和 4 号国家也踢一场，胜者晋级……晋级后的国家用相同的方法继续完成赛程，直到决出冠军。给出各个国家的能力值，请问亚军是哪个国家？

输入
第一行一个数字n
第二行2^n个数字，代表其能力值
输出
亚军国家的编号（国家编号从1开始）
样例输入
3
4 2 3 1 10 5 9 7
样例输出
1
*/

#include<bits/stdc++.h>
using namespace std;
struct Team
{
    int ability;
    int index;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,num;
    cin>>n;
    num=pow(2,n);
    Team a[num+1];
    for(int i=1;i<=num;i++){cin>>a[i].ability;a[i].index=i;}
    while(num>=4)
    {
        for(int i=1;i<=num;i+=2)
        {
            if(a[i].ability>a[i+1].ability)a[(i+1)/2]=a[i];
            else a[(i+1)/2]=a[i+1];
        }
        num/=2;
    }
    if(a[1].ability>a[2].ability)cout<<a[2].index<<'\n';
    else cout<<a[1].index<<endl;
    return 0;
}
