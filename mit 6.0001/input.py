print(list(map(lambda x:x*x,range(10))))#使用list函数可以转换为列表，输出数组
print(map(lambda x:x*x,range(10))) #返回迭代器
#lambda为匿名函数，没有名字的函数，只能有一个表达式，该表达式子的结果就是返回的值
def square(x):
    return x**2
print(list(map(square, range(5))))
#map函数的功能是根据制定的函数做对应序列的映射，括号里为函数名与序列（【】必须有）
print(list(map(lambda x,y:x*y,[1,2],[4,6])))#也可以有多个变量，多个序列
#########################
f=open('D:\chen.txt','r')#后面为读入，'r'（读入）'w'（写入）不输入默认为读入，文件名称有中文读不进去
for line in f:
    print(line[0])#输出文件每一行的第一个数字，删去0就是输出整个矩阵
f.close()
print('\n')
#####
with open("D:\chen.txt", "r") as txt:
    for line in txt:
        print(line)#输出整个矩阵，优势在于文件会自己关闭
#############
for line in open('D:\chen.txt','r'):
    print(line)#由于文件自动关闭，不再需要txt

    
    
 ###file handles
name_handle = open('kids', 'w')#create a file named kids
for i in range(2):
 name = input('Enter name: ')
 name_handle.write(name + '\n')#换行
name_handle.close()#不关闭可能会有某些东西没有保存
with open('kids') as txt:#确保是否关闭
    for line in txt:
        print(line[:-1])#输出无空行

##
name_handle = open('kids', 'a')#'w'之前内容会丢掉 append
######
x=[1,2,3]
print(x[-1],x[:-1],x[::-1])




#1
