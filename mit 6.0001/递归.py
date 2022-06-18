#####斐波那契
def fib(n):
    if n==1 or n==0:
        return 1
    else:
        return fib(n-1)+fib(n-2)
def test_fib(n):
    for i in range(n+1):
        print(i,fib(i))

n=int(input())
fib(n)
test_fib(n)


###global variables全局变量 影响可读性
def fib(x):
    global num_fib_calls
    num_fib_calls+=1
    if x==1 or x==0:
        return 1
    else:
        return fib(x-1)+fib(x-2)
def test_fib(x):
    for i in range(x+1):
        global num_fib_calls
        num_fib_calls=0
        print(fib(i),num_fib_calls)
n=int(input())
test_fib(n)
