def is_in(str1,str2):
    if str1 in str2:
        return True
    else:
        return False
def test_is_in(str1_vals,str2_vals):##测试函数，把被测试的函数的结果调用
#然后检测该结果满不满足被测试函数的需求
    for str1 in str1_vals:
        for str2 in str2_vals:
            result=is_in(str1,str2)
            if result==(str1 in str2):
                val='Great'
            else:
                val='Bad'
            print(f'str1={str1},str2={str2}:{val}')
str1_vals=('abc','114514','!@#$@')#元组，与数组的区别就是元素值没办法改
str2_vals=('abcdefs','114516','!@#$@^^^^')
test_is_in(str1_vals,str2_vals)
#m=input('enter str1:')
#n=input('enter str2:')
#print(is_in(m,n))
#print(f'{1+1}')#f格式化字符串，表达式+花括号 


###################
# def f(x,y,z)
# def f(x,y,z=1) 默认参数值，调用f可不用赋值z，若赋值则z未必为1
#调用 f(x=,y=,z=) f(x=,,)
#错误 f(,x=)
################
def mean(*args):####*调用一系列数
    tot=0
    for a in args:
        tot+=a
    return tot/len(args)
args=[1,2,3,4]
args=(1,2,3,4,5)
args='12234'
print(mean(*args))

################
def f(x):
    def g():
        x='abc'
        print('x=',x)
    def h():
        z=x
        print('z=',z)
    h()
    g()
    print('x=',x)
    return g
x=3
z=f(x)#这里是body of function外的x
print('x=',x)
print('z=',z)
def g1():
    x=1
    z=x
    print('x=',x)
    print('z=',z)
x=3
g1()
#1
