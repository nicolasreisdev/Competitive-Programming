# Enter your code here. Read input from STDIN. Print output to STDOUT


import itertools
from itertools import product
a = input().split()
b = input().split()

ans = list(itertools.product(a, b))
for i, value in enumerate(ans):
    numPrint = "("
    for num in value:
        numPrint = numPrint + num + ", " 
    numPrint = numPrint[0: len(numPrint)-2]
    numPrint = numPrint + ")"
    print(numPrint, end=' ')
print()
