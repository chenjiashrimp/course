/*
描述
在c++面向对象的语法中，存在着class的private成员的概念。

对于一个private成员，通常情况下我们要访问/修改它有如下几种办法：

在该类的public成员函数中修改/访问，在外部调用该类的public函数(常规用法)。

声明类的友元类，通过友元类的public成员函数修改/访问，在外部调用友元类的public函数（一定程度上破坏了封装性，正常情况下不推荐）。

通过偏移量，直接算出对应private成员的地址，强制转换为对应类型并修改（强烈不推荐）。

本题要求定义一个类A,包含一个int类型的private成员。初始化该成员值为1，并在外部调用，改变该成员的值。输出该成员修改前后结果。



输入
该private成员要修改成的值
输出
该private成员修改前后值的变化
样例输入
100
样例输出
1
100
*/

#include<bits/stdc++.h>
using namespace std;

class A {
private:
    int value;
    friend class B;
public:
    A() {
        value = 1;
    }
    int getValue() {
        return value;
    }
    void changeValue(int i) {
        value = i;
    }

};
class B {
public:
    int getValue(A& a) {
        return a.value;
    }
    void changeValue(A& a, int i) {
        a.value = i;
    }
};

int main() {
    int i;
    cin >> i;
    A a;
    int x = a.getValue();
    cout << x << endl;
    a.changeValue(i);
     x = a.getValue();
    cout << x << endl;
    return 0;
}
