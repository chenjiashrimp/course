import math
prime_sum=2
not_prime=0
num=1
x=int(input('enter there:'))
for number in range(3,x,2):
    for i in range(3,int(math.sqrt(number))+1,2):#md,少加一个1，结果就错了
        if number%i==0:
            not_prime=1
            break
    if not_prime==0:
        prime_sum+=number
        num=num+1
    not_prime=0
print(prime_sum,num)
        
    
