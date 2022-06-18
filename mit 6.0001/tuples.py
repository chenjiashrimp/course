#####tuples(元组)
t1=(1,)
t3=(1)
t2=(1,3,'two')
print(type(t3))
print(t2*3)
print((t1+t2)[3])
print((t1+t2)[0:3])#start stop-1
t4=(t2,114514)
x,y,z='abc'
x,y,z=(1,2,3)


#######function about string
str='abcbdbeb'
print(str.split('b'))#divide from 'b'                    '
print(str.rstrip())#去掉最后面的空格
print(str.lower())#大写变小写
print(str.replace('b','a'))####replace old with new
print(str.rfind('ab'))#reverse
print(str.count('a'))




##############list###########
####diffenences between 'is' and '=='
x1=[1,2]
x2=[3,4]
y1=[x1,x2]
y2=[[1,2],[3,4]]
print(y1==y2)
print(y1 is y2)##值和地址都要一样
print(id(y1)==id(y2))
x1.append(5)
print(y1==y2)
####

L=[1,2,3]
print(L[-1])
L.append(L)##变成L的一个元素，数组也是
L.extend(L)##后面只能跟数组
print(L is L[-1])##true ????????为啥
#浅拷贝和深拷贝
#浅拷贝只是拷贝地址，深拷贝直接吧内容也复制过来，相当于和原来没关系
x1=copy.deepcopy(x)
x1=[x,x]
x1[0].append(4)#x==x1[0],指向的内存一致
##list comprehension
##[expr for elem in iterable if test]test 可有可无
print([(x,y) for x in range(6) if x%2==0 for y in range(6) if y%3==0])
#multiple for 顺序
L1=[114514,1,2]
L2=[1,2,3]
for i in map(min,L1,L2):
    print(i)
#map is a higher order(高阶)function and can be used in for loop
#the first argument can be used in n numbers of List



########range
print(range(10)[2:8][3])#第几个
print(range(2,8,2)==range(2,7,2))
print(sum((1,2,1.0)))#注意括号
#range tuples list

#####sets a type of collection
x={'1','a','123'}#unordered for loop error index error
x.add('b')#add single
x.update(['c','4'])#add multiple
print(x.remove('e'))#discard if not in the set not error remove will error



#1
