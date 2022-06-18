/*描述
对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。在字符串中，单词之间通过空白符分隔，空白符包括：空格(' ')、制表符('\t')、回车符('\r')、换行符('\n')。
输入
输入一行：待处理的字符串（长度小于80）。
输出
输出一行：转换后的字符串。
样例输入
if so, you already have a google account. you can sign in on the right.
样例输出
If So, You Already Have A Google Account. You Can Sign In On The Right.
*/
#include <stdio.h>

char c;
int n;

int main() {
    int i;
    int is_first_letter = 1; // 表示当前是否是首字符

    // 逐个读入字符
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            // 如果当前是首字母，且是小写字母
            // 则转换为大写字母

            if (is_first_letter && c >= 'a' && c <= 'z')
                c = c + 'A' - 'a';

            is_first_letter = 0;
        }
        else
            is_first_letter = 1;
        putchar(c);
    }
}
