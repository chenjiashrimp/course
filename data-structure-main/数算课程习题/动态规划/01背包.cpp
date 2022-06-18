/*
描述
且说上一周的故事里，小Hi和小Ho费劲心思终于拿到了茫茫多的奖券！而现在，终于到了小Ho领取奖励的时刻了！

小Ho现在手上有M张奖券，而奖品区有N件奖品，分别标号为1到N，其中第i件奖品需要need(i)张奖券进行兑换，同时也只能兑换一次，为了使得辛苦得到的奖券不白白浪费，小Ho给每件奖品都评了分，其中第i件奖品的评分值为value(i),表示他对这件奖品的喜好值。现在他想知道，凭借他手上的这些奖券，可以换到哪些奖品，使得这些奖品的喜好值之和能够最大。

输入
第一行为两个正整数N和M,表示奖品的个数，以及小Ho手中的奖券数。

接下来的n行描述每一行描述一个奖品，其中第i行为两个整数need(i)和value(i)，意义如前文所述。

测试数据保证

对于100%的数据，N的值不超过500，M的值不超过10^5

对于100%的数据，need(i)不超过2*10^5, value(i)不超过10^3
输出
对于每组测试数据，输出一个整数Ans，表示小Ho可以获得的总喜好值。
样例输入
5 1000
144 990
487 436
210 673
567 58
1056 897
样例输出
2099
*/

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct Data {
    int need, value;
};
const int max_n = 501;
const int max_m = 2 * 1e5 + 10;
Data a[max_n];
int f[max_m];
int n, m;

int main() {
    cin.sync_with_stdio(false);  //speed up reading
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i].need >> a[i].value;
    for (int i = 0; i < n; ++i) {
        for (int j = m;j >= a[i].need;j--)
            if (f[j] < f[j - a[i].need] + a[i].value)
                f[j] = f[j - a[i].need] + a[i].value;
    }
    cout << f[m] << endl;
    return 0;
}
