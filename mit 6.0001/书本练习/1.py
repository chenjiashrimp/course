j=0
while j<1:
    x=int(input('enter there:'))
    root,pwr=0,0
    guess=0
    for root in range(1,x):
        if root**2>x:
            break
        if root**5<x:
            continue
        for pwr in range(1,6):
            if root**pwr>x:
                break
            if root**pwr==x:
                guess=1
                break
        if guess==1:
            break
    if guess==1:
        print(root,'**',pwr,'=',x)
    else:
        print('no solution')
        
