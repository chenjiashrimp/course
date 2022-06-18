hi="hello there"#单引号双引号都可以
#name=input("enter your name: ")#input的数据类型全为str
#greeting= hi+" "+name
#silly=hi+(" "+name)*3#字符串有乘法加法，没有减法除法


#print("my fav num is",x,".","x=",x)#区别在于会自动添加空格，看个人需求
#print("my fav num is"+x_str+"."+"x="+x_str)#，和+可以自由组合，注意数据类型

##############
x,y,z=1,2,0
#print(not (x==1),(x==1)or(y!=2),(x!=1)and(y==2))
#print(not x,not z)#配合bool值使用，非0即1
#print("ab">"ba")#比较大小为字母顺序
########################if elif else如果有多个条件正确，那么也只会运行第一个正确的代码块
########################
n=0
while n<5:
    print(n)#会自动换行 如果加上\n就是再空一行了
    n=n+1
######ctrl+c可以停止程序

mynum=0
for i in range(3,9,2):
    mynum+=i
    print(i,mynum)
###break可以提前中断循环while或者for，多层循环嵌套要注意每个循环的代码块是啥，break控制的是
###哪部分代码块
###while常用于循环次数比较不清楚，for常用于比较清楚
#1
