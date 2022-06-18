/*描述
N只小白鼠(1 < N < 100)，每只鼠头上戴着一顶有颜色的帽子。现在称出每只白鼠的重量，要求按照白鼠重量从大到小的顺序输出它们头上帽子的颜色。帽子的颜色用“red”，“blue”等字符串来表示。不同的小白鼠可以戴相同颜色的帽子。白鼠的重量用整数表示。

输入
输入第一行为一个整数N，表示小白鼠的数目。
下面有N行，每行是一只白鼠的信息。第一个为不大于1000的正整数，表示白鼠的重量，；第二个为字符串，表示白鼠的帽子颜色，字符串长度不超过10个字符。

注意：白鼠的重量各不相同。
输出
按照白鼠的重量从大到小的顺序输出白鼠的帽子颜色。
样例输入
3
30 red
50 blue
40 green
样例输出
blue
green
red 
*/
#include <stdio.h>

struct Rat {
    int weight;
    char hat_color[15];
};

struct Rat rat[100];
int n;

int main() {
    int i, j;
    struct Rat tmp;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
       
        scanf("%d %s", &rat[i].weight, &rat[i].hat_color);//使用scanf("%s")可读入字符串
    }


    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            if (rat[i].weight < rat[j].weight) {
                tmp = rat[j];
                rat[j] = rat[i];
                rat[i] = tmp;
            }
        }

    for (i = 0; i < n; i++)
        printf("%s\n", rat[i].hat_color);
}
