/*
描述
给定两个字符串A，B，在A中查找与B相同的子串，并返回所有满足条件的位置。

例如 A = "abaaababa", B = "aba"，则B在位置0, 4, 6出现。

由于B出现的位置可能很多，输出所有位置求和并对10007取模的值即可。

若B不在A中出现，则输出0。

输入
第一行输入一个字符串A。

第二行输入一个字符串B。

（A B只包含小写字母，且长度大于0，小于等于200000）。
输出
如题意所述。
样例输入
abaaababa
aba
样例输出
10
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int max_n = 200000 + 10;
char a[max_n], b[max_n];
int nb[max_n];
void getNext(char* s, int* next) {
    next[0] = -1;
    int k = -1, j = 0, len = strlen(s);
    while (j < len) {
        // calculate next
        if (k == -1 || s[k] == s[j]) {
            j++;
            k++;
            next[j]=k;
        } else
        /*****fill in the codes*************/
        k=next[k];
    }
}
int find(char* str1, char* str2, int* next2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0, j = 0;
    int cnt = 0;
    while (i < len1) {
        if(j==-1||str1[i]==str2[j]){
        	i++;
        	j++;
		}
		else{
			j=next2[j];
		}
        if (j == len2) {
            cnt = (cnt + i - len2) % 10007;
            j = next2[j];
        }
    }
    return cnt;
}
int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin >> a >> b;
    getNext(b, nb);
    cout << find(a, b, nb) << endl;
    return 0;
}
