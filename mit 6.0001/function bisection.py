##########################原始方法
x=float(input('enter there:'))
ans,num_guess=0.0,0
epsilon=0.01#what is close enough
step=epsilon**2#step is too large, it may skip the suitable answer
while abs(ans**2-x)>=epsilon and ans**2<=x:
    ans+=step
    num_guess+=1
if abs(ans**2-x)>=epsilon:#can not find an ans colse enough
    print('fail',num_guess)
else:
    print(ans,'**2=',x,num_guess)

    
 x=0.0
for i in range(10):
    x+=0.1
print(x)#in most situation not important. when == important 
#use abs(x-y)<0.000000001 rather than x==y
print(0.1*10.0)
print(0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1)
print(round(1.23456789,3))



###############newton
#x=x-function/function的导数 画图可知越来越逼近零点，用于求零点的近似值
epsilon=0.01
k=float(input("enter there:"))
guess=k/2
num_guess=0
while abs(guess**2-k)>=epsilon:
    num_guess+=1
    print(num_guess,'guess=',guess)
    guess=guess-((guess**2-k)/(2*guess))#精髓，一个简单的二次方程，逼近的零点几位平方根
print(num_guess,guess,'**2=',k)
################function and scoping
def max_val(x,y):#命名，全用小写字母加下划线
    if x>y:
        return x#return only can be used in body of function,执行到遇到return为止
#如果没有return，则返回none
    else:
        return y
x,y=2,4
print(max_val(x,y))
print(max_val(3,4)*max_val(5,6))
#######################



def find_root_bound(x,power):#大函数可以嵌套小函数，函数太长把小函数写在外面
    low=min(-1,x)
    high=max(1,x)
    return low,high
def bisection_solve(x,power,epsilon,low,high):
    ans=(low+high)/2
    while abs(ans**power-x)>epsilon:
        if ans**power>x:
            high=ans
        else:
            low=ans
        ans=(high+low)/2
    return ans
def find_root(x,power,epsilon):
    if power%2==0 and x<0:
        return None
    low,high=find_root_bound(x,power)
    return bisection_solve(x, power, epsilon, low, high)
x,power,epsilon=input('enter there').split()
x=float(x)
power=float(power)
epsilon=float(epsilon)
print(find_root(x,power,epsilon))
##函数名也可以作为函数的参量 
def bisection_solve1(x,eval_ans,epsilon,low,high):#eval_ans为函数名，可以写任意函数然后套用
    ans=(low+high)/2
    while abs(eval_ans(ans)-x)>epsilon:
        if eval_ans(ans)>x:
            high=ans
        else:
            low=ans
        ans=(high+low)/2
    return ans
def square(x,power):
    return x**power
print(bisection_solve1(99,lambda ans:ans**2, 0.01, 2, 99))#利用lambda，简单的函数不用另外写
###################
c=lambda x,y: x/y if y!=0 else None# conditional expressions
print(c(1,2))
print((lambda x,y: x/y if y!=0 else None)(1,2))#吧数值传递给lambda的两种方式
##########
def create_eval_ans():
    power=int(input('enter there:'))
    return lambda ans:ans**power
eval_ans=create_eval_ans()
###################oversimplify
def find(s,sub):
    if sub not in s:
        return None
    reverse_s=s[::-1]
    reverse_sub=sub[::-1]
    return len(s)-reverse_s.find(reverse_sub)-len(sub)
s,sub=input('enter there:').split()
print(find(s,sub))
#s.find(sub) 找出第一次出现sub的位置，若没有返回-1


#1       
