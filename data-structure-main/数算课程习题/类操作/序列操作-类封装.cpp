/*
总时间限制: 1000ms 内存限制: 65535kB
描述
有一个从1到n的序列（n<=1000）。对序列进行m次操作（m<=2000）。

每次有两种操作：

移动：将值为a和值为b之间的数（包括a和b）移到值为k的后面。比如，对于序列1 2 3 4 5，将2到3之间的数字移动到数字4的后面，序列将变为1 4 2 3 5。

反转：将值为a和值为b之间数反转。比如：对于序列1 4 2 3 5，反转4 3，变为1 3 2 4 5。




输入
第一行输入一个整数t，表示测试数据的组数。
对于每组测试数据，第一行输入两个整数n,m；
每次操作首先输入一个字符type。
当type=”m”，移动操作，接着输入三个整数a，b，k，保证b的下标大于等于a的下标，，k不在a、b之间。
当type=”r”，反转操作，接着输入两个整数a，b，保证b的下标大于等于a的下标。
输出
对于每组测试数据，输出n个整数，表示经过m次操作后的序列。注意最后一个数字后面不要输出空格。
样例输入
1
5 5
m 2 3 4
r 4 2
r 1 4
r 2 3
m 3 2 5
样例输出
4 5 3 1 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

class MyArray
{
public:
    MyArray()
    {
        arr = NULL;
        arr_size = -1;
    }
    ~MyArray()
    {
        if (arr != NULL)
            free(arr); // if you use "malloc" to allocate memory
                       // or you can use c++ style: "delete" corresponding to "new"
        arr_size = -1;
    }
    void new_arr(int n);
    void segment_move(int a, int b, int k);
    void segment_reverse(int a, int b);
    void print();

private:
    // private variable only used by public function
    // means, a.arr is error, a is MyArr
    int *arr;
    int arr_size;
};

void MyArray::new_arr(int n)
{
    if (arr != NULL)
        free(arr);
    arr_size = n;
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i ++)
        arr[i] = i + 1;
}

void MyArray::segment_move(int a, int b, int k)
{
    int start, end, pos;
    for (int i = 0; i < arr_size; i ++)
    {
        if (arr[i] == a) start = i;
        if (arr[i] == b) end   = i;
        if (arr[i] == k) pos   = i;
    }
    int *tmp_arr = (int *)malloc(arr_size * sizeof(int));
    int j = 0;
    for (int i = 0; i < start; i ++, j ++)
        tmp_arr[j] = arr[i];
    for (int i = end + 1; i <= pos; i ++, j ++)
        tmp_arr[j] = arr[i];
    for (int i = start; i <= end; i ++, j ++)
        tmp_arr[j] = arr[i];
    for (int i = pos + 1; i < arr_size; i ++, j ++)
        tmp_arr[j] = arr[i];

    free(arr);
    arr = tmp_arr;
}

void MyArray::segment_reverse(int a, int b)
{
    int start, end;
    for (int i = 0; i < arr_size; i ++)
    {
        if (arr[i] == a) start = i;
        if (arr[i] == b) end   = i;
    }

    int temp;
    for (int i = 0; i < (end - start + 1) / 2; i++ )
    {
        temp = arr[start + i];
        arr[start + i] = arr[end - i];
        arr[end - i] = temp;
    }
}

void MyArray::print()
{
    printf("%d", arr[0]);
    for (int i = 1; i < arr_size; i ++)
        printf(" %d", arr[i]);
    printf("\n");
}

int main()
{

    int t;
    int n, m;
    int a, b, k;
    scanf("%d", &t);
    while (t --)
    {
        MyArray m_arr;
        scanf("%d %d", &n, &m);
        m_arr.new_arr(n);
        while ( m -- )
        {
            char type[10];
            scanf("%s", type);
            if (type[0] == 'm')
            {
                scanf("%d %d %d", &a, &b, &k);
                m_arr.segment_move(a, b, k);
            } else {
                scanf("%d %d", &a, &b);
                m_arr.segment_reverse(a, b);
            }
        }
        m_arr.print();
    }
    return 0;
}
