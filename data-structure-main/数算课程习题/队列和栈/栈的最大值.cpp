/*
描述
给定一个栈a，初始为空。

给定一个操作序列，操作共分三种：

push i将正整数i压入栈

pop将栈顶元素弹出（保证此时栈不空）

queryMax输出此时栈内最大值（若栈内为空，输出0）



输入
第一行一个操作数目n(n<=100000)
以下n行，每行首先是一个字符串s，若字符串为"push"，则在空格后会有一个整数i(i<100000)
输出
对于每个query，输出栈内的最大值
样例输入
7
queryMax
push 1
queryMax
push 2
queryMax
pop
queryMax
样例输出
0
1
2
1
*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    //stl::stack 成员函数 .top()为获取栈顶元素  .pop()为弹出栈顶   .push(i)为将i推入栈
    stack<int>stk;//储存当前栈的情况
    stack<int>stkmax;//储存当前栈内最值

    int n;
    cin>>n;
    string s;

    for (int i=0;i<n;++i){
        cin>>s;
        if (s=="queryMax"){
            if (stkmax.empty())
                cout<<"0"<<endl;
            else 
                cout<<stkmax.top()<<endl;
        }
        else if (s=="pop"){
            int f=stk.top();
            stk.pop();
            if (f==stkmax.top())
                stkmax.pop();
        }
        else {
            int val;
            cin>>val;
            stk.push(val);
            if ((!stkmax.empty()&&val>stkmax.top())||stkmax.empty())
                stkmax.push(val);
        }
    }    
    fclose(stdin);fclose(stdout);
    return 0;
}
