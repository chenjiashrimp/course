/*描述
在一个有180人的大班级中，存在两个人生日相同的概率非常大，现给出每个学生的学号，出生月日。试找出所有生日相同的学生。
输入
第一行为整数n，表示有n个学生，n<100。
此后每行包含一个字符串和两个整数，分别表示学生的学号（字符串长度小于10）和出生月(1<=m<=12)日(1<=d<=31)。
学号、月、日之间用一个空格分隔。
输出
对每组生日相同的学生，输出一行，
其中前两个数字表示月和日，后面跟着所有在当天出生的学生的学号，数字、学号之间都用一个空格分隔。
对所有的输出，要求按日期从前到后的顺序输出。
对生日相同的学号，按输入的顺序输出。
样例输入
5
00508192 3 2
00508153 4 5
00508172 3 2
00508023 4 5
00509122 4 5
*/

#include <stdio.h>

struct People {
    int month, day;
    char id[30];
};

struct People people[200];
int n;


int count[13][32];

int main() {
    int i, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s%d%d", people[i].id, &people[i].month, &people[i].day);
        count[people[i].month][people[i].day]++;
    }


    for (i = 1; i <= 12; i++)
        for (j = 1; j <= 31; j++)

            if (count[i][j] >= 2) {
                printf("%d %d", i, j);
                for (k = 0; k < n; k++)
                {
                    if (people[k].month == i && people[k].day == j)
                        printf(" %s", people[k].id);
                }
                printf("\n");
            }
}
