def compute_gcd(x, y):

   while(y):
       x, y = y, x % y
   return x

def compute_lcm(x, y):
   if abs(x-y) == x or abs(x-y) == y:
       return x if x > y else y 
   lcm = (x*y)//compute_gcd(x,y)
   return lcm

from math import ceil

t = int(input())
cases = list()
for _ in range(t):
    cases.append(int(input()))



def do_function(num):
    min = 100000000
    x, y  = 0 , 0
    for i in range(1,int((ceil((num-1)/2)+1))):
        j = num - i
        num = compute_lcm(i,j)
        if num < min:
            min , x, y = num, i, j
    print(x,y)


for i in cases:
    do_function(i)