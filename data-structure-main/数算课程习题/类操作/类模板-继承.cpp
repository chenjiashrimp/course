/*
描述
使用继承机制，分别设计实现抽象基类图形类，派生类圆形类、正方形类、长方形类，并实现方法获取图形面积、属性赋值。

填空完成

输入
三行，均为整数，分别为圆半径、正方形边长、长方形长宽
输出
三行，分别是他们的面积（pi取3.14）
样例输入
3
4
6 5
样例输出
28.26
16
30
*/

#include <bits/stdc++.h>
#define pi 3.14
using namespace std;
class Shape {
   public:
    virtual double area() = 0;
    virtual int setvalue(vector<int>& params) = 0;
};
class Circle : public Shape {
    int r;

   public:
    int setvalue(vector<int>& params) {
        r = params[0];
        return 0;
    }
    double area() { return r * r * pi; }
};

class Square : public Shape {
    int r;

   public:
    int setvalue(vector<int>& params) {
        r = params[0];
        return 0;
    }
    double area() { return r * r; }
};

class Rectangle : public Shape {
    int a, b;
public:
    int setvalue(vector<int>& params) {
        a = params[0];
        b = params[1];
        return 0;
    }
    double area() { return a * b; }
};

int main() {
    Shape *a, *b, *c;
    vector<int> params;
    params.resize(2);
    a = new Circle();
    cin >> params[0];
    a->setvalue(params);
    b = new Square();
    cin >> params[0];
    b->setvalue(params);

    c = new Rectangle();
    cin >> params[0] >> params[1];
    c->setvalue(params);
    cout << a->area() << endl << b->area() << endl << c->area() << endl;
    return 0;
}
