####modules 模块
##A module is a .py file containing Python definitions and statements
##使用 模块名 点 函数
#module packages in standard Python library

###module package math
print(math.log(x,2))



#module package calender
import calendar as cal
cal_english = cal.TextCalendar()
print(cal_english.formatmonth(1949, 10))
print(cal.day_name[cal.weekday(2033, 12, 25)])#某天是周几
print(cal.monthcalendar(2021, 12))#二维list 一般5 list 一个list七个int
print(cal.MONDAY)#0

#######thanksgiving day
def find_thanksgiving(year):
 month = cal.monthcalendar(year, 11)
 if month[0][cal.THURSDAY] != 0:
     thanksgiving = month[3][cal.THURSDAY]
 
 else:
     thanksgiving = month[4][cal.THURSDAY]
 return thanksgiving
print('In 2011', 'U.S. Thanksgiving was on November',
 find_thanksgiving(2011))

# Import one module per line.
#Place all imports at the start of a program.
#Import standard modules first, followed by third-party
#modules (e.g., the modules provided through Anaconda), and
#finally application-specific modules.








####module math######
import math
a,b=3,7
a,b=b,a
print(a**b)
print(a/b)#小数
print(a%b)
print(a//b)#取出商，整数
print(6.0//2)#含有一个小数，输出小数
print(math.sqrt(a))
print(abs(-5))
print(3==3.0)#True
print(round(80.12999,2))#四舍五入，保留2个小数
print(round(81.00000,6))#小数点后最多保留一个0
###################位运算符，十进制转为二进制，算完在变为十进制
x,y=10,11
print(x&y)#全是1才是1
print(x|y)#一个1就是1
print(int('1001',2))#转为十进制,数据类型为int
print(x^y)#相异为1
print(~x)#取反运算符-x-1
print(x<<8)#左移，高位丢弃低位补零
print(x>>3)
###################

m,n=20,20
if(m is n):#标识符引用自同一个对象
    print("great")
else:
    print("fuck")
if(m is not n):
    print("great")
else:
    print("fuck")
