/*
描述
给长度为n的序列（n<=1000），这里有三种不同类型的序列，全是整数，全是浮点数，全是字符串，现在序列进行m次操作（m<=2000）。

每次有两种操作：

移动：将区间[i, j]之间元素移动到k的后面。比如，对于序列1 2 3 4 5，将区间[0, 2]之间的元素移动到下标3的后面，序列将变为4 1 2 3 5。

反转：将区间[i, j ]之间的元素反转。比如：对于序列1 2 3 4 5，反转区间[1, 3]，变为1 4 3 2 5。

注意：下标从0开始。



输入
第一行输入一个整数t，表示测试数据的组数。
对于每组测试数据，第一行输入有三列type, n , m，分别表示数据类型（interger, double, string），共n个数，m次操作。
每次操作首先输入一个字符oprator。
当oprator=”m”，移动操作，接着输入三个整数i，j，k，保证i小于等于j，k不在区间[i,j]内。
当oprator=”r”，反转操作，接着输入两个整数i，j，保证i小于等于j。
输出
对于每组测试数据，输出序列中的经过m次操作后的的n个元素，元素之间用空格隔开，注意最后一个元素后面不要输出空格,对于浮点数，保留2位小数。
样例输入
3
interger 5 5
626 323 537 538 118 
r 1 3
m 1 3 4
r 0 2
m 0 3 4
r 1 3
double 5 5
1.96 2.22 1.29 1.61 5.35 
r 1 2
r 1 2
m 1 2 3
r 0 3
m 0 3 4
string 5 5
qghumeay nlfdxf rcv cxggb kfnqdux 
r 1 3
m 0 3 4
m 0 3 4
m 0 3 4
m 1 2 3
样例输出
323 626 118 538 537
5.35 1.29 2.22 1.61 1.96
rcv qghumeay nlfdxf kfnqdux cxggb
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

template <typename T>
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
            delete[] arr;
        arr_size = -1;
    }

    // you can use this like nomal array operator []
    // eg: MyArray<int> m; m[i] = 3;
    T & operator [](int pos) { return arr[pos]; }

    int get_size() const { return arr_size; }

    // allocate a array, size is n
    void new_arr(int n);
    // move the elements bettween  start(i) and end(j) to the behind of pos(k)
    void segment_move(int start, int end, int pos);
    // reverse the elements bettween start(i) and end(j)
    void segment_reverse(int start, int end);
    // print all elements
    void print();

private:
    // private variable only used by public function
    // means, a.arr is illegal operation, a is MyArray
    T *arr;
    int arr_size;
};


template <typename T>
void MyArray<T>::new_arr(int n)
{
    if (arr != NULL)
        delete arr;
    arr_size = n;
    arr = new T[n];
}

template <typename T>
void MyArray<T>::segment_move(int start, int end, int pos)
{
    T *tmp_arr = new T[arr_size];
    int j = 0;
    for (int i = 0; i < start; i ++, j ++)
        tmp_arr[j] = arr[i];
    for (int i = end + 1; i <= pos; i ++, j ++)
        tmp_arr[j] = arr[i];
    for (int i = start; i <= end; i ++, j ++)
        tmp_arr[j] = arr[i];
    for (int i = pos + 1; i < arr_size; i ++, j ++)
        tmp_arr[j] = arr[i];

    delete []arr;
    arr = tmp_arr;
}

template <typename T>
void MyArray<T>::segment_reverse(int start, int end)
{
    T temp;
    for (int i = 0; i < (end - start + 1) / 2; i++ )
    {
        temp = arr[start + i];
        arr[start + i] = arr[end - i];
        arr[end - i] = temp;
    }
}

template <typename T>
void process(MyArray<T> &m_arr, // 引用类型，不是取地址运算
             int m)
{
    int i, j, k;
    char str[10];
    while ( m -- )
    {
        scanf("%s", str);
        if (str[0] == 'm')
        {
            scanf("%d %d %d", &i, &j, &k);
            m_arr.segment_move(i, j, k);
        }
        else {
            scanf("%d %d", &i, &j);
            m_arr.segment_reverse(i, j);
        }
    }
    m_arr.print();
}

template <typename T>
void MyArray<T>::print( )
{
    cout  << setprecision(2) <<  setiosflags(ios::fixed) << arr[0];
    for (int i = 1; i < arr_size; i ++)
        cout << " "  << setprecision(2) <<  setiosflags(ios::fixed) << arr[i];
    cout << endl;
}

int main()
{
    int t;
    int n, m;
    int i, j, k;
    char type[10];
    scanf("%d", &t);
    while (t --)
    {
        scanf("%s %d %d", type, &n, &m);
        // interger
        if (0 == strcmp(type, "interger"))
        {
            MyArray<int> m_arr;
            m_arr.new_arr( n );
            for (int i = 0; i < n; i ++)
                cin >> m_arr[i];
            process(m_arr, m);
        }
        // double
        else if (0 == strcmp(type, "double"))
        {
           // cout << "double"  << endl;

            MyArray<double> m_arr;
            m_arr.new_arr( n );
            for (int i = 0; i < n; i ++)
                cin >> m_arr[i];
            process(m_arr, m);
        }
        // string
        else if (0 == strcmp(type, "string"))
        {
            MyArray<string> m_arr;
            m_arr.new_arr( n );
            for (int i = 0; i < n; i ++)
                cin >> m_arr[i];
            process(m_arr, m);
        }
    }
    return 0;
}
