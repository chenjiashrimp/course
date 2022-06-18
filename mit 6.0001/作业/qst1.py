annual_salary,portion_saved,total_cost=input('enter there:').split()
annual_salary=float(annual_salary)
portion_saved=float(portion_saved)
total_cost=float(total_cost)
num_month=0
portion_down_payment,current_savings,r=0.25,0,0.04
while current_savings<total_cost*portion_down_payment:
    num_month+=1
    current_savings+=current_savings*r/12
    current_savings+=(annual_salary/12)*portion_saved
print(f'Numbers of months:{num_month}')
###################question B#############
annual_salary,portion_saved,total_cost,semi_annual_raise=input('enter there:').split()
annual_salary=float(annual_salary)
portion_saved=float(portion_saved)
total_cost=float(total_cost)
semi_annual_raise=float(semi_annual_raise)
num_month=0
portion_down_payment,current_savings,r=0.25,0,0.04
while current_savings<=total_cost*portion_down_payment:
    num_month+=1
    current_savings+=current_savings*r/12
    current_savings+=(annual_salary/12)*portion_saved
    if num_month%6==0:
        annual_salary+=annual_salary*semi_annual_raise
print(f'Numbers of months:{num_month}')
###################question C#############
annual_salary,total_cost,semi_annual_raise=input('enter there:').split()
annual_salary=float(annual_salary)
total_cost=float(total_cost)
semi_annual_raise=float(semi_annual_raise)
difference=10000
low,high=0,10000
num_bisection_search=0
portion_down_payment,current_savings,r=0.25,0,0.04
portion_saved=(0+10000)/20000
while difference>=1:
    portion_saved=(high+low)/20000
    num_bisection_search+=1
    current_savings=0
    annual_salary=150000
    for num_month in range(1,37):
        current_savings+=current_savings*r/12
        current_savings+=(annual_salary/12)*portion_saved
        if num_month%6==0:
            annual_salary+=annual_salary*semi_annual_raise
    if current_savings>total_cost*portion_down_payment:
        high=portion_saved*10000
    else:
        low=portion_saved*10000
    difference=abs(portion_saved*10000-(high+low)/2)
    print(difference,high,low,portion_saved,current_savings)
print(num_bisection_search,portion_saved)
