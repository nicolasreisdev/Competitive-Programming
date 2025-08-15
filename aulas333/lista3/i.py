import math
#def mdc(x, y):
#   if y == 0:
#        return x
#    else:
#        return mdc(y, x % y)


n = int(input())
for i in range (0,n): 
    x,nda, y = input().split()
    x = int(x)  
    y = int(y)
    k = math.gcd(x,y) 
    x = x//k
    y = y//k
    print(f"{x} / {y}")
    