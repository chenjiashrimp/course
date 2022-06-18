/*
描述
现有编号从1到n的纸牌，选择一个从下到上的顺序把他们摞起来，使得相邻两张纸牌的编号之和是素数。对于每一个n，请输出其所有满足要求的排列情况。

输入
一个整数n
输出
对于一个n，按字典序输出其所有的可能排列情况。每个情况一行。若没有相应的排列，请什么都不要输出。
样例输入
2
样例输出
1 2
2 1
提示
0 < n < 15
*/

#include <cstdio>
#include <iostream>
using namespace std;

const int max_n = 21;
int ans[max_n];
bool vis[max_n];
bool isprime[max_n];

void getprime(int n) {
	isprime[2]=1;
	int i=3;
	for(int k=3;k<=n;k=k+2)
	   isprime[k]=1;
	while(i<=n){
		for(int j=3;j*j<=i;j+=2){
			if(i%j==0&&i!=j){
			   isprime[i]=0;
			   break;
			}
		}
                 i=i+2;
	}
    /*****fill in the codes*************/
    // isprime[i] : whether i is a prime
}

void dfs(int i, int n) {
    if (i == n) {
        for (int i = 0; i < n - 1; ++i) cout << ans[i] << " ";
        cout << ans[n - 1] << endl;
        return;
    }
    else{
    	for(int j=1;j<=n;j++){
    		if(vis[j]==0){
    			if(i==0){
    				vis[j]=1;
    				ans[i]=j;
    				dfs(1,n);
    				vis[j]=0;
				}
				else{
					if(isprime[j+ans[i-1]]==1){
						vis[j]=1;
						ans[i]=j;
						i++;
						dfs(i,n);
						i--;
						vis[j]=0;
					}
				}
			}
		}
	}
    /*****fill in the codes*************/
    // Depth-First-Search
}
int main() {
    int n;
    cin >> n;
    getprime(31);
    dfs(0, n);
    return 0;
}
